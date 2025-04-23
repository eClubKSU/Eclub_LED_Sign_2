#include "graphics.h"

namespace GFX {

  void draw(std::vector<Point> map, uint16_t x, uint16_t y, ARGB color) {
    for(unsigned int i = 0; i < map.size(); i++) {
      LED::draw(map.at(i).x + x, map.at(i).y + y, color);
    }
  }

  std::vector<Point> line(int16_t x0, int16_t y0, int16_t x1, int16_t y1) {
    std::vector<Point> map;
    bool steep = abs(y1 - y0) > abs(x1 - x0);
    int16_t inter;
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
        map.push_back({y0, x0});
      } else {
        map.push_back({x0, y0});
      }
      err -= riseY * ystep;
      if (err < 0) {
        y0 += ystep;
        err += runX;
      }
    }
    return map;
  }

  std::vector<Point> rectangle(int16_t base, int16_t height) {
    std::vector<Point> map;
    std::vector<Point> temp_line;

    temp_line = line(0, 0, base, 0);
    map.insert(map.end(), temp_line.begin(), temp_line.end());

    temp_line = line(base, 0, base, height);
    map.insert(map.end(), temp_line.begin(), temp_line.end());

    temp_line = line(base, height, 0, height);
    map.insert(map.end(), temp_line.begin(), temp_line.end());

    temp_line = line(0, height, 0, 0);
    map.insert(map.end(), temp_line.begin(), temp_line.end());


    return map;
  }

  std::vector<Point> triangle(int16_t base, int16_t height) {
    std::vector<Point> map;
    std::vector<Point> temp_line;

    temp_line = line(0, 0, base, 0);
    map.insert(map.end(), temp_line.begin(), temp_line.end());

    temp_line = line(base, 0, base/2, height);
    map.insert(map.end(), temp_line.begin(), temp_line.end());

    temp_line = line(base/2, height, 0, 0);
    map.insert(map.end(), temp_line.begin(), temp_line.end());

    return map;
  }

  std::vector<Point> triangle(int16_t base, int16_t height, uint16_t orientation) {
    std::vector<Point> map;
    std::vector<Point> temp_line;
    switch(orientation){
      case 0: // Pointing Up
        temp_line = line(0, 0, base, 0);
        map.insert(map.end(), temp_line.begin(), temp_line.end());

        temp_line = line(base, 0, base/2, height);
        map.insert(map.end(), temp_line.begin(), temp_line.end());

        temp_line = line(base/2, height, 0, 0);
        map.insert(map.end(), temp_line.begin(), temp_line.end());
        break;
      case 1: // Pointing Right
        temp_line = line(0, 0, 0, base);
        map.insert(map.end(), temp_line.begin(), temp_line.end());

        temp_line = line(0, 0, height, base/2);
        map.insert(map.end(), temp_line.begin(), temp_line.end());

        temp_line = line(0, base, height, base/2);
        map.insert(map.end(), temp_line.begin(), temp_line.end());
        break;
      case 2: // Pointing Down
        temp_line = line(0, height, base, height);
        map.insert(map.end(), temp_line.begin(), temp_line.end());

        temp_line = line(0, height, base/2, 0);
        map.insert(map.end(), temp_line.begin(), temp_line.end());

        temp_line = line(base, height, base/2, 0);
        map.insert(map.end(), temp_line.begin(), temp_line.end());
        break;
      case 3: // Pointing Left
        temp_line = line(0, base/2, height, base);
        map.insert(map.end(), temp_line.begin(), temp_line.end());

        temp_line = line(height, base, height, 0);
        map.insert(map.end(), temp_line.begin(), temp_line.end());

        temp_line = line(height, 0, 0, base/2);
        map.insert(map.end(), temp_line.begin(), temp_line.end());
        break;
    }
    return map;
  }

  std::vector<Point> ellipse(uint16_t rx, uint16_t ry) {
    std::vector<Point> map;
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
      map.push_back({x, y});
      map.push_back({-x, y});
      map.push_back({x, -y});
      map.push_back({-x, -y});

      /*
      drawPoint(x + xc, y + yc, color);
      drawPoint(-x + xc, y + yc, color);
      drawPoint(x + xc, -y + yc, color);
      drawPoint(-x + xc, -y + yc, color);
      */

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
      map.push_back({x, y});
      map.push_back({-x, y});
      map.push_back({x, -y});
      map.push_back({-x, -y});

      /*
      drawPoint(x + xc, y + yc, color);
      drawPoint(-x + xc, y + yc, color);
      drawPoint(x + xc, -y + yc, color);
      drawPoint(-x + xc, -y + yc, color);
      */

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
    return map;
  }

  void drawLine(u16_t x0, u16_t y0, u16_t x1, u16_t y1, RGB color) {
    bool steep = abs(y1 - y0) > abs(x1 - x0);
    u16_t inter;
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

    i16_t riseY = (y1 - y0);
    i16_t runX = (x1 - x0);

    i16_t err = runX / 2;
    i16_t ystep;

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

  void drawRect(u16_t x0, u16_t y0, u16_t x1, u16_t y1, RGB color) {
    drawLine(x0, y0, x1, y0, color);
    drawLine(x0, y0, x0, y1, color);
    drawLine(x1, y0, x1, y1, color);
    drawLine(x0, y1, x1, y1, color);
  }

  void drawTri(u16_t x, u16_t y, u16_t base, u16_t height, RGB color) {
    drawLine(x, y, x + base, y, color);
    drawLine(x, y, x + base/2, y + height, color);
    drawLine(x + base, y, x + base/2, y + height, color);
  }

  void drawTri(u16_t x, u16_t y, u16_t base, u16_t height, RGB color, u16_t orientation) {
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

  void drawEllipse(u16_t rx, u16_t ry, u16_t xc, u16_t yc, RGB color) {
    f32_t dx, dy, d1, d2, x, y;
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
    for(u32_t i = 0; i < LED::leds.size(); i++) {
      LED::leds[i] = 0;
    }
  }

  void fill(RGB color) {
    for(u32_t i = 0; i < LED::leds.size(); i++) {
      LED::leds[i] = color;
    }
  }

  void drawText(const char* text, Bitmap* font[], u16_t x, u16_t y, RGB color) {
    u16_t i = 0;
    u16_t nx = x;
    while (text[i] != 0) {
      drawBitmap(font[(u32_t)text[i]], nx, y, color);
      nx += font[(u32_t)text[i]]->wid+1;
      i++;
    }
  }

  void drawBitmap(Bitmap* map, u16_t x, u16_t y, RGB color) {

    u16_t mask = map->size-1;
    mask |= (mask >> 1);
    mask |= (mask >> 2);
    mask |= (mask >> 4);
    mask |= (mask >> 8);

    u8_t shift = 0;
    u16_t i_bit = 1;
    while (mask & i_bit) {
      shift++;
      i_bit <<= 1;
    }

    i_bit = 0;

    u32_t buffer = *map->bitmap | (*(map->bitmap+1) << 8) | (*(map->bitmap+2) << 16) | (*(map->bitmap+3) << 24);
    u16_t i_byte = 4;


    for(i32_t i = 0; i < map->hth; i++) {
      for(i32_t j = 0; j < map->wid; j++) {
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

  void drawBitmap(Bitmap* map, u16_t x, u16_t y) {
    u16_t mask = map->size-1;
    mask |= (mask >> 1);
    mask |= (mask >> 2);
    mask |= (mask >> 4);
    mask |= (mask >> 8);

    u8_t shift = 0;
    u16_t i_bit = 1;
    while (mask & i_bit) {
      shift++;
      i_bit <<= 1;
    }

    i_bit = 0;

    u32_t buffer = *map->bitmap | (*(map->bitmap+1) << 8) | (*(map->bitmap+2) << 16) | (*(map->bitmap+3) << 24);
    u16_t i_byte = 4;


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
}
