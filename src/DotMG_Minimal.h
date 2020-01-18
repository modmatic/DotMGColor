#ifndef _DOTMG_MINIMAL_H
#define _DOTMG_MINIMAL_H

#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>

#define PIN_TFT_CS  16
#define PIN_TFT_DC  17
#define PIN_TFT_RST 18

#define PIN_BUTTON_A      9
#define PIN_BUTTON_B      10
#define PIN_BUTTON_UP     5
#define PIN_BUTTON_DOWN   6
#define PIN_BUTTON_LEFT   7
#define PIN_BUTTON_RIGHT  8
#define PIN_BUTTON_START  14
#define PIN_BUTTON_SELECT 15

#define PIN_SPEAKER PIN_DAC0

class DotMG
{
public:
  DotMG();
  ~DotMG();

  Adafruit_ST7735 *tft;

  void init();
  bool isAButtonPressed() const;
  bool isBButtonPressed() const;
  bool isUpButtonPressed() const;
  bool isDownButtonPressed() const;
  bool isLeftButtonPressed() const;
  bool isRightButtonPressed() const;
  bool isStartButtonPressed() const;
  bool isSelectButtonPressed() const;
  void playTone(unsigned int frequency) const;
  void playTone(unsigned int frequency, unsigned long duration) const;
  void stopTone() const;
};

extern DotMG dmg;

#endif
