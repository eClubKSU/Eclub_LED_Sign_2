#include "src/led_driver.h"



void setup() {
    Serial.begin(9600);

    LED::set_size(56,20);

    LED::add_leds(13, 11, 0, 560, 10000000);
    LED::add_leds(27, 26, 560, 560, 10000000);

    LED::draw(0,0, 0xFF00FF);
    LED::draw(55,0, 0xFF0000);
    LED::draw(0,19, 0xFFFFFF);
    LED::draw(55,19, 0x0000FF);


    unsigned long timer = micros();
    LED::write();

    Serial.println(micros()-timer);
}

void loop() {
    // for (unsigned int i = 0; i < 1120; i++) {
    //     LED::leds[i] = 0;
    // }

    // LED::write();

    // delay(500);

    // for (unsigned int i = 0; i < 1120; i++) {
        
    //     LED::leds[i] = i % 56; 
    // }

    // LED::write();

    // delay(500);

}

