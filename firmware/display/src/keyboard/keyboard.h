#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "USBHost_t36.h"
#include <unordered_set>
#include <map>
#include <vector>

namespace Key{

    enum Keys {
        ESC  =  0x1B,
        BACK =  0x7F,
        ENTER = 0x0A,
        UP = 0xDA,
        DOWN = 0xD9,
        LEFT = 0xD8,
        RIGHT = 0xD7
    };

    void setup();

    void on_press(int key);

    void on_release(int key);

    bool is_pressed(int key);

    void attach_press(int key, void (*)());
    void attach_release(int key, void (*)());

    void attach_press(void (*)(int key));
    void attach_release(void (*)(int key));

    void clear_attach();
}

#endif