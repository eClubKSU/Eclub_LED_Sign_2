#ifndef CLUB_DISPLAY
#define CLUB_DISPLAY

#include "../../types.h"
#include "../../graphics/graphics.h"
#include "../../keyboard/keyboard.h"

#define CLUB_SCROLL 0
#define CLUB_FLASH 1
#define DEPT_SCROLL 2

#define TEXT_Y_POS 6

#define FPS 25

namespace ClubDisplay {

    void run(bool cycling);
    bool stopped();

}

#endif