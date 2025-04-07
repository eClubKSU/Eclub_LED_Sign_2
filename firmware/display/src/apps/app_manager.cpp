#include "app_manager.h"

//dictionary/map of the applets function pointers
std::map<String, void (*)()> apps;

char* app_names[3] = {"physics", "fireworks", "tetris"};

void appSetup() {
  //format: applet["name of applet"] = &nameofappletmainfunction
  //apps["app_name"] = &AppName::run;


  apps["physics"] = &Physics::run;
  apps["fireworks"] = &Fireworks::run;
  apps["tetris"] = &Tetris::run;
}

void cycleApps() {
  int i = 0;
  while (i<3) {
    if (!Key::is_pressed(Key::ESC)) {
      Serial.print("Starting App: ");
      Serial.println(app_names[i]);
      apps[app_names[i]]();
      i++;
    }
  }
}

void startApp(String name) {
  apps[name]();
}