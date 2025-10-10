#ifndef COLOR_H
#define COLOR_H

#include "../types.h"
#include "../bitmap/bitmaps.h"


namespace Color { 

    struct PosEffect {
        enum PosEffectType {
            GRADIENT,
            RANDOM,
            MASK,
        } ty;
        union Data {
            struct Gradient {
                u16_t size;
                GFX::PointColor* colors;
            } gradient;
            struct Random {
                ARGB start;
                ARGB end;
            } random;
            struct Mask {
                GFX::Bitmap* mask;
                ARGB* palette;
            } mask;
        } d;

        PosEffect() {}
    
        static PosEffect gradient(GFX::PointColor* colors, u16_t size) {
            PosEffect e;
            e.ty = GRADIENT;
            e.d.gradient = {size, colors};
            return (e);
        }
        static PosEffect random(ARGB start, ARGB end) {
            PosEffect e;
            e.ty = RANDOM;
            e.d.random = {start, end}; 
            return (e);
        }
        static PosEffect mask(GFX::Bitmap* mask, ARGB* palette) {
            PosEffect e;
            e.ty = MASK;
            e.d.mask = {mask, palette}; 
            return (e);
        }

        ARGB get_color(i16_t x, i16_t y);
    };

    struct IndexEffect {
        enum IndexEffectType {
            GRADIENT,
            EQUAL_GRADIENT,
            PATTERN,
            RANDOM,
        } ty;
        union Data {
            struct Gradient {
                GFX::IndexColor* colors;
                u16_t size;
            } gradient;
            struct EqualGradient {
                ARGB* colors;
                u16_t size; 
            } equal_gradient;
            struct Pattern {
                ARGB* colors;
                u16_t size;
            } pattern;
            struct Random {
                ARGB start;
                ARGB end;
            } random;
        } d;

        IndexEffect() {}
    
        static IndexEffect gradient(GFX::IndexColor* colors, u16_t size) {
            IndexEffect e;
            e.ty = GRADIENT;
            e.d.gradient = {colors, size};
            return (e);
        }
        static IndexEffect equal_gradient(ARGB* colors, u16_t size) {
            IndexEffect e;
            e.ty = EQUAL_GRADIENT;
            e.d.equal_gradient = {colors, size};
            return (e);
        }
        static IndexEffect pattern(ARGB* colors, u16_t size) {
            IndexEffect e;
            e.ty = PATTERN;
            e.d.pattern = {colors, size}; 
            return (e);
        }
        static IndexEffect random(ARGB start, ARGB end) {
            IndexEffect e;
            e.ty = RANDOM;
            e.d.random = {start, end}; 
            return (e);
        }

        ARGB get_color(u16_t index, u16_t size);
    };

    ARGB compose(ARGB c0, ARGB c1); 

    ARGB rand(ARGB start, ARGB end);

}

#endif