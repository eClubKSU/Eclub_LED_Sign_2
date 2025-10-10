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




  // Color::IndexEffect ce1 = Color::IndexEffect::pattern(new ARGB[6] {0xFF0000, 0xFFA500, 0xFFFF00, 0x00FF00, 0x0000FF, 0xFF00FF}, 6);
  // Color::PosEffect ce2 = Color::PosEffect::random(0x000000, 0x0F0F0F);

  // Color::PosEffect ce3 = Color::PosEffect::gradient(new GFX::PointColor[4] {{3,3,0xFF00FF}, {-3,-3,0xFF0000},{-4,3,0x0000FF}, {10,10,0x00FF00}}, 4);

  // GFX::draw(GFX::ellipse(9,9), 10,9, ce3);

  // GFX::draw(GFX::rectangle(10,10), 20,4, ce3);

  // LED::write();

  delay(1000);
}

void loop() {
  APP::cycle();
}

