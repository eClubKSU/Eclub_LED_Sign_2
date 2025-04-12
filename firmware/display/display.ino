#include "src/graphics/graphics.h"
#include "src/apps/app_manager.h"
#include "src/bitmap/bitmaps.h"
#include "src/keyboard/keyboard.h"
#include <FastLED.h>
#include <cmath>
#include <vector>
#include <Entropy.h>




// For mirroring strips, all the "special" stuff happens just in setup.  We
// just addLeds multiple times, once for each strip
void setup() {
  Entropy.Initialize();
  randomSeed(Entropy.random());
  Serial.begin(9600);
  Serial.println("Serial");
  
  // tell FastLED there's 560 NEOPIXEL leds on pin 2, starting at index 0 in the led array
  FastLED.addLeds<DOTSTAR, 11, 13, BGR, DATA_RATE_MHZ(4)>(GFX::leds, 0, NUM_LEDS_PER_STRIP);
  // tell FastLED there's 560 NEOPIXEL leds on pin 3, starting at index 560 in the led array
  FastLED.addLeds<DOTSTAR, 26, 27, BGR, DATA_RATE_MHZ(4)>(GFX::leds, NUM_LEDS_PER_STRIP, NUM_LEDS_PER_STRIP);

  GFX::clear();
  FastLED.show();

  Key::setup();

  appSetup();

  //startApp("physics");
}

void loop() {
  cycleApps();
  //startApp("dino");
}

