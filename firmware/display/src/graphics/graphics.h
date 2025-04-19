#ifndef SIGN_GFX_H
#define SIGN_GFX_H

#include <Arduino.h>
#include "../driver/driver.h"
#include "../bitmap/bitmaps.h"
#include "../color/color.h"



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
}

#endif
