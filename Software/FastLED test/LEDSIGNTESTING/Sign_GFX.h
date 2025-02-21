#ifndef SIGN_GFX_H
#define SIGN_GFX_H

#include <Arduino.h>
#include <FastLED.h>

int rectToIndex(int boardX, int boardY);
void drawLine(int startX, int startY, int endX, int endY);
void drawRect(int x0, int y0, int x1, int y1);

#endif
