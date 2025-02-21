#include <FastLED.h>
#include <cmath>
#include "config.h"
#include "src/graphics/graphics.h"

#define NUM_STRIPS 2
#define NUM_LEDS_PER_STRIP 560
#define NUM_LEDS NUM_LEDS_PER_STRIP * NUM_STRIPS

CRGB leds[NUM_STRIPS * NUM_LEDS_PER_STRIP];

// For mirroring strips, all the "special" stuff happens just in setup.  We
// just addLeds multiple times, once for each strip
void setup() {
    // tell FastLED there's 560 NEOPIXEL leds on pin 2, starting at index 0 in the led array
    FastLED.addLeds<DOTSTAR, 11, 13, BGR, DATA_RATE_MHZ(1)>(leds, 0, NUM_LEDS_PER_STRIP);
    // tell FastLED there's 560 NEOPIXEL leds on pin 3, starting at index 560 in the led array
    FastLED.addLeds<DOTSTAR, 26, 27, BGR, DATA_RATE_MHZ(1)>(leds, NUM_LEDS_PER_STRIP, NUM_LEDS_PER_STRIP);
}

void loop () {
    int i = 0;
    leds[i] = CRGB::White;
    FastLED.show();
}
