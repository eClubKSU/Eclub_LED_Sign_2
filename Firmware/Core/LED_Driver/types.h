#define u8 uint8_t
#define u16 uint16_t
#define u32 uint32_t

typedef struct Point {
    u16 x;
    u16 y;
} Point;

typedef struct Context {
    CRGB* leds;
    u16 wid;
    u16 len;
} Context;