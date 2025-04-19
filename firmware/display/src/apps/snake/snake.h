#ifndef SNAKE
#define SNAKE

#include <deque>

#include "../../types.h"
#include "../../graphics/graphics.h"
#include "../../keyboard/keyboard.h"

namespace Snake {

    void key_pressed(i32_t key);
    void scoreString();
    void spawnFruit();
    void Setup();
    void Logic();
    void Draw();
    void run();
    bool stopped();

}

#endif