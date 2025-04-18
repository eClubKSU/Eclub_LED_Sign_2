#ifndef LED_DRIVER_H
#define LED_DRIVER_H

#include <Arduino.h>
#include <SPI.h>
#include <vector>


namespace LED {

    struct Strip {
        uint16_t index;
        uint16_t length;
    };

    struct Size {
        uint16_t wid;
        uint16_t hth;
    };
    
    extern std::vector<Strip> strips;

    extern std::vector<uint32_t> leds;

    extern Size size;

    void set_size(uint16_t wid, uint16_t hth);

    void add_leds(uint16_t clk, uint16_t mosi, uint16_t index, uint16_t length, unsigned long speed);

    void draw(int16_t x, int16_t y, uint32_t color);

    void write();
}

#endif