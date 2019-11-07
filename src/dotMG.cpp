#include <DotMG.h>

DotMG::DotMG() {
  this->tft = new Adafruit_ST7735(PIN_TFT_CS, PIN_TFT_DC, PIN_TFT_RST);
}

DotMG::~DotMG() {
  delete this->tft;
}

void DotMG::init() {
  this->tft->initR(INITR_BLACKTAB);
  this->tft->setRotation(1);
  this->tft->fillScreen(ST77XX_BLACK);

  pinMode(PIN_BUTTON_A, INPUT_PULLUP);
  pinMode(PIN_BUTTON_B, INPUT_PULLUP);
  pinMode(PIN_BUTTON_UP, INPUT_PULLUP);
  pinMode(PIN_BUTTON_DOWN, INPUT_PULLUP);
  pinMode(PIN_BUTTON_LEFT, INPUT_PULLUP);
  pinMode(PIN_BUTTON_RIGHT, INPUT_PULLUP);
  pinMode(PIN_BUTTON_START, INPUT_PULLUP);
  pinMode(PIN_BUTTON_SELECT, INPUT_PULLUP);
}

bool DotMG::isAButtonPressed() const {
  return (PORT_BUTTON_A & MASK_BUTTON_A) == 0;
}

bool DotMG::isBButtonPressed() const {
  return (PORT_BUTTON_B & MASK_BUTTON_B) == 0;
}

bool DotMG::isUpButtonPressed() const {
  return (PORT_BUTTON_UP & MASK_BUTTON_UP) == 0;
}

bool DotMG::isDownButtonPressed() const {
  return (PORT_BUTTON_DOWN & MASK_BUTTON_DOWN) == 0;
}

bool DotMG::isLeftButtonPressed() const {
  return (PORT_BUTTON_LEFT & MASK_BUTTON_LEFT) == 0;
}

bool DotMG::isRightButtonPressed() const {
  return (PORT_BUTTON_RIGHT & MASK_BUTTON_RIGHT) == 0;
}

bool DotMG::isStartButtonPressed() const {
  return (PORT_BUTTON_START & MASK_BUTTON_START) == 0;
}

bool DotMG::isSelectButtonPressed() const {
  return (PORT_BUTTON_SELECT & MASK_BUTTON_SELECT) == 0;
}

void DotMG::playTone(unsigned int frequency) const {
  tone(PIN_SPEAKER, frequency);
}

void DotMG::playTone(unsigned int frequency, unsigned long duration) const {
  tone(PIN_SPEAKER, frequency, duration);
}
void DotMG::stopTone() const {
  noTone(PIN_SPEAKER);
}

DotMG dmg;