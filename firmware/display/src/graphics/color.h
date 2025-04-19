#ifndef COLOR_H
#define COLOR_H

#include <Arduino.h>
#include "../bitmap/bitmaps.h"

namespace Color {

    typedef uint32_t ARGB; 

    typedef uint32_t RGB; 

    enum Channel {
        RED = 0,
        GREEN = 1,
        BLUE = 2,
        ALPHA = 3,
    };

    enum ColorEffectType {
        GRADIENT,
        PATTERN,
        RANDOM,
        MASK,

    }

    struct ColorEffect {
        ColorEffectType ty;
        union {
            struct c_Gradient {
                ARGB* colors;
            };
            struct c_Pattern {

            };
            struct c_Random {

            };
            struct c_Mask {
                *GFX::Bitmap mask;
                ARGB* palette;
            }
        };
    };

    uint32_t compose(ARGB c0, ARGB c1); 


}

#endif