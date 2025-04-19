#ifndef COLOR_H
#define COLOR_H

#include "../types.h"
#include "../bitmap/bitmaps.h"

typedef u32_t ARGB; 

typedef u32_t RGB; 

namespace Color { 

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
    };

    struct ColorEffect {
        ColorEffectType ty;
        union {
            struct {
                ARGB* colors;
            };
            struct {

            };
            struct {

            };
            struct {
                GFX::Bitmap* mask;
                ARGB* palette;
            };
        };
    };

    ARGB compose(ARGB c0, ARGB c1); 

}

#endif