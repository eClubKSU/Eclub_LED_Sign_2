#include "fireworks.h"

namespace Fireworks {

  void run() {

    unsigned long timer = millis();
    int f_count = 0;

    while(!stopped()) {

      if (millis() - timer >= 500) {
          timer = millis();
          GFX::clear();
          GFX::drawBitmap(&FireworkA[f_count % 8],5,1);
          FastLED.show();
          f_count += 1;
        }
    }
  }

  bool stopped() {
    return(Key::is_pressed(Key::ESC));
  }
}