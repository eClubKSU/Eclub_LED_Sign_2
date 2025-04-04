#include "example_applet_2.h"

unsigned int count2 = 0;

void example2Play() {
  while(check2Stop()) {
    clear();
    drawLine(1, 1, 10, 10, CRGB(0x040404));
    FastLED.show();
    delay(1000);
    drawLine(10, 10, 20, 10, CRGB(0x040404));
    FastLED.show();
    delay(1000);
  }
}

bool check2Stop() {
  if(count2 >= 4) {
    count2 = 0;
    return false;
  }
  else{
    count2++;
    return true;
  }
}