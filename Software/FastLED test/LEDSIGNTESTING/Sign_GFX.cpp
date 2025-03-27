#include "Sign_GFX.h"

CRGB leds[NUM_LEDS_PER_STRIP * NUM_STRIPS];
std::vector<Pixel*> pixelBuffer;

int rectToIndex(uint16_t x, uint16_t y) {
  // find the index of the LED at Y level(alternates left and right side)
  int interY = (y * 56) - 1;
  // calculate the final index based on whether the Y index starts on the right or left which is determined by even or odd respectively
  int finalIndex = (y % 2 == 0) ? interY - (56 - x) : interY - (x - 1);
  return finalIndex;
}

void drawPoint(uint16_t x, uint16_t y, CRGB color) {
  leds[rectToIndex(x, y)] = color;
}

void drawLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, CRGB color) {
  bool steep = abs(y1 - y0) > abs(x1 - x0);
  uint16_t inter;
  if (steep) {
    inter = x0;
    x0 = y0;
    y0 = inter;
    inter = x1;
    x1 = y1;
    y1 = inter;
  }

  //ensures the line is always drawn from left to right
  if (x1 < x0) {
    inter = x0;
    x0 = x1;
    x1 = inter;
    inter = y0;
    y0 = y1;
    y1 = inter;
  }

  int16_t riseY = (y1 - y0);
  int16_t runX = (x1 - x0);

  int16_t err = runX / 2;
  int16_t ystep;

  if (y0 < y1) {
    ystep = 1;
  } else {
    ystep = -1;
  }

  //draw the line procedurally from left to right
  for(; x0 <= x1; x0++) {
    if (steep) {
      drawPoint(y0, x0, color);
    } else {
      drawPoint(x0, y0, color);
    }
    err -= riseY * ystep;
    if (err < 0) {
      y0 += ystep;
      err += runX;
    }
  }
}

void drawRect(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, CRGB color) {
  drawLine(x0, y0, x1, y0, color);
  drawLine(x0, y0, x0, y1, color);
  drawLine(x1, y0, x1, y1, color);
  drawLine(x0, y1, x1, y1, color);
}

void drawTri(uint16_t x, uint16_t y, uint16_t base, uint16_t height, CRGB color) {
  drawLine(x, y, x + base, y, color);
  drawLine(x, y, x + base/2, y + height, color);
  drawLine(x + base, y, x + base/2, y + height, color);
}

void drawEllipse(uint16_t rx, uint16_t ry, uint16_t xc, uint16_t yc, CRGB color) {
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
    drawPoint(x + xc, y + yc, color);
    drawPoint(-x + xc, y + yc, color);
    drawPoint(x + xc, -y + yc, color);
    drawPoint(-x + xc, -y + yc, color);
 
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
    drawPoint(x + xc, y + yc, color);
    drawPoint(-x + xc, y + yc, color);
    drawPoint(x + xc, -y + yc, color);
    drawPoint(-x + xc, -y + yc, color);

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

void clear() {
  for(int i = 0; i < NUM_LEDS_PER_STRIP * NUM_STRIPS; i++) {
    leds[i] = 0;
  }
}

void fill(CRGB color) {
  for(int i = 0; i < NUM_LEDS_PER_STRIP * NUM_STRIPS; i++) {
    leds[i] = color;
  }
}

void drawGrayscaleBitmap(byte image[], uint16_t x, uint16_t y, uint16_t width, uint16_t height, CRGB color) {
  uint8_t currBit = 0;
  uint8_t currByte = 0;
  for(int i = 0; i < height; i++) {
    for(int j = 0; j < width; j++) {
      if(currBit == 8) {
        currByte++;
        currBit = 0;
      }
      if((image[currByte] >> (7 - currBit)) & 0x01) {
        drawPoint(x + j, y - i, color);
      }
      currBit++;
    }
  }
}

void addBuffer(uint16_t x, uint16_t y, CRGB color, uint16_t millisDuration) {
  Pixel* p = new Pixel();
  p->x = x;
  p->y = y;
  p->color = color;
  p->millisDuration = millisDuration;
  pixelBuffer.insert(pixelBuffer.begin(), p);
}

void addBuffer(uint16_t x[], uint16_t y[], CRGB color, uint16_t millisDuration, uint16_t length) {
  for(int i = 0; i < length; ++i) {
    addBuffer(x[i], y[i], color, millisDuration);
  }
}

unsigned long nextPixel = 0;

void consumeBuffer() {
  if(!pixelBuffer.empty()) {
    Pixel* p = pixelBuffer.back();
    pixelBuffer.pop_back();
    drawPoint(p->x, p->y, p->color);
    nextPixel = millis() + p->millisDuration;
    delete p;
  }
}

void drawAnimate() {
  if(millis() >= nextPixel) {
    consumeBuffer();
  }
}
