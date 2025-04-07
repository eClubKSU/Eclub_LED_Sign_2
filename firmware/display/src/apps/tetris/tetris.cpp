#include "tetris.h"

namespace Tetris {

  CRGB map[200] = {};
  GFX::ColorBitmap field = {10,20,map};

  void run() {

    while(!stopped()) {



      GFX::clear();
      GFX::drawLine(10,1,10,20, CRGB(0x0F0F0F));
      GFX::drawLine(21,1,21,20, CRGB(0x0F0F0F));

      FastLED.show();
    }
  }

  bool stopped() {
    return(Key::is_pressed(Key::ESC));
  }

}