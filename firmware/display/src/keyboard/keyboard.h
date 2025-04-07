#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "USBHost_t36.h"
#include <unordered_set>

namespace Key{

    enum Keys {
        ESC  =  0x1B,
        BACK =  0x7F,
        Enter = 0x0A,
    };

    void setup();

    void OnPress(int key);

    void OnRelease(int key);

    bool is_pressed(int key);
    bool is_pressed(char key);
}

#endif