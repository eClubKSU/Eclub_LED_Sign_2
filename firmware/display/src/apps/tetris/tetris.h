#ifndef TETRIS
#define TETRIS

#include <Arduino.h>
#include "../../graphics/graphics.h"
#include "../../keyboard/keyboard.h"

namespace Tetris {

    void run();
    bool stopped();

}

#endif