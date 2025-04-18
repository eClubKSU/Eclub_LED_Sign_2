#include "color.h"

namespace Color {
    RGBA rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
        return ((RGBA)(((uint32_t)r << 24) | ((uint32_t)g << 16) | ((uint32_t)b <<  8) | (uint32_t)a ));  
    }

    RGBA rgb(uint8_t r, uint8_t g, uint8_t b) {
        return ((RGBA)(((uint32_t)r << 16) | ((uint32_t)g << 8) | (uint32_t)b ));
    }

    RGBA compose(RGBA c0, RGBA c1) {
        float a0 = get_channel(c0, ALPHA);
        float a1 = get_channel(c1, ALPHA); 

        return ((RGBA)0x00000000);
    }

    float get_channel(RGBA c, Channel chn) {
        
        uint8_t byte;
        
        switch (chn) {
            case RED:
                 byte = (c >> 24) & 0xFF;
            break;
            case BLUE:
                 byte = (c >> 16) & 0xFF;
            break;
            case GREEN:
                 byte = (c >> 8) & 0xFF;
            break;
            case ALPHA:
                 byte = c & 0xFF;
            break;
        }

        return (255 / (float)byte);
    }
}
