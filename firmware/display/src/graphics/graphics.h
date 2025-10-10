#ifndef SIGN_GFX_H
#define SIGN_GFX_H

#include "../types.h"
#include "../driver/driver.h"
#include "../bitmap/bitmaps.h"
#include "color.h"

namespace GFX {


  std::vector<Point> line(i16_t x0, i16_t y0, i16_t x1, i16_t y1);
  std::vector<Point> rectangle(i16_t base, i16_t height);
  std::vector<Point> triangle(i16_t base, i16_t height);
  std::vector<Point> triangle(i16_t base, i16_t height, u16_t orientation);
  std::vector<Point> ellipse(u16_t rx, u16_t ry);

  void draw(std::vector<Point> map, i16_t x, i16_t y, ARGB color);

  void draw(std::vector<Point> map, i16_t x, i16_t y, Color::PosEffect effect);
  void draw(std::vector<Point> map, i16_t x, i16_t y, Color::IndexEffect effect);

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
