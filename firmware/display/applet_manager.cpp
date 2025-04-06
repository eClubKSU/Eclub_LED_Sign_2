#include "applet_manager.h"

//dictionary/map of the applets function pointers
std::map<String, void (*)()> apps;

void appSetup() {
  //format: applet["name of applet"] = &nameofappletmainfunction
  apps["app_name"] = &AppName::run;


  apps["physics"] = &Physics::run;
  apps["fireworks"] = &Fireworks::run;
}

void cycleApps() {
  for (auto app : apps) {
    app.second();
  }
}

void startApp(String name) {
  apps[name]();
}