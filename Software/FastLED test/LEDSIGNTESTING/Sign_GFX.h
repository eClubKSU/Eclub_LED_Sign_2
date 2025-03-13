#ifndef SIGN_GFX_H
#define SIGN_GFX_H

#include <Arduino.h>
#include <FastLED.h>

#define NUM_STRIPS 2
#define NUM_LEDS_PER_STRIP 560
#define NUM_LEDS NUM_LEDS_PER_STRIP * NUM_STRIPS

extern CRGB leds[NUM_LEDS_PER_STRIP * NUM_STRIPS];

int rectToIndex(uint16_t x, uint16_t y);
void drawPoint(uint16_t x, uint16_t y, CRGB color);
void drawLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, CRGB color);
void drawRect(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, CRGB color);
void drawTri(uint16_t x, uint16_t y, uint16_t base, uint16_t height, CRGB color);
void drawEllipse(uint16_t rx, uint16_t ry, uint16_t xc, uint16_t yc, CRGB color);
void clear();
void fill(CRGB color);
void drawGrayscaleBitmap(byte image[], uint16_t x, uint16_t y, uint16_t width, uint16_t height, CRGB color);

// Blaine TODO : antiAliasing() <- maybe
void drawInstant();
void drawAnimate();

#endif
