#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "../types.h"
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

    void on_press(i32_t key);

    void on_release(i32_t key);

    bool is_pressed(i32_t key);

    void attach_press(i32_t key, void (*)());
    void attach_release(i32_t key, void (*)());

    void attach_press(void (*)(i32_t key));
    void attach_release(void (*)(i32_t key));

    void clear_attach();
}

#endif