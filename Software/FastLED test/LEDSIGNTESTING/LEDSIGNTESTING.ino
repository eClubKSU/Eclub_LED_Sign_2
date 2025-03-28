#include "Sign_GFX.h"
#include "bitmap/bitmaps.h"
#include <FastLED.h>
#include <cmath>
#include <vector>

Pixel p1;

byte test[3] = {0, 0, 0};
uint16_t x[4] = {5, 6, 7, 8};
uint16_t y[4] = {5, 6, 7, 8};

// For mirroring strips, all the "special" stuff happens just in setup.  We
// just addLeds multiple times, once for each strip
void setup() {
  // tell FastLED there's 560 NEOPIXEL leds on pin 2, starting at index 0 in the led array
  FastLED.addLeds<DOTSTAR, 11, 13, BGR, DATA_RATE_MHZ(2)>(leds, 0, NUM_LEDS_PER_STRIP);

  // tell FastLED there's 560 NEOPIXEL leds on pin 3, starting at index 560 in the led array
  FastLED.addLeds<DOTSTAR, 26, 27, BGR, DATA_RATE_MHZ(2)>(leds, NUM_LEDS_PER_STRIP, NUM_LEDS_PER_STRIP);

  addBuffer(x, y, CRGB(0x040404), 1000, 4);
}


void loop() {
  //drawGrayscaleBitmap(test, 24, 6, 5, 4, CRGB(0x040404));
  drawAnimate();
  //leds[rectToIndex(1, 1)] = CRGB::White;
  //drawLine(3, 5, 10, 17);
  //drawRect(17, 3, 27, 13, CRGB(0x040404));
  //drawTri(3, 3, 10, 10, CRGB(0x040404));
  //drawLine(31, 3, 41, 13, CRGB(0x040404));
  //drawLine(31, 13, 41, 3, CRGB(0x040404));
  //drawEllipse(20, 8, 28, 11, CRGB(0x040404));
  //fill(CRGB::Amethyst);
  //pride();
  //bright();
  //flashbang();
  FastLED.show();
}


/*
void bright() {
  for(int i = 0; i < NUM_LEDS; i++) {
   leds[i] = CRGB::White;
  }
}

bool t = false;
void flashbang() {
  bool t = false;
  for(int i = 0; i < NUM_LEDS; i++) {
   leds[i] = t ? CRGB::White : CRGB::Black;
  }
  t = !t;
}

void pride() 
{
  static uint16_t sPseudotime = 0;
  static uint16_t sLastMillis = 0;
  static uint16_t sHue16 = 0;
 
  uint8_t sat8 = beatsin88( 87, 220, 250);
  uint8_t brightdepth = beatsin88( 341, 96, 224);
  uint16_t brightnessthetainc16 = beatsin88( 203, (25 * 256), (40 * 256));
  uint8_t msmultiplier = beatsin88(147, 23, 60);

  uint16_t hue16 = sHue16;//gHue * 256;
  uint16_t hueinc16 = beatsin88(113, 1, 3000);
  
  uint16_t ms = millis();
  uint16_t deltams = ms - sLastMillis ;
  sLastMillis  = ms;
  sPseudotime += deltams * msmultiplier;
  sHue16 += deltams * beatsin88( 400, 5,9);
  uint16_t brightnesstheta16 = sPseudotime;
  
  for( uint16_t i = 0 ; i < NUM_LEDS; i++) {
    hue16 += hueinc16;
    uint8_t hue8 = hue16 / 256;

    brightnesstheta16  += brightnessthetainc16;
    uint16_t b16 = sin16( brightnesstheta16  ) + 32768;

    uint16_t bri16 = (uint32_t)((uint32_t)b16 * (uint32_t)b16) / 65536;
    uint8_t bri8 = (uint32_t)(((uint32_t)bri16) * brightdepth) / 65536;
    bri8 += (255 - brightdepth);
    
    CRGB newcolor = CHSV( hue8, sat8, bri8);
    
    uint16_t pixelnumber = i;
    pixelnumber = (NUM_LEDS-1) - pixelnumber;
    
    nblend( leds[pixelnumber], newcolor, 64);
  }
}
*/
