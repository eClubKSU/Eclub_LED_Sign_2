#ifndef APPLET_MANAGER
#define APPLET_MANAGER

#include <Arduino.h>
#include <map>

//include your app directory here(apps MUST be in the src folder(FOR SOME STUPID REASON(hours wasted)))
#include "src/example1/example_applet.h"
#include "src/example2/example_applet_2.h"
#include "src/ball_physics/ball_physics.h"

#define NUM_APPS 2

void appSetup();
void cycleApps();
void startApp(String name);

#endif