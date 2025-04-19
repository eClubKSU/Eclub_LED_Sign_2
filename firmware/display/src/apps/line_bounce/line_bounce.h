#ifndef LINE_BOUNCE
#define LINE_BOUNCE

#include "../../types.h"
#include "../../graphics/graphics.h"
#include "../../keyboard/keyboard.h"

#define SPEED 10 //ms between next pixel
#define BRIGHTNESS 64

namespace LineBounce {

    void run();
    bool stopped();
    RGB randomColor(u8_t max_brightness);
    void updatePixel();
    void updatePixelRaw();

}

#endif