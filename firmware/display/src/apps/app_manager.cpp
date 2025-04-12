#include "app_manager.h"

//dictionary/map of the applets function pointers
std::map<String, void (*)()> apps;

void appSetup() {
  //format: applet["name of applet"] = &nameofappletmainfunction
  //apps["app_name"] = &AppName::run;


  apps["physics"] = &Physics::run;
  apps["fireworks"] = &Fireworks::run;
  apps["tetris"] = &Tetris::run;
  apps["line"] = &LineBounce::run;
  apps["dino"] = &Dino::run;
  apps["snake"] = &Snake::run;
}

void cycleApps() {
  for (auto app : apps) {
    //wait until the ESC key is released
    while (Key::is_pressed(Key::ESC)) {}

    Serial.print("Starting App: ");
    Serial.println(app.first);
    app.second();
  }
}

void startApp(String name) {
  apps[name]();
}