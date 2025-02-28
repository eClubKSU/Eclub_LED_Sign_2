#include "Point.h"

Point* new_point(uint16_t x, uint16_t y) {
    Point* p = (Point*)malloc(sizeof(Point));
    p->x = x;
    p->y = y;
}

Point* point_swap(Point* p) {
    return new_point(p->y, p->x);
}