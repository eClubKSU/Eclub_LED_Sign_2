#include "driver.h"

namespace LED {

    std::vector<Strip> strips;

    std::vector<uint32_t> leds;

    Size size;

    void set_size(uint16_t wid, uint16_t hth) {
        size.wid = wid;
        size.hth = hth;
    }


    void add_leds(uint16_t clk, uint16_t mosi, uint16_t index, uint16_t length, unsigned long speed) {

        switch (strips.size()) {
            case 0:
                SPI.setMOSI(mosi);
                SPI.setSCK(clk);
                SPI.begin(); 
                SPI.beginTransaction(SPISettings(speed, MSBFIRST, SPI_MODE3));
            break;
            case 1:
                SPI1.setMOSI(mosi);
                SPI1.setSCK(clk);
                SPI1.begin(); 
                SPI1.beginTransaction(SPISettings(speed, MSBFIRST, SPI_MODE3));
            break;
            case 2:
                SPI2.setMOSI(mosi);
                SPI2.setSCK(clk);
                SPI2.begin(); 
                SPI2.beginTransaction(SPISettings(speed, MSBFIRST, SPI_MODE3));
            break;
        }
        leds.resize(leds.size() + length);
        strips.push_back(*new Strip{index, length});
    }

    void draw(int16_t x, int16_t y, uint32_t color) {
        if (x >= 0 && x < size.wid && y >= 0 && y < size.hth) {
            leds[(y * size.wid) + (y % 2 == 0 ? (size.wid - 1 - x) : x)] = ((color & 0xFF0000) >> 16) | (color & 0x00FF00) | ((color & 0x0000FF) << 16);
        }   
    }

    void write() {
        for (unsigned int i = 0; i < strips.size(); i++) {
            switch (i) {
                case 0:
                    SPI.transfer32(0x00000000);
                    for (unsigned int j = strips[i].index; j < (strips[i].index + strips[i].length); j++) {
                        SPI.transfer32(0xFF000000 | leds[j]);
                    }
                    for (uint16_t j = 0; j < (strips[i].length + 63) >> 6; j++) {
                        SPI.transfer32(0xFFFFFFFF);
                    }    
                break;
                case 1:
                    SPI1.transfer32(0x00000000);
                    for (unsigned int j = strips[i].index; j < (strips[i].index + strips[i].length); j++) {
                        SPI1.transfer32(0xFF000000 | leds[j]);
                    }
                    for (uint16_t j = 0; j < (strips[i].length + 63) >> 6; j++) {
                        SPI1.transfer32(0xFFFFFFFF);
                    }
                break;
                case 2:
                    SPI2.transfer32(0x00000000);
                    for (unsigned int j = strips[i].index; j < (strips[i].index + strips[i].length); j++) {
                        SPI2.transfer32(0xFF000000 | leds[j]);
                    }
                    for (uint16_t j = 0; j < (strips[i].length + 63) >> 6; j++) {
                        SPI2.transfer32(0xFFFFFFFF);
                    }
                break;
            }
        }
    }
}