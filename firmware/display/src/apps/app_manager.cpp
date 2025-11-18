#include "app_manager.h"


namespace APP {

  struct 

  //dictionary/map of the apps function pointers
  std::map<String, void (*)()> apps; // map of apps
  std::map<String, void (*)()>::iterator it; // forward iterator through the apps list

  void setup() {

    //apps["app_name"] = &AppName::run;


    apps["physics"] = &Physics::run;
    //apps["fireworks"] = &Fireworks::run;
    //apps["tetris"] = &Tetris::run;
    apps["line"] = &LineBounce::run;
    apps["dino"] = &Dino::run;
    apps["snake"] = &Snake::run;
    //apps["test"] = &Test::run;
    apps["pipes"] = &Pipes::run;
  }

  void menu() {
    it = apps.begin();
    GFX::clear();
    GFX::drawText(it->first.c_str(), Font::font_5x7, 5, 3, 0x265399);
    LED::write();
    while(!Key::is_pressed(Key::ENTER)) {
      GFX::drawText(it->first.c_str(), Font::font_5x7, 5, 3, 0x265399);
      if(Key::is_pressed(Key::RIGHT)) {
        it++;
        if(it == apps.end()) {
          it = apps.begin();
        }
        while(Key::is_pressed(Key::RIGHT));
        GFX::clear();
      }
      else if(Key::is_pressed(Key::LEFT)) {
        if(it == apps.begin()) {
          it = std::prev(apps.end());
        }
        else {
          it--;
        }  
        while(Key::is_pressed(Key::LEFT));
        GFX::clear();
      }
      LED::write();
    }
    start(it->first);
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