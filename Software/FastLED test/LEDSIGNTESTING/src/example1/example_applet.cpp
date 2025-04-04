#include "example_applet.h"

uint8_t count = 0;

void examplePlay() {
  while(checkStop()) {
    clear();
    drawRect(1, 1, 10, 10, CRGB(0x040404));
    FastLED.show();
    delay(1000);
    drawEllipse(5, 5, 10, 10, CRGB(0x040404));
    FastLED.show();
    delay(1000);
  }
}

bool checkStop() {
  if(count >= 2) {
    count = 0;
    return false;
  }
  else{
    count++;
    return true;
  }
}