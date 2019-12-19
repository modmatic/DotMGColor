# DotMGColor

Library for creating games and other programs with the Modmatic dotMG in full 16-bit color.

## Installation

1. Download this repo as a ZIP file to a known location on your machine.

2. Install the library using the following guide:

[Installing Additional Arduino Libraries](https://www.arduino.cc/en/Guide/Libraries#toc5)

Requires:

 - [Adafruit SP7735 Library](https://github.com/adafruit/Adafruit-ST7735-Library)
 - [Adafruit GFX Library](https://github.com/adafruit/Adafruit-GFX-Library)

## Caveats

Because color is 16-bit and the ATmega328P does not have enough RAM, [double buffering](https://gameprogrammingpatterns.com/double-buffer.html) is not supported by this library. See the [recommended dotMG library](https://github.com/modmatic/DotMG) for 4-color (2-bit) double buffering support.
