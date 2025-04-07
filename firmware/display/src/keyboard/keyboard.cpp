#include "keyboard.h"

namespace Key {
    USBHost myusb;
    USBHub hub1(myusb);
    KeyboardController keyboard1(myusb);
    USBHIDParser hid1(myusb);

    std::unordered_set<int> keys;

    void setup() {

        myusb.begin();
        keyboard1.attachPress(OnPress);
        keyboard1.attachRelease(OnRelease);
    }

    void OnPress(int key) {
        keys.insert(key);
        Serial.println(key, HEX);
    }

    void OnRelease(int key) {
        keys.erase(key);
    }

    bool is_pressed(int key) {
        return (keys.end() != keys.find(key));
    }

    bool is_pressed(char key) {
        return (keys.end() != keys.find((int)key));
    }
}