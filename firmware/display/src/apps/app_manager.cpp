#include "app_manager.h"


namespace APP {

  //dictionary/map of the applets function pointers
  std::map<String, void (*)()> apps;

  void setup() {

    //apps["app_name"] = &AppName::run;


    apps["physics"] = &Physics::run;
    //apps["fireworks"] = &Fireworks::run;
    //apps["tetris"] = &Tetris::run;
    apps["line"] = &LineBounce::run;
    apps["dino"] = &Dino::run;
    apps["snake"] = &Snake::run;
    apps["test"] = &Test::run;
  }

  void cycle() {
    for (auto app : apps) {
      //wait until the ESC key is released
      while (Key::is_pressed(Key::ESC)) {}

      start(app.first);
    }
  }

  void start(String name) {
    Serial.print("Starting App: ");
    Serial.println(name);
    apps[name]();
  }
}