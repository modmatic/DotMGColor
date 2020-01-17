#include <DotMGColor.h>

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
  return !digitalRead(PIN_BUTTON_A);
}

bool DotMG::isBButtonPressed() const {
  return !digitalRead(PIN_BUTTON_B);
}

bool DotMG::isUpButtonPressed() const {
  return !digitalRead(PIN_BUTTON_UP);
}

bool DotMG::isDownButtonPressed() const {
  return !digitalRead(PIN_BUTTON_DOWN);
}

bool DotMG::isLeftButtonPressed() const {
  return !digitalRead(PIN_BUTTON_LEFT);
}

bool DotMG::isRightButtonPressed() const {
  return !digitalRead(PIN_BUTTON_RIGHT);
}

bool DotMG::isStartButtonPressed() const {
  return !digitalRead(PIN_BUTTON_START);
}

bool DotMG::isSelectButtonPressed() const {
  return !digitalRead(PIN_BUTTON_SELECT);
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
