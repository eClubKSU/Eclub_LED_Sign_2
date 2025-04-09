#ifndef LINE_BOUNCE
#define LINE_BOUNCE

#include <Arduino.h>
#include "../../graphics/graphics.h"
#include "../../keyboard/keyboard.h"

#define SPEED 10 //ms between next pixel

namespace LineBounce {

    void run();
    bool stopped();
    CRGB randomColor(uint8_t max_brightness);
    void updatePixel();

}

#endif