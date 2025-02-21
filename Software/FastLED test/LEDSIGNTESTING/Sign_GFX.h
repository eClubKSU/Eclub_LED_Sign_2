#ifndef SIGN_GFX_H
#define SIGN_GFX_H

#include <Arduino.h>
#include <FastLED.h>

#define NUM_STRIPS 2
#define NUM_LEDS_PER_STRIP 560
#define NUM_LEDS NUM_LEDS_PER_STRIP * NUM_STRIPS

extern CRGB leds[NUM_LEDS_PER_STRIP * NUM_STRIPS];

int rectToIndex(int boardX, int boardY);
void drawLine(int startX, int startY, int endX, int endY, CRGB color);
void drawRect(int x0, int y0, int x1, int y1, CRGB color);
void drawTri(int x, int y, int base, int height, CRGB color);

#endif
