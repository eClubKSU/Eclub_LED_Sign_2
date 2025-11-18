#ifndef APPLET_MANAGER
#define APPLET_MANAGER

#include <map>

#include "../types.h"

#include "../graphics/graphics.h"

//include your app directory here(apps MUST be in the src folder(FOR SOME STUPID REASON(hours wasted)))
#include "template_app/app_name.h"
#include "ball_physics/ball_physics.h"
#include "fireworks/fireworks.h"
#include "tetris/tetris.h"
#include "line_bounce/line_bounce.h"
#include "dino/dino.h"
#include "snake/snake.h"
#include "test/test.h"
#include "pipes/pipes.h"

namespace APP {
    
    void setup();
    void menu();
    void cycle();
    void start(String name);
}


#endif