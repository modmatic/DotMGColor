#ifndef _DOTMG_MINIMAL_H
#define _DOTMG_MINIMAL_H

#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>

#define PIN_BUTTON_A      20
#define PIN_BUTTON_B      21
#define PIN_BUTTON_UP     18
#define PIN_BUTTON_DOWN   4
#define PIN_BUTTON_LEFT   5
#define PIN_BUTTON_RIGHT  19
#define PIN_BUTTON_START  0
#define PIN_BUTTON_SELECT 1

#define PIN_SPEAKER PIN_DAC1

class DotMG
{
public:
  DotMG();
  ~DotMG();

  // TODO: Make private and not pointer in public
  SPIClass *spi;
  Adafruit_ST7735 *tft;

  void begin();
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
