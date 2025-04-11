#ifndef SNAKE
#define SNAKE

#include <Arduino.h>
#include "../../graphics/graphics.h"
#include "../../keyboard/keyboard.h"
#include <list>

namespace Snake {

    void key_pressed(int key);
    void Setup();
    void Logic();
    void Draw();
    void run();
    bool stopped();

}

#endif