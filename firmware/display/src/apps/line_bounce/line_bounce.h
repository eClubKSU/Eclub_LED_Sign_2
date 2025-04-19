#ifndef LINE_BOUNCE
#define LINE_BOUNCE

#include <Arduino.h>
#include "../../graphics/graphics.h"
#include "../../keyboard/keyboard.h"

#define SPEED 10 //ms between next pixel
#define BRIGHTNESS 64

namespace LineBounce {

    void run();
    bool stopped();
    uint32_t randomColor(uint8_t max_brightness);
    void updatePixel();
    void updatePixelRaw();

}

#endif