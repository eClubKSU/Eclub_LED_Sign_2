#include "src/graphics/graphics.h"
#include "src/apps/app_manager.h"
#include "src/bitmap/bitmaps.h"
#include "src/keyboard/keyboard.h"
#include "src/driver/driver.h"
#include <cmath>
#include <vector>
#include <Entropy.h>




// For mirroring strips, all the "special" stuff happens just in setup.  We
// just addLeds multiple times, once for each strip
void setup() {
  Entropy.Initialize();
  randomSeed(Entropy.random());
  Serial.begin(9600);
  Serial.println("Serial");

  LED::set_size(56,20);

  LED::add_leds(13, 11, 0, 560, 8000000);
  LED::add_leds(27, 26, 560, 560, 8000000);

  GFX::clear();
  LED::write();

  Key::setup();

  appSetup();

}

void loop() {
  cycleApps();
}

