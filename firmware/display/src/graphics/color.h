#ifndef COLOR_H
#define COLOR_H

#include <Arduino.h>
#include "../driver/driver.h"

namespace Color {

    enum Channel {
        RED = 0,
        GREEN = 1,
        BLUE = 2,
        ALPHA = 3,
    };

    using RGBA = uint32_t;

    using RGB = uint32_t;

    RGBA rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
    RGBA* palette_gen();  

    RGBA rgb(uint8_t r, uint8_t g, uint8_t b);

    RGB compose(RGBA c0, RGBA c1);

    float get_channel(RGBA c, Channel chn);  
}

#endif