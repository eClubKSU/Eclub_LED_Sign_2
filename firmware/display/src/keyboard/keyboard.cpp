#include "keyboard.h"

namespace Key {
    USBHost myusb;
    USBHub hub1(myusb);
    KeyboardController keyboard1(myusb);
    USBHIDParser hid1(myusb);

    std::unordered_set<int> keys;

    std::map<int, void (*)()> key_press_listeners;
    std::map<int, void (*)()> key_release_listeners;

    std::vector<void (*)(i32_t key)> press_listeners;
    std::vector<void (*)(i32_t key)> release_listeners;


    void setup() {

        myusb.begin();
        keyboard1.attachPress(on_press);
        keyboard1.attachRelease(on_release);
    }

    void on_press(i32_t key) {
        keys.insert(key);
        
        Serial.print("Keyboard: ");
        Serial.println(key, HEX);

        if (key_press_listeners.count(key)) {
            key_press_listeners[key]();
        }
        for(void (*fn)(i32_t key) : press_listeners) {
            fn(key);
        }
    }

    void on_release(i32_t key) {
        keys.erase(key);

        if (key_release_listeners.count(key)) {
            key_release_listeners[key]();
        }
        for(void (*fn)(i32_t key) : release_listeners) {
            fn(key);
        }
    }

    bool is_pressed(i32_t key) {
        return (keys.end() != keys.find(key));
    }

    void attach_press(i32_t key, void (*listener)()) {
        key_press_listeners[key] = listener;
    }

    void attach_release(i32_t key, void (*listener)()) {
        key_release_listeners[key] = listener;
    }

    void attach_press(void (*listener)(i32_t key) ) {
        press_listeners.push_back(listener);
    }

    void attach_release(void (*listener)(i32_t key)) {
        release_listeners.push_back(listener);
    }

    void clear_attach() {
        key_press_listeners.clear();
        key_release_listeners.clear();
        press_listeners.clear();
        release_listeners.clear();
    }
}