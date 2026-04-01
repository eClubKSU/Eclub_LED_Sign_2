#include "color.h"

namespace Color {

    ARGB compose(ARGB c0, ARGB c1) {

        return ((ARGB)0x00000000);
    }


    ARGB PosEffect::get_color(i16_t x, i16_t y) {
        switch (this->ty) {
            case GRADIENT: {
                f32_t totalWeight = 0.0f;
                f32_t rSum = 0.0f, gSum = 0.0f, bSum = 0.0f;

                for (u32_t i = 0; i < this->d.gradient.size; i++) {
                    float dx = x - this->d.gradient.colors[i].x;
                    float dy = y - this->d.gradient.colors[i].y;
                    float distSq = dx * dx + dy * dy;

                    // Check if the point is exactly on one of the inputs
                    if (distSq < 1e-6) {
                        return (this->d.gradient.colors[i].c);
                    }

                    float weight = 1.0f / distSq;  // IDW with p=2
                    totalWeight += weight;
                    rSum += weight * ((this->d.gradient.colors[i].c >> 16) & 0xFF);
                    gSum += weight * ((this->d.gradient.colors[i].c >> 8) & 0xFF);
                    bSum += weight * ((this->d.gradient.colors[i].c >> 0) & 0xFF);
                }
                return(((u32_t)(rSum / totalWeight) << 16) | ((u32_t)(gSum / totalWeight) << 8) | ((u32_t)(bSum / totalWeight) << 0));

            }break;
            case RANDOM:
                return rand(this->d.random.start, this->d.random.end);
            break;
            case MASK:
            
            break;
        }
    }

    ARGB IndexEffect::get_color(u16_t index, u16_t size)  {
        switch (this->ty) {
            case GRADIENT:
                
            break;
            case EQUAL_GRADIENT:
                
            break;
            case PATTERN:
                return (*(this->d.pattern.colors + (index % this->d.pattern.size)));
            break;
            case RANDOM:
                return rand(this->d.random.start, this->d.random.end);
            break;
        }
    }

    ARGB rand(ARGB start, ARGB end) {
        u32_t a = random((start >> 24) & 0xFF, (end >> 24) & 0xFF);
        u32_t r = random((start >> 16) & 0xFF, (end >> 16) & 0xFF);
        u32_t g = random((start >> 8) & 0xFF, (end >> 8) & 0xFF);
        u32_t b = random(start & 0xFF, end & 0xFF);

        return ((ARGB)((a << 24) | (r << 16) | (g << 8) | b));
        
    }
}
