#ifndef DINO
#define DINO

#include <deque>
#include <string>

#include "../../types.h"
#include "../../graphics/graphics.h"
#include "../../keyboard/keyboard.h"

#define GRAVITY 2
#define FPS 30

namespace Dino {

    void run();
    bool stopped();

}

#endif