#ifndef SNAKE
#define SNAKE

#include <Arduino.h>
#include "../../graphics/graphics.h"
#include "../../keyboard/keyboard.h"
#include "../../bitmap/bitmaps.h"
#include <deque>
#include <algorithm>

namespace Snake {

    void key_pressed(int key);
    void scoreString();
    void spawnFruit();
    void Setup();
    void Logic();
    void Draw();
    void run();
    bool stopped();

}

#endif