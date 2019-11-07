// Snake
// Ported from: https://www.creoqode.com/video-games-pyxa
// Modifications by Andrew Meyer
//
// CONTROLS:
// - D-pad: Control snake

#include <DotMG.h>

// Screen size in pixels

#define SW         160 // Screen width
#define SH         128 // Screen height

// Define actions

#define BUTTON_NONE   0
#define BUTTON_DOWN   1
#define BUTTON_RIGHT  2
#define BUTTON_UP     3
#define BUTTON_LEFT   4

uint16_t color = ST7735_GREEN;
uint8_t buttonPressed, currentDirection;
boolean collision, apple;
boolean displayEnd=false ;
int head, timer, snakeSize, snakeX, snakeY,
    appleX, appleY, difficulty, score, x[300], y[300];
int colorCode =1;
uint16_t COLOR_MAP[7] = {ST7735_RED,ST7735_GREEN,ST7735_CYAN,ST7735_MAGENTA,ST7735_YELLOW,ST7735_BLUE,ST7735_WHITE};

void setup() {
  dmg.init();
  start();
}

void updateDifficulty(){
  if (difficulty>61){
    difficulty -=3;}
  else if (difficulty>41){
    difficulty -=2;
  }
  else if (difficulty>21){
    difficulty --;
  }
}

void loop() {
  if (!collision){
    appleLogic();
    controlApple();
    updateSnake(buttonPressed);

    if (timer >= snakeSize - 1)
      removeLastFromTail();
    else
      timer++;
  } else {
    if (displayEnd == true){
      over();
      start();
    }
  }
  delay(difficulty);
}

void drawPlayfield(){
  dmg.tft->drawRect(0, 10, 158, 118, ST7735_YELLOW);
  dmg.tft->setTextSize(1);
  dmg.tft->setTextColor(ST7735_WHITE);
  dmg.tft->setCursor(3, 0);
  dmg.tft->print("Score:");
}

void updateScore(int score){
  dmg.tft->fillRect(45, 0, SW - 75, 9, ST7735_BLACK);
  dmg.tft->setTextSize(1);
  dmg.tft->setCursor(45, 0);
  dmg.tft->setTextColor(ST7735_WHITE);
  dmg.tft->print(score);
}

void controller() {
  if (dmg.isRightButtonPressed()) {
  buttonPressed = BUTTON_RIGHT;
  }
  if (dmg.isLeftButtonPressed()) {
  buttonPressed = BUTTON_LEFT;
  }
  if (dmg.isDownButtonPressed()) {
  buttonPressed = BUTTON_DOWN;
  }
  if (dmg.isUpButtonPressed()) {
  buttonPressed = BUTTON_UP;
  }
}

void updateSnake(uint8_t buttonPressed){
  controller();
  if (buttonPressed == BUTTON_UP){
    if(currentDirection != BUTTON_DOWN){

      snakeY -= 5;
      currentDirection = BUTTON_UP;
    } else
      snakeY += 5;
  }
  if (buttonPressed == BUTTON_DOWN){
    if(currentDirection != BUTTON_UP){
      snakeY += 5;
      currentDirection = BUTTON_DOWN;
    } else
      snakeY -= 5;
  }
  if (buttonPressed == BUTTON_LEFT){
    if(currentDirection != BUTTON_RIGHT){
      snakeX -= 5;
      currentDirection = BUTTON_LEFT;
    } else
      snakeX += 5;
  }
  if (buttonPressed == BUTTON_RIGHT){
    if(currentDirection != BUTTON_LEFT){
      snakeX += 5;
      currentDirection = BUTTON_RIGHT;
    } else
      snakeX -= 5;
  }

  if (snakeY < 13)
    snakeY = 123;

  if (snakeY > 124)
    snakeY = 13;

  if (snakeX < 3)
    snakeX = 153;

  if (snakeX > 154)
    snakeX = 3;

  drawSnakeAll(snakeX, snakeY, ST7735_GREEN);

  x[head] = snakeX;
  y[head] = snakeY;
  collisionCheck();
  head++;
  if (head >= 300){
    removeLastFromTail();
    resetArray();
    head = snakeSize + 1;
  }
}

void resetArray(){
  for(int j = 1; j < snakeSize; j++){
    x[snakeSize - j] = x[head - j];
    x[head - j] = 0;
    y[snakeSize - j] = y[head - j];
    y[head - j] = 0;
  }
  x[0] = 0;
  y[0] = 0;
}

void removeLastFromTail(){
  drawSnake(x[head - snakeSize], y[head - snakeSize], ST7735_BLACK);
  x[head - snakeSize] = 0;
  y[head - snakeSize] = 0;
}

void collisionCheck(){
  for (int z = 0; z < head; z++) {
    if ((x[head] == x[z]) && (y[head] == y[z])) {
      color = ST7735_RED;
      collision = true;
      drawSnake(snakeX, snakeY, ST7735_RED);
      displayEnd = true;
    }
  }
}

void appleLogic(){
  if (!apple){
    int tempx = appleX;
    int tempy = appleY;

    appleX = random(0, 155);
    appleY = random(10, 121);

    if (appleX % 5 == 1) appleX--;
    else if (appleX % 5 == 2) appleX-=2;
    else if (appleX % 5 == 3) appleX-=3;
    else if (appleX % 5 == 4) appleX++;

    if (appleY % 5 == 1) appleY--;
    else if (appleY % 5 == 2) appleY-=2;
    else if (appleY % 5 == 3) appleY-=3;
    else if (appleY % 5 == 4) appleY++;

    appleX +=3;
    appleY +=3;

    if((tempx==appleX) && (tempy==appleY)){
      appleX=48;
      appleY=63;
    }
    colorCode = (colorCode+2)% 7;
    drawApple(appleX, appleY, COLOR_MAP[colorCode]);
    apple = true;
  }
}

void controlApple(){
  if ((x[head - 1] == appleX) || (x[head - 1] == appleX+1)|| (x[head - 1] == appleX-1) ){
    if ((y[head - 1] == appleY) || (y[head - 1] == appleY+1)|| (y[head - 1] == appleY-1)){
      apple = false;
      snakeSize += 2;
      score += 10;
      updateScore(score);
      updateDifficulty();
      dmg.playTone(220, 30);
      delay(30);
      dmg.playTone(440, 30);
    }
  }
  else{
    drawApple(appleX, appleY, COLOR_MAP[colorCode]);
  }
}

void drawSnakeAll(int snakeX, int snakeY, uint16_t color){
  if(currentDirection == BUTTON_RIGHT){
    drawSnake(snakeX, snakeY, color);
    dmg.tft->drawPixel(snakeX + 2, snakeY - 2, ST7735_BLACK);
    dmg.tft->drawPixel(snakeX + 2, snakeY  +2, ST7735_BLACK);
  }
  if(currentDirection == BUTTON_UP){
    drawSnake(snakeX, snakeY, color);
    dmg.tft->drawPixel(snakeX + 2, snakeY - 2, ST7735_BLACK);
    dmg.tft->drawPixel(snakeX - 2, snakeY  -2, ST7735_BLACK);
  }
  if(currentDirection == BUTTON_DOWN){
    drawSnake(snakeX, snakeY, color);
    dmg.tft->drawPixel(snakeX - 2, snakeY + 2, ST7735_BLACK);
    dmg.tft->drawPixel(snakeX + 2, snakeY  +2, ST7735_BLACK);
  }
  if(currentDirection == BUTTON_LEFT){
    drawSnake(snakeX, snakeY, color);
    dmg.tft->drawPixel(snakeX - 2, snakeY - 2, ST7735_BLACK);
    dmg.tft->drawPixel(snakeX - 2, snakeY  +2, ST7735_BLACK);
  }
}

void drawSnake(int snakeX, int snakeY, uint16_t color){
  dmg.tft->drawPixel(snakeX - 2, snakeY - 2, color);
  dmg.tft->drawPixel(snakeX - 2, snakeY - 1, color);
  dmg.tft->drawPixel(snakeX - 2, snakeY , color);
  dmg.tft->drawPixel(snakeX - 2, snakeY + 1, color);
  dmg.tft->drawPixel(snakeX - 2, snakeY + 2, color);

  dmg.tft->drawPixel(snakeX - 1, snakeY + 1, color);
  dmg.tft->drawPixel(snakeX - 1, snakeY - 1, color);
  dmg.tft->drawPixel(snakeX - 1, snakeY, color);
  dmg.tft->drawPixel(snakeX - 1, snakeY - 2, color);
  dmg.tft->drawPixel(snakeX - 1, snakeY + 2, color);

  dmg.tft->drawPixel(snakeX , snakeY - 2, color);
  dmg.tft->drawPixel(snakeX , snakeY + 2, color);
  dmg.tft->drawPixel(snakeX, snakeY - 1, color);
  dmg.tft->drawPixel(snakeX, snakeY, color);
  dmg.tft->drawPixel(snakeX, snakeY + 1, color);

  dmg.tft->drawPixel(snakeX + 1, snakeY + 1, color);
  dmg.tft->drawPixel(snakeX + 1, snakeY, color);
  dmg.tft->drawPixel(snakeX + 1, snakeY - 1, color);
  dmg.tft->drawPixel(snakeX + 1, snakeY - 2, color);
  dmg.tft->drawPixel(snakeX + 1, snakeY + 2, color);

  dmg.tft->drawPixel(snakeX + 2, snakeY - 2, color);
  dmg.tft->drawPixel(snakeX + 2, snakeY - 1 , color);
  dmg.tft->drawPixel(snakeX + 2, snakeY , color);
  dmg.tft->drawPixel(snakeX + 2, snakeY + 1, color);
  dmg.tft->drawPixel(snakeX + 2, snakeY + 2, color);
}

void drawApple(int appleX, int appleY, uint16_t color){
  dmg.tft->drawPixel(appleX - 1, appleY - 1, color);  //top left
  dmg.tft->drawPixel(appleX, appleY - 1, color);      //top
  dmg.tft->drawPixel(appleX + 1, appleY - 1, color);  //top right
  dmg.tft->drawPixel(appleX - 1, appleY, color);      //left
  dmg.tft->drawPixel(appleX, appleY, color);          //middle
  dmg.tft->drawPixel(appleX + 1, appleY, color);      //right
  dmg.tft->drawPixel(appleX - 1, appleY + 1, color);  //bottom left
  dmg.tft->drawPixel(appleX, appleY + 1, color);      //bottom
  dmg.tft->drawPixel(appleX + 1,  appleY + 1, color); //bottom right
}

void start() {
  // Draw start screen
  dmg.tft->fillScreen(ST7735_BLACK);
  delay(50);

  dmg.tft->setTextColor(ST7735_BLUE);
  dmg.tft->setTextSize(4);
  dmg.tft->setCursor( 21, 35 );
  dmg.tft->println("SNAKE");

  for(int i = -2; i < 31; i++){
    dmg.tft->fillRect(5*i,9,10,10,ST7735_GREEN);
    dmg.tft->fillRect(5*i+10,9,100,10,ST7735_BLACK);

    dmg.tft->drawPixel(5*i+8,9,ST7735_BLACK);
    dmg.tft->drawPixel(5*i+9,9,ST7735_BLACK);
    dmg.tft->drawPixel(5*i+9,10,ST7735_BLACK);

    dmg.tft->drawPixel(5*i+8,18,ST7735_BLACK);
    dmg.tft->drawPixel(5*i+9,17,ST7735_BLACK);
    dmg.tft->drawPixel(5*i+9,18,ST7735_BLACK);

    dmg.tft->fillRect(5*i+5,10,3,3,ST7735_RED);
    dmg.tft->fillRect(5*i+5,14,3,3,ST7735_RED);

    dmg.tft->fillRect(150-5*i,80,10,10,ST7735_GREEN);

    dmg.tft->drawPixel(150-5*i+1,80,ST7735_BLACK);
    dmg.tft->drawPixel(150-5*i,80,ST7735_BLACK);
    dmg.tft->drawPixel(150-5*i,81,ST7735_BLACK);

    dmg.tft->drawPixel(150-5*i,88,ST7735_BLACK);
    dmg.tft->drawPixel(150-5*i,89,ST7735_BLACK);
    dmg.tft->drawPixel(150-5*i+1,89,ST7735_BLACK);

    dmg.tft->fillRect(150-5*i+2,81,3,3,ST7735_RED);
    dmg.tft->fillRect(150-5*i+2,85,3,3,ST7735_RED);
    delay(30);
  }

  dmg.playTone(440, 200);
  delay(200);
  dmg.playTone(880, 500);
  delay(250);

  dmg.tft->setTextColor(ST7735_WHITE);
  dmg.tft->setTextSize(0);
  dmg.tft->setCursor( 15, 115);
  dmg.tft->println("Press -Start- to Play");
  while (!dmg.isStartButtonPressed());

  randomSeed(millis());
  dmg.tft->fillScreen(ST7735_BLACK);
  collision = false;
  apple = false;
  displayEnd = false;
  snakeX = 43;
  snakeY = 84;
  color = ST7735_WHITE;
  buttonPressed = BUTTON_RIGHT;
  currentDirection = BUTTON_RIGHT;

  difficulty=75;
  score = 0;
  head = 0;
  snakeSize = 8;
  timer = 0;
  updateScore(score);
  drawPlayfield();
}

void over() {
  dmg.playTone(440, 500);
  delay(200);
  dmg.playTone(220, 1000);
  dmg.tft->fillScreen(ST7735_BLACK);
  dmg.tft->setTextColor(ST7735_GREEN);
  dmg.tft->setTextSize(2);
  dmg.tft->setCursor( (SW/2) - (9*6), (SH/2) - 4);
  dmg.tft->println("GAME OVER");
  dmg.tft->setTextColor(ST7735_WHITE);
  dmg.tft->setTextSize(0);
  dmg.tft->setCursor( 50, (SH/2) - 26);
  dmg.tft->print("Score:");
  dmg.tft->print(score);
  dmg.tft->setCursor( 7, 105);
  dmg.tft->println("Press -Start- to Restart");
  while (!dmg.isStartButtonPressed());
}
