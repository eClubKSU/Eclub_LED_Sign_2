#ifndef PIPES
#define PIPES

#include "../../types.h"
#include "../../graphics/graphics.h"
#include "../../keyboard/keyboard.h"

namespace Pipes {

    void run(bool cycling);
    bool stopped();
    RGB randomColor();

}

#endif