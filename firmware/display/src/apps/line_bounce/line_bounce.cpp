#include "line_bounce.h"

namespace LineBounce {

  //declare global variables for App here  
  GFX::Pixel* curr;
  int16_t x;
  int16_t y;
  int8_t dx;
  int8_t dy;
  CRGB color;

  void run() {
    GFX::clear();
    x = 1;
    y = 1;
    color = randomColor(16);
    dx = 1;
    dy = 1;

    while(!stopped()) {
        GFX::drawPoint(x, y, color);
        updatePixel();
        FastLED.show();
        delay(SPEED);
    }
  }

  void updatePixel() {
    if(x + dx > 56 || x + dx < 1) {
        dx *= -1;
        color = randomColor(16);
    }
    if(y + dy > 20 || y + dy < 1) {
        dy *= -1;
        color = randomColor(16);
    }
    x += dx;
    y += dy;
  }

  CRGB randomColor(uint8_t max_brightness) {
    uint32_t red = (uint32_t)random(max_brightness);
    uint32_t green = (uint32_t)random(max_brightness);
    uint32_t blue = (uint32_t)random(max_brightness);

    return CRGB((red << 16) | (green << 8) | (blue));
  }

  // return true if you want this app to stop running and return to the main menu 
  bool stopped() {
    return(Key::is_pressed(Key::ESC));
  }
}