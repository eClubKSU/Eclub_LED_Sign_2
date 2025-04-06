#ifndef SIGN_GFX_H
#define SIGN_GFX_H

#include <Arduino.h>
#include <FastLED.h>
#include <vector>

#define NUM_STRIPS 2
#define NUM_LEDS_PER_STRIP 560
#define NUM_LEDS NUM_LEDS_PER_STRIP * NUM_STRIPS

namespace GFX {

  struct Point {
    uint16_t x;
    uint16_t y;
  };

  struct Pixel {
    uint16_t x;
    uint16_t y;
    CRGB color;
    uint16_t millisDuration;
  };

  struct Bitmap {
    uint16_t wid;
    uint16_t hth;
    uint8_t* bitmap;
  };

  struct ColorBitmap {
    uint16_t wid;
    uint16_t hth;
    CRGB* bitmap;
  };

  struct Color {
    union {
      CRGB color;
    };
  };

  extern CRGB leds[NUM_LEDS_PER_STRIP * NUM_STRIPS];
  extern std::vector<Pixel*> pixelBuffer;

  int rectToIndex(uint16_t x, uint16_t y);
  void drawPoint(uint16_t x, uint16_t y, CRGB color);
  void drawLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, CRGB color);
  void drawRect(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, CRGB color);
  void drawTri(uint16_t x, uint16_t y, uint16_t base, uint16_t height, CRGB color);
  void drawEllipse(uint16_t rx, uint16_t ry, uint16_t xc, uint16_t yc, CRGB color);
  void clear();
  void fill(CRGB color);
  void drawBitmap(Bitmap* map, uint16_t x, uint16_t y, CRGB color);
  void drawBitmap(ColorBitmap* map, uint16_t x, uint16_t y);
  void drawText(char* text, Bitmap font[], uint16_t x, uint16_t y, CRGB color);
  void drawRollingText(char* text, Bitmap font[], uint16_t x, uint16_t y, uint16_t width, uint16_t index, CRGB color);
  void addBuffer(uint16_t x, uint16_t y, CRGB color, uint16_t millisDuration);
  void addBuffer(uint16_t x[], uint16_t y[], CRGB color, uint16_t millisDuration, uint16_t length);
  void consumeBuffer();

  // Blaine TODO : antiAliasing() <- maybe
  void drawInstant();
  void drawAnimate();

}

#endif
