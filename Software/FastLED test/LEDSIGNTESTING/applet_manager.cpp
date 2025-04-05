#include "applet_manager.h"

//dictionary/map of the applets function pointers
std::map<String, void (*)()> applet;

void appSetup() {
  //format: applet["name of applet"] = &nameofappletmainfunction
    applet["example1"] = &examplePlay;
    applet["example2"] = &example2Play;
    applet["ball"] = &play_ball;
}

void cycleApps() {
  applet["example1"]();
  applet["example2"]();
}

void startApp(String name) {
  applet[name]();
}