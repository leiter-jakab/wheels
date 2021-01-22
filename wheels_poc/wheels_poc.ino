#include "buttons.h"
#include "wheels.h"
#include "leds.h"

void setup() {
  Serial.begin(115200);
  while (!Serial) {};

  Serial.println("starting");
  initButtons();
  initLeds();
  initWheels();
}

void loop() {
  if (millis() % 10 < 1) {
    tickButtons();
  }
  tickWheels();
}
