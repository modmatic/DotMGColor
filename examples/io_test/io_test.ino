// I/O Test Program
// Written by Andrew Meyer
// Copyright 2019

#include <DotMG_Minimal.h>

class Button {
public:
  bool currentState, lastState = true;
  unsigned int toneFreq;
  uint16_t color;

  Button(uint16_t color, unsigned int toneFreq) {
    this->color = color;
    this->toneFreq = toneFreq;
  }

  bool changed() {
    return this->currentState != this->lastState;
  }

  uint16_t fg() {
    return currentState ? ST77XX_BLACK : this->color;
  }

  uint16_t bg() {
    return currentState ? this->color : ST77XX_BLACK;
  }

  void updateTone(DotMG &dmg) {
    if (this->currentState) {
      dmg.playTone(this->toneFreq);
    } else {
      dmg.stopTone();
    }
  }

  void flush() {
    this->lastState = this->currentState;
  }
};

void setup() {
  dmg.begin();
}

Button buttonA = Button(ST77XX_MAGENTA, 294);
Button buttonB = Button(ST77XX_MAGENTA, 262);
Button buttonUp = Button(ST77XX_BLUE, 587);
Button buttonDown = Button(ST77XX_BLUE, 349);
Button buttonLeft = Button(ST77XX_BLUE, 494);
Button buttonRight = Button(ST77XX_BLUE, 440);
Button buttonStart = Button(ST77XX_CYAN, 196);
Button buttonSelect = Button(ST77XX_CYAN, 175);

void loop() {
  buttonA.currentState = dmg.isAButtonPressed();
  buttonB.currentState = dmg.isBButtonPressed();
  buttonUp.currentState = dmg.isUpButtonPressed();
  buttonDown.currentState = dmg.isDownButtonPressed();
  buttonLeft.currentState = dmg.isLeftButtonPressed();
  buttonRight.currentState = dmg.isRightButtonPressed();
  buttonStart.currentState = dmg.isStartButtonPressed();
  buttonSelect.currentState = dmg.isSelectButtonPressed();

  if (buttonA.changed()) {
    buttonA.updateTone(dmg);
    dmg.tft->fillCircle(135, 50, 15, buttonA.bg());
    dmg.tft->drawChar(131, 43, 'A', buttonA.fg(), buttonA.bg(), 2);
    dmg.tft->drawCircle(135, 50, 15, buttonA.color);
  }

  if (buttonB.changed()) {
    buttonB.updateTone(dmg);
    dmg.tft->fillCircle(100, 70, 15, buttonB.bg());
    dmg.tft->drawChar(96, 63, 'B', buttonB.fg(), buttonB.bg(), 2);
    dmg.tft->drawCircle(100, 70, 15, buttonB.color);
  }

  if (buttonUp.changed()) {
    buttonUp.updateTone(dmg);
    dmg.tft->fillTriangle(35, 35, 25, 45, 45, 45, buttonUp.bg());
    dmg.tft->drawTriangle(35, 35, 25, 45, 45, 45, buttonUp.color);
  }

  if (buttonDown.changed()) {
    buttonDown.updateTone(dmg);
    dmg.tft->fillTriangle(35, 85, 25, 75, 45, 75, buttonDown.bg());
    dmg.tft->drawTriangle(35, 85, 25, 75, 45, 75, buttonDown.color);
  }

  if (buttonLeft.changed()) {
    buttonLeft.updateTone(dmg);
    dmg.tft->fillTriangle(10, 60, 20, 50, 20, 70, buttonLeft.bg());
    dmg.tft->drawTriangle(10, 60, 20, 50, 20, 70, buttonLeft.color);
  }

  if (buttonRight.changed()) {
    buttonRight.updateTone(dmg);
    dmg.tft->fillTriangle(60, 60, 50, 50, 50, 70, buttonRight.bg());
    dmg.tft->drawTriangle(60, 60, 50, 50, 50, 70, buttonRight.color);
  }

  if (buttonStart.changed()) {
    buttonStart.updateTone(dmg);
    dmg.tft->fillRoundRect(89, 100, 45, 15, 5, buttonStart.bg());
    dmg.tft->setCursor(97, 104);
    dmg.tft->setTextColor(buttonStart.fg(), buttonStart.bg());
    dmg.tft->print("START");
    dmg.tft->drawRoundRect(89, 100, 45, 15, 5, buttonStart.color);
  }

  if (buttonSelect.changed()) {
    buttonSelect.updateTone(dmg);
    dmg.tft->fillRoundRect(39, 100, 45, 15, 5, buttonSelect.bg());
    dmg.tft->setCursor(44, 104);
    dmg.tft->setTextColor(buttonSelect.fg(), buttonSelect.bg());
    dmg.tft->print("SELECT");
    dmg.tft->drawRoundRect(39, 100, 45, 15, 5, buttonSelect.color);
  }

  buttonA.flush();
  buttonB.flush();
  buttonUp.flush();
  buttonDown.flush();
  buttonLeft.flush();
  buttonRight.flush();
  buttonStart.flush();
  buttonSelect.flush();
}
