#include <Arduino.h>
#include <Entropy.h>

#include "src/types.h"
#include "src/graphics/graphics.h"
#include "src/apps/app_manager.h"
#include "src/keyboard/keyboard.h"
#include "src/driver/driver.h"


void setup() {
  //Initialize Serial
  Serial.begin(9600);
  //while (!Serial) {}
  Serial.println("Serial");

  //Initialize RNG
  Entropy.Initialize();
  randomSeed(Entropy.random());

  //Initialize Keyboard
  Key::setup();
  
  //Initialize LED Driver
  //set display size
  LED::set_size(56,20);
  //add SPI channels
  LED::add_leds(13, 11, 0, 560, 4000000);
  LED::add_leds(27, 26, 560, 560, 4000000);
  //clear display
  GFX::clear();
  
  LED::write();

  //Initialize Apps
  APP::setup();


  // Color::Effect ce1 = Color::Effect::gradient(new ARGB[5] {1,2,3,4,5}, 5);
  // Color::Effect ce2 = Color::Effect::pattern(new ARGB[5] {1,2,3,4,5}, 5);
  // Color::Effect ce3 = Color::Effect::random((RGB)0x000000, (RGB)0x0F0F0F);
  // Color::Effect ce4 = Color::Effect::mask(Bitmaps::Cactus, NULL);
}

void loop() {
  APP::cycle();
}

