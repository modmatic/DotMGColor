#ifndef _DOTMGCOLOR_H
#define _DOTMGCOLOR_H

#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>

#define PIN_TFT_CS  A3
#define PIN_TFT_RST 8
#define PIN_TFT_DC  9

#define PIN_BUTTON_A      2
#define PIN_BUTTON_B      3
#define PIN_BUTTON_UP     4
#define PIN_BUTTON_DOWN   5
#define PIN_BUTTON_LEFT   6
#define PIN_BUTTON_RIGHT  7
#define PIN_BUTTON_START  A0
#define PIN_BUTTON_SELECT A1

#define MASK_BUTTON_A      (1 << PIN_BUTTON_A)
#define MASK_BUTTON_B      (1 << PIN_BUTTON_B)
#define MASK_BUTTON_UP     (1 << PIN_BUTTON_UP)
#define MASK_BUTTON_DOWN   (1 << PIN_BUTTON_DOWN)
#define MASK_BUTTON_LEFT   (1 << PIN_BUTTON_LEFT)
#define MASK_BUTTON_RIGHT  (1 << PIN_BUTTON_RIGHT)
#define MASK_BUTTON_START  (1 << (PIN_BUTTON_START - A0))
#define MASK_BUTTON_SELECT (1 << (PIN_BUTTON_SELECT - A0))

#define PORT_BUTTON_A      PIND
#define PORT_BUTTON_B      PIND
#define PORT_BUTTON_UP     PIND
#define PORT_BUTTON_DOWN   PIND
#define PORT_BUTTON_LEFT   PIND
#define PORT_BUTTON_RIGHT  PIND
#define PORT_BUTTON_START  PINC
#define PORT_BUTTON_SELECT PINC

#define PIN_SPEAKER A2

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
