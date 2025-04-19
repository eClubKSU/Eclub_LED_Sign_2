#include "graphics.h"

namespace GFX {

  std::vector<Pixel*> pixelBuffer;

  int rectToIndex(uint16_t x, uint16_t y) {
    if(x > 56 || y > 20) {
      return -1;
    }
    // find the index of the LED at Y level(alternates left and right side)
    int interY = (y * 56) - 1;
    // calculate the final index based on whether the Y index starts on the right or left which is determined by even or odd respectively
    int finalIndex = (y % 2 == 0) ? interY - (56 - x) : interY - (x - 1);
    return finalIndex;
  }

  // void drawPoint(uint16_t x, uint16_t y, uint32_t color) {
  //   int index = rectToIndex(x, y);
  //   if(index > 0) {
  //     leds[rectToIndex(x, y)] = color;
  //   }
  //   else {
  //     Serial.println("Warning: attempting to draw out of bounds");
  //   }
  // }

  void drawLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint32_t color) {
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
        LED::draw(y0, x0, color);
      } else {
        LED::draw(x0, y0, color);
      }
      err -= riseY * ystep;
      if (err < 0) {
        y0 += ystep;
        err += runX;
      }
    }
  }

  void drawRect(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint32_t color) {
    drawLine(x0, y0, x1, y0, color);
    drawLine(x0, y0, x0, y1, color);
    drawLine(x1, y0, x1, y1, color);
    drawLine(x0, y1, x1, y1, color);
  }

  void drawTri(uint16_t x, uint16_t y, uint16_t base, uint16_t height, uint32_t color) {
    drawLine(x, y, x + base, y, color);
    drawLine(x, y, x + base/2, y + height, color);
    drawLine(x + base, y, x + base/2, y + height, color);
  }

  void drawTri(uint16_t x, uint16_t y, uint16_t base, uint16_t height, uint32_t color, uint16_t orientation) {
    switch(orientation){
      case 0: // Pointing Up
        drawLine(x, y, x + base, y, color);
        drawLine(x, y, x + base/2, y + height, color);
        drawLine(x + base, y, x + base/2, y + height, color);
        break;
      case 1: // Pointing Right
        drawLine(x, y, x, y + base, color);
        drawLine(x, y, x + height, y + base/2, color);
        drawLine(x, y + base, x + height, y + base/2, color);
        break;
      case 2: // Pointing Down
        drawLine(x, y + height, x + base, y + height, color);
        drawLine(x, y + height, x + base/2, y, color);
        drawLine(x + base, y + height, x + base/2, y, color);
        break;
      case 3: // Pointing Left
        drawLine(x, y + base/2, x + height, y + base, color);
        drawLine(x + height, y + base, x + height, y, color);
        drawLine(x + height, y, x, y + base/2, color);
        break;
    }
  }

  void drawEllipse(uint16_t rx, uint16_t ry, uint16_t xc, uint16_t yc, uint32_t color) {
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
      LED::draw(x + xc, y + yc, color);
      LED::draw(-x + xc, y + yc, color);
      LED::draw(x + xc, -y + yc, color);
      LED::draw(-x + xc, -y + yc, color);
  
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
      LED::draw(x + xc, y + yc, color);
      LED::draw(-x + xc, y + yc, color);
      LED::draw(x + xc, -y + yc, color);
      LED::draw(-x + xc, -y + yc, color);

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
    uint32_t black = 0x000000;
    for(int i = 0; i < NUM_LEDS_PER_STRIP * NUM_STRIPS; i++) {
      LED::leds[i] = black;
    }
  }

  void fill(uint32_t color) {
    for(int i = 0; i < NUM_LEDS_PER_STRIP * NUM_STRIPS; i++) {
      LED::leds[i] = color;
    }
  }

  void drawText(const char* text, Bitmap* font[], uint16_t x, uint16_t y, uint32_t color) {
    uint16_t i = 0;
    uint16_t nx = x;
    while (text[i] != 0) {
      drawBitmap(font[(uint32_t)text[i]], nx, y, color);
      nx += font[(uint32_t)text[i]]->wid+1;
      i++;
    }
  }

  void drawRollingText(const char text[], Bitmap* font[], uint16_t x, uint16_t y, uint16_t width, uint16_t index, uint32_t color) {
    uint16_t str_len = 0;
    while (text[str_len] != 0) {
      str_len++;
    }

    uint16_t len = 0;
    uint16_t i = 0;
    while (len <= width) {
      len += font[(uint32_t)text[i]]->wid+1;
      i++;
    }
    char* str = (char*)malloc(i+1);
    uint16_t i_text = index;
    for (int j = 0; j < i; j++) {
      *(str+j) = text[i_text%str_len];
      i_text++;
    }
    *(str+i) = 0;
    drawText(str, font, x, y, color);
    free(str);
  }

  void drawBitmap(Bitmap* map, uint16_t x, uint16_t y, uint32_t color) {

    uint16_t mask = map->size-1;
    mask |= (mask >> 1);
    mask |= (mask >> 2);
    mask |= (mask >> 4);
    mask |= (mask >> 8);

    uint8_t shift = 0;
    uint16_t i_bit = 1;
    while (mask & i_bit) {
      shift++;
      i_bit <<= 1;
    }

    i_bit = 0;

    uint32_t buffer = *map->bitmap | (*(map->bitmap+1) << 8) | (*(map->bitmap+2) << 16) | (*(map->bitmap+3) << 24);
    uint16_t i_byte = 4;


    for(int i = 0; i < map->hth; i++) {
      for(int j = 0; j < map->wid; j++) {
        if (buffer >> i_bit & mask) {
          LED::draw(x + j, map->hth + y - i, color);
        }
        i_bit += shift;
        while (i_bit >= 8 ) {
          buffer = buffer >> 8 | (*(map->bitmap+i_byte++) << 24);
          i_bit -= 8;
        }
      }
    }
  }

  void drawBitmap(Bitmap* map, uint16_t x, uint16_t y) {
    uint16_t mask = map->size-1;
    mask |= (mask >> 1);
    mask |= (mask >> 2);
    mask |= (mask >> 4);
    mask |= (mask >> 8);

    uint8_t shift = 0;
    uint16_t i_bit = 1;
    while (mask & i_bit) {
      shift++;
      i_bit <<= 1;
    }

    i_bit = 0;

    uint32_t buffer = *map->bitmap | (*(map->bitmap+1) << 8) | (*(map->bitmap+2) << 16) | (*(map->bitmap+3) << 24);
    uint16_t i_byte = 4;


    for(int i = 0; i < map->hth; i++) {
      for(int j = 0; j < map->wid; j++) {

        LED::draw(x + j, map->hth + y - i, map->palette[buffer >> i_bit & mask]);
        i_bit += shift;
        while (i_bit >= 8 ) {
          buffer = buffer >> 8 | (*(map->bitmap+i_byte++) << 24);
          i_bit -= 8;
        }
      }
    }
  }

  void addBuffer(uint16_t x, uint16_t y, uint32_t color, uint16_t millisDuration) {
    Pixel* p = new Pixel();
    p->x = x;
    p->y = y;
    p->color = color;
    p->millisDuration = millisDuration;
    pixelBuffer.insert(pixelBuffer.begin(), p);
  }

  void addBuffer(uint16_t x[], uint16_t y[], uint32_t color, uint16_t millisDuration, uint16_t length) {
    for(int i = 0; i < length; ++i) {
      addBuffer(x[i], y[i], color, millisDuration);
    }
  }

  unsigned long nextPixel = 0;

  void consumeBuffer() {
    if(!pixelBuffer.empty()) {
      Pixel* p = pixelBuffer.back();
      pixelBuffer.pop_back();
      LED::draw(p->x, p->y, p->color);
      nextPixel = millis() + p->millisDuration;
      delete p;
    }
  }

  void drawAnimate() {
    if(millis() >= nextPixel) {
      consumeBuffer();
    }
  }

}
