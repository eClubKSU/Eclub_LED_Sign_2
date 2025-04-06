#ifndef APPLET_MANAGER
#define APPLET_MANAGER

#include <Arduino.h>
#include <map>

//include your app directory here(apps MUST be in the src folder(FOR SOME STUPID REASON(hours wasted)))
#include "src/template_app/app_name.h"
#include "src/ball_physics/ball_physics.h"
#include "src/fireworks/fireworks.h"

void appSetup();
void cycleApps();
void startApp(String name);

#endif