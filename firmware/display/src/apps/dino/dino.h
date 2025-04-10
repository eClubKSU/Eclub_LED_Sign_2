#ifndef DINO
#define DINO

#include <Arduino.h>
#include <deque>
#include "../../graphics/graphics.h"
#include "../../bitmap/bitmaps.h"
#include "../../keyboard/keyboard.h"

#define GRAVITY 2
#define FPS 30

namespace Dino {

    void run();
    bool stopped();

}

#endif