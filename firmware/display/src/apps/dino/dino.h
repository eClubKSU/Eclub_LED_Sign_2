#ifndef DINO
#define DINO

#include <deque>
#include <string>

#include "../../types.h"
#include "../../graphics/graphics.h"
#include "../../keyboard/keyboard.h"
#include "../../bitmap/bitmaps.h"

#define GRAVITY 2
#define FPS 30

namespace Dino {

    void run();
    GFX::Bitmap* thumbnail();
    bool stopped();

}

#endif