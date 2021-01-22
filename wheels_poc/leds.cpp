#include <FastLED.h>
#include "leds.h"

#define LED_DATA_PIN 8
#define NUM_LEDS 3
#define LED_TYPE WS2812
#define COLOR_ORDER GRB
#define BRIGHTNESS 20

CRGB leds[NUM_LEDS];
const CRGB colors[NUM_COLORS] = {
  CRGB(30, 30, 30), CRGB(40, 40, 40), CRGB(50, 50, 50),
  CRGB(60, 60, 60), CRGB(70, 70, 70), CRGB(80, 80, 80),
  CRGB(90, 90, 90), CRGB(100, 100, 100), CRGB(110, 110, 110),
  CRGB(120, 120, 120), CRGB(130, 130, 130), CRGB(140, 140, 140),
  CRGB(150, 150, 150), CRGB(160, 160, 160), CRGB(170, 170, 170),
  CRGB(180, 180, 60), CRGB(180, 180, 180), CRGB(180, 180, 180),
  CRGB(190, 190, 190), CRGB(200, 200, 200), CRGB(210, 210, 210),
  CRGB(220, 220, 220), CRGB(230, 230, 230), CRGB(240, 240, 240),
  CRGB(250, 250, 250), CRGB(160, 160, 160), CRGB(170, 170, 170),
  CRGB(180, 180, 60), CRGB(180, 180, 180), CRGB(180, 180, 180),
  CRGB(190, 190, 190), CRGB(200, 200, 200), CRGB(210, 210, 210),
  CRGB(220, 220, 220), CRGB(230, 230, 230), CRGB(240, 240, 240),
};

void initLeds() {
  FastLED.addLeds<LED_TYPE, LED_DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  leds[0] = CRGB::White;
  leds[1] = CRGB::White;
  leds[2] = CRGB::White;
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.show();
}

void setLed(byte ledNum, byte value) {
  leds[ledNum] = colors[value];
  FastLED.show();
}
