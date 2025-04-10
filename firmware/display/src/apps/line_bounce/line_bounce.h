#ifndef LINE_BOUNCE
#define LINE_BOUNCE

#include <Arduino.h>
#include "../../graphics/graphics.h"
#include "../../keyboard/keyboard.h"

#define SPEED 100 //ms between next pixel
#define BRIGHTNESS 64

namespace LineBounce {

    void run();
    bool stopped();
    CRGB randomColor(uint8_t max_brightness);
    void updatePixel();
    void updatePixelRaw();

}

#endif