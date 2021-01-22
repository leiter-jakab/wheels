#include <Arduino.h>

#ifndef LEDS_H
#define LEDS_H

#define NUM_COLORS 36

void initLeds();
void setLed(byte ledNum, byte value);

#endif
