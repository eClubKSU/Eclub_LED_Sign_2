#ifndef draw
#define draw

#include <FastLED.h>

typedef struct draw {
    uint32_t pixel; //index
    CRGB color;
    uint32_t animation;
} draw;

void animate(draw** animationBuffer);

#endif