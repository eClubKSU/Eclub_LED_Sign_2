#ifndef SIGN_GFX_H
#define SIGN_GFX_H

#include "../types.h"
#include "../driver/driver.h"
#include "../bitmap/bitmaps.h"
#include "color.h"

namespace GFX {

  struct Point {
    u16_t x;
    u16_t y;
  };

  inline bool operator==(const Point& lhs, const Point& rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y;
  }

  struct Pixel {
    u16_t x;
    u16_t y;
    u32_t color;
    u16_t millisDuration;
  };


  void drawLine(u16_t x0, u16_t y0, u16_t x1, u16_t y1, RGB color);
  void drawRect(u16_t x0, u16_t y0, u16_t x1, u16_t y1, RGB color);
  void drawTri(u16_t x, u16_t y, u16_t base, u16_t height, RGB color);
  void drawTri(u16_t x, u16_t y, u16_t base, u16_t height, RGB color, u16_t orientation);
  void drawEllipse(u16_t rx, u16_t ry, u16_t xc, u16_t yc, RGB color);
  void clear();
  void fill(RGB color);
  void drawBitmap(Bitmap* map, u16_t x, u16_t y, RGB color);
  void drawBitmap(Bitmap* map, u16_t x, u16_t y);
  void drawText(const char* text, Bitmap* font[], u16_t x, u16_t y, RGB color);
}

#endif
