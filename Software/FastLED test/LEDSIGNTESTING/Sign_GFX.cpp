#include "Sign_GFX.h"

int rectToIndex(int boardX, int boardY) {
  // find the index of the LED at Y level(alternates left and right side)
  int interY = (boardY * 56) - 1;
  // calculate the final index based on whether the Y index starts on the right or left which is determined by even or odd respectively
  int finalIndex = (boardY % 2 == 0) ? interY - (56 - boardX) : interY - (boardX - 1);
  return finalIndex;
}

void drawLine(int startX, int startY, int endX, int endY) {
  bool steep = abs(endY - startY) > abs(endX - startX);
  int inter;
  if (steep) {
    inter = startX;
    startX = startY;
    startY = inter;
    inter = endX;
    endX = endY;
    endY = inter;
  }

  //ensures the line is always drawn from left to right
  if (endX < startX) {
    inter = startX;
    startX = endX;
    endX = inter;
    inter = startY;
    startY = endY;
    endY = inter;
  }

  int riseY = (endY - startY);
  int runX = (endX - startX);

  int err = runX / 2;
  int ystep;

  if (startY < endY) {
    ystep = 1;
  } else {
    ystep = -1;
  }

  //draw the line procedurally from left to right
  for(; startX <= endX; startX++) {
      if (steep) {
        leds[rectToIndex(startY, startX)] = CRGB::HotPink;
      } else {
        leds[rectToIndex(startX, startY)] = CRGB::HotPink;
      }
      err -= runY;
      if (err < 0) {
        startY += ystep;
        err += runX;
      }
    }
  }
}

void drawRect(int x0, int y0, int x1, int y1) {
  
}