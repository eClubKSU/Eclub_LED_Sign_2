#ifndef TYPES_H
#define TYPES_H

#include <cstddef>

typedef char           i8_t;
typedef unsigned char  u8_t;

typedef short          i16_t;
typedef unsigned short u16_t;

typedef int            i32_t;
typedef unsigned int   u32_t;

typedef long           i64_t;
typedef unsigned long  u64_t;

typedef float          f32_t;
typedef double         f64_t;

typedef u32_t ARGB; 
typedef u32_t RGB; 

namespace GFX {

    struct PointColor {
        i16_t x;
        i16_t y;
        ARGB color;
    };

    struct IndexColor {
        u32_t index;
        ARGB color;
    };

    struct Point {
    i16_t x;
    i16_t y;
    };

    inline bool operator==(const Point& lhs, const Point& rhs) {
        return lhs.x == rhs.x && lhs.y == rhs.y;
    }
}



#endif