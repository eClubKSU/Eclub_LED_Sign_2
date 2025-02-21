#ifndef graphics
#define graphics

#include "types.h"

bool clear(CRGB* ctx) {}

bool fill(CRGB* ctx, CRGB color) {}

bool draw_point(CRGB* ctx, CRGB color, Point p) {}

bool draw_point(CRGB* ctx, CRGB color, u16 x, u16 y) {}

bool draw_line(CRGB* ctx, CRGB color, Point p1, Point p2) {}

bool draw_rect(CRGB* ctx, CRGB color, bool fill, Point p1, Point p2) {}

bool draw_text(CRGB* ctx, CRGB color, bool wrap, char* text, Point p1, Point p2) {}

#endif