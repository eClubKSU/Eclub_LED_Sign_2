#ifndef APPLET_MANAGER
#define APPLET_MANAGER

#include <Arduino.h>
#include <map>

//include your app directory here(apps MUST be in the src folder(FOR SOME STUPID REASON(hours wasted)))
#include "template_app/app_name.h"
#include "ball_physics/ball_physics.h"
#include "fireworks/fireworks.h"
#include "tetris/tetris.h"

void appSetup();
void cycleApps();
void startApp(String name);

#endif