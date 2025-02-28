#ifndef Point
#define Point

typedef struct Point {
    uint16_t x;
    uint16_t y;
} Point;

Point new_point(uint16_t x, uint16_t y);

#endif