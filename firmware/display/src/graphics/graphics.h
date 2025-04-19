#ifndef SIGN_GFX_H
#define SIGN_GFX_H

#include <Arduino.h>
#include "../driver/driver.h"
#include <vector>

#define NUM_STRIPS 2
#define NUM_LEDS_PER_STRIP 560
#define NUM_LEDS NUM_LEDS_PER_STRIP * NUM_STRIPS

namespace GFX {

  struct Point {
    uint16_t x;
    uint16_t y;
  };

  inline bool operator==(const Point& lhs, const Point& rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y;
  }

  struct Pixel {
    uint16_t x;
    uint16_t y;
    uint32_t color;
    uint16_t millisDuration;
  };

  struct Bitmap {
    uint16_t wid;
    uint16_t hth;
    uint16_t size;
    uint32_t* palette;
    uint8_t* bitmap;
  };

  struct ColorBitmap {
    uint16_t wid;
    uint16_t hth;
    uint32_t* bitmap;
  };

  extern std::vector<Pixel*> pixelBuffer;

  int rectToIndex(uint16_t x, uint16_t y);
  //void drawPoint(uint16_t x, uint16_t y, uint32_t color);
  void drawLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint32_t color);
  void drawRect(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint32_t color);
  void drawTri(uint16_t x, uint16_t y, uint16_t base, uint16_t height, uint32_t color);
  void drawTri(uint16_t x, uint16_t y, uint16_t base, uint16_t height, uint32_t color, uint16_t orientation);
  void drawEllipse(uint16_t rx, uint16_t ry, uint16_t xc, uint16_t yc, uint32_t color);
  void clear();
  void fill(uint32_t color);
  void drawBitmap(Bitmap* map, uint16_t x, uint16_t y, uint32_t color);
  void drawBitmap(Bitmap* map, uint16_t x, uint16_t y);
  void drawText(const char* text, Bitmap* font[], uint16_t x, uint16_t y, uint32_t color);
  void drawRollingText(const char* text, Bitmap* font[], uint16_t x, uint16_t y, uint16_t width, uint16_t index, uint32_t color);
  void addBuffer(uint16_t x, uint16_t y, uint32_t color, uint16_t millisDuration);
  void addBuffer(uint16_t x[], uint16_t y[], uint32_t color, uint16_t millisDuration, uint16_t length);
  void consumeBuffer();

  // Blaine TODO : antiAliasing() <- maybe
  void drawInstant();
  void drawAnimate();

}

#endif
