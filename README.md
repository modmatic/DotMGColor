# DotMG_Minimal

This is a bare-bones library that gives access to all of dotMG's I/O capabilities:

- TFT display
- Piezo buzzer
- A, B, D-pad, Start, Select buttons

Use this library if you only want/need a simple way to interact with the above I/O. For a more comprehensive game development library, see the [recommended dotMG library][rec_lib] or the [Arduboy2DotMG library][ard_lib].

## Examples

- [**`io_test`**](/examples/io_test/io_test.ino): Simple program that plays tones and draws to the screen to indicate which buttons are being pressed.

- [**`snake`**](/examples/snake/snake.ino): The classic Snake game!

## Installation

1. Download this repo as a ZIP file to a known location on your machine.

2. Install the library using the following guide:

[Installing Additional Arduino Libraries](https://www.arduino.cc/en/Guide/Libraries#toc5)

Requires:

 - [Adafruit SP7735 Library](https://github.com/adafruit/Adafruit-ST7735-Library)
 - [Adafruit GFX Library](https://github.com/adafruit/Adafruit-GFX-Library)

## Advanced

If you'd like to enable direct memory access (DMA) to speed up screen updates, just edit your local copy of `Adafruit_GFX_Library/AdafruitSPITFT.h` and uncomment a line that looks similar to:

```cpp
 // #define USE_SPI_DMA
```

## Caveats

Please note that [double buffering](https://gameprogrammingpatterns.com/double-buffer.html) is not implemented in this library. See the [recommended dotMG library][rec_lib] or the [Arduboy2DotMG library][ard_lib] for double buffering support.

[rec_lib]: https://github.com/modmatic/DotMG
[ard_lib]: https://github.com/modmatic/Arduboy2DotMG
