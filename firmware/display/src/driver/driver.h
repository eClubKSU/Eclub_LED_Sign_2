#ifndef LED_DRIVER_H
#define LED_DRIVER_H

#include <SPI.h>
#include <vector>

#include "../types.h"
#include "../graphics/color.h"



namespace LED {

    struct Strip {
        u16_t index;
        u16_t length;
    };

    struct Size {
        u16_t wid;
        u16_t hth;
    };
    
    extern std::vector<Strip> strips;

    extern std::vector<u32_t> leds;

    extern Size size;

    void set_size(u16_t wid, u16_t hth);

    void add_leds(u16_t clk, u16_t mosi, u16_t index, u16_t length, unsigned long speed);

    void draw(i16_t x, i16_t y, RGB color);

    void write();
}

#endif