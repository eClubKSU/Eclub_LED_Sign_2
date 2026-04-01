#include "app_manager.h"


namespace APP {

  // Dictionary with Arduino 
  std::map<String, App> apps; // map of apps
  std::map<String, App>::iterator it; // forward iterator through the apps list

  void setup() {

    //apps["app_name"] = {&AppName::run, &AppName::thumbnail}; or {&AppName::run, nullptr}; if no thumbnail


    apps["physics"] = {&Physics::run, nullptr};
    //apps["fireworks"] = &Fireworks::run;
    //apps["tetris"] = &Tetris::run;
    apps["line"] = {&LineBounce::run, nullptr};
    apps["dino"] = {&Dino::run, &Dino::thumbnail};
    apps["snake"] = {&Snake::run, nullptr};
    //apps["test"] = &Test::run;
    apps["pipes"] = {&Pipes::run, nullptr};
  }

  void menu() {
    // Set the iterator to the start of the map
    it = apps.begin();
    // Setup the basic menu
    GFX::clear();
    // if there is no thumbnail just print the name of the app, else show thumbnail
    if (apps[it->first].thumbnail == nullptr)
      GFX::drawText(it->first.c_str(), Font::font_5x7, 0, 0, 0x265399);
    else
      GFX::drawBitmap(apps[it->first].thumbnail(), 0, 0);
    LED::write();
    // Allow cycling through app names until the user decides to start the current app with ENTER
    while(!Key::is_pressed(Key::ENTER)) {
      if (apps[it->first].thumbnail == nullptr)
        GFX::drawText(it->first.c_str(), Font::font_5x7, 0, 0, 0x265399);
      else
        GFX::drawBitmap(apps[it->first].thumbnail(), 0, 0);
      if(Key::is_pressed(Key::RIGHT)) {
        it++;
        if(it == apps.end()) {
          it = apps.begin();
        }
        while(Key::is_pressed(Key::RIGHT)); // Buffer to wait for button release
        GFX::clear();
      }
      else if(Key::is_pressed(Key::LEFT)) {
        if(it == apps.begin()) {
          // apps.end() grabs the iterator in the spot AFTER the final piece and "it--;" is unsafe in this instance
          it = std::prev(apps.end()); 
        }
        else {
          it--;
        }  
        while(Key::is_pressed(Key::LEFT)); // Buffer to wait for button release
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
    apps[name].run();
  }
}