#include "Sign_GFX.h"

CRGB leds[NUM_LEDS_PER_STRIP * NUM_STRIPS];

int rectToIndex(int boardX, int boardY) {
  // find the index of the LED at Y level(alternates left and right side)
  int interY = (boardY * 56) - 1;
  // calculate the final index based on whether the Y index starts on the right or left which is determined by even or odd respectively
  int finalIndex = (boardY % 2 == 0) ? interY - (56 - boardX) : interY - (boardX - 1);
  return finalIndex;
}

void drawLine(int startX, int startY, int endX, int endY, CRGB color) {
  bool steep = abs(endY - startY) > abs(endX - startX);
  int inter;
  if (steep) {
    inter = startX;
    startX = startY;
    startY = inter;
    inter = endX;
    endX = endY;
    endY = inter;
  }

  //ensures the line is always drawn from left to right
  if (endX < startX) {
    inter = startX;
    startX = endX;
    endX = inter;
    inter = startY;
    startY = endY;
    endY = inter;
  }

  int riseY = (endY - startY);
  int runX = (endX - startX);

  int err = runX / 2;
  int ystep;

  if (startY < endY) {
    ystep = 1;
  } else {
    ystep = -1;
  }

  //draw the line procedurally from left to right
  for(; startX <= endX; startX++) {
    if (steep) {
      leds[rectToIndex(startY, startX)] = color;
    } else {
      leds[rectToIndex(startX, startY)] = color;
    }
    err -= riseY * ystep;
    if (err < 0) {
      startY += ystep;
      err += runX;
    }
  }
}

void drawRect(int x0, int y0, int x1, int y1, CRGB color) {
  drawLine(x0, y0, x1, y0, color);
  drawLine(x0, y0, x0, y1, color);
  drawLine(x1, y0, x1, y1, color);
  drawLine(x0, y1, x1, y1, color);
}

void drawTri(int x, int y, int base, int height, CRGB color) {
  drawLine(x, y, x + base, y, color);
  drawLine(x, y, x + base/2, y + height, color);
  drawLine(x + base, y, x + base/2, y + height, color);
}

void drawEllipse(int rx, int ry, int xc, int yc, CRGB color) {
  float dx, dy, d1, d2, x, y;
  x = 0;
  y = ry;
 
  // Initial decision parameter of region 1
  d1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
  dx = 2 * ry * ry * x;
  dy = 2 * rx * rx * y;
 
  // For region 1
  while (dx < dy) 
  {
    // Print points based on 4-way symmetry
    leds[rectToIndex(x + xc, y + yc)] = color;
    leds[rectToIndex(-x + xc, y + yc)] = color;
    leds[rectToIndex(x + xc, -y + yc)] = color;
    leds[rectToIndex(-x + xc, -y + yc)] = color;
 
    // Checking and updating value of
    // decision parameter based on algorithm
    if (d1 < 0)
    {
      x++;
      dx = dx + (2 * ry * ry);
      d1 = d1 + dx + (ry * ry);
    }
    else
    {
      x++;
      y--;
      dx = dx + (2 * ry * ry);
      dy = dy - (2 * rx * rx);
      d1 = d1 + dx - dy + (ry * ry);
    }
  }
 
  // Decision parameter of region 2
  d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) + ((rx * rx) * ((y - 1) * (y - 1))) - (rx * rx * ry * ry);
 
  // Plotting points of region 2
  while (y >= 0)
  {
    // Print points based on 4-way symmetry
    leds[rectToIndex(x + xc, y + yc)] = color;
    leds[rectToIndex(-x + xc, y + yc)] = color;
    leds[rectToIndex(x + xc, -y + yc)] = color;
    leds[rectToIndex(-x + xc, -y + yc)] = color;

    // Checking and updating parameter
    // value based on algorithm
    if (d2 > 0) 
    {
      y--;
      dy = dy - (2 * rx * rx);
      d2 = d2 + (rx * rx) - dy;
    }
    else
    {
      y--;
      x++;
      dx = dx + (2 * ry * ry);
      dy = dy - (2 * rx * rx);
      d2 = d2 + dx - dy + (rx * rx);
    }
  }
}

