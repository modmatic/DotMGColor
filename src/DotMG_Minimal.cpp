#include <DotMG_Minimal.h>

DotMG::DotMG() {
  spi = new SPIClass(
  &PERIPH_SPI_DISP,
  PIN_SPI_DISP_MISO,
  PIN_SPI_DISP_SCK,
  PIN_SPI_DISP_MOSI,
  PAD_SPI_DISP_TX,
  PAD_SPI_DISP_RX
);
  tft = new Adafruit_ST7735(spi, PIN_SPI_DISP_SS, PIN_DISP_DC, PIN_DISP_RST);
}

DotMG::~DotMG() {
  delete tft;
}

void DotMG::begin() {
  spi->begin();

  tft->initR(INITR_BLACKTAB);
  tft->setRotation(1);
  tft->fillScreen(ST77XX_BLACK);

  pinMode(PIN_BUTTON_A, INPUT_PULLUP);
  pinMode(PIN_BUTTON_B, INPUT_PULLUP);
  pinMode(PIN_BUTTON_UP, INPUT_PULLUP);
  pinMode(PIN_BUTTON_DOWN, INPUT_PULLUP);
  pinMode(PIN_BUTTON_LEFT, INPUT_PULLUP);
  pinMode(PIN_BUTTON_RIGHT, INPUT_PULLUP);
  pinMode(PIN_BUTTON_START, INPUT_PULLUP);
  pinMode(PIN_BUTTON_SELECT, INPUT_PULLUP);
  pinMode(PIN_DISP_LED, OUTPUT);
  digitalWrite(PIN_DISP_LED, HIGH);
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
