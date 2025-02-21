#include <FastLED.h>

#define u8 char
#define u16 unsigned short
#define u32 unsigned int


typedef struct Point {
    u16 x;
    u16 y;
} Point;

typedef struct Context {
    CRGB* leds;
    u16 wid;
    u16 len;
} Context;
