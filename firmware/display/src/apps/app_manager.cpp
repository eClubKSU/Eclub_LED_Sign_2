#include "app_manager.h"


namespace APP {

  // Dictionary with Arduino 
  std::map<String, App> apps; // map of apps
  std::map<String, App>::iterator it; // forward iterator through the apps list
  bool cycling = false;

  void setup() {

    //apps["app_name"] = {&AppName::run, &AppName::thumbnail, bool}; or {&AppName::run, nullptr, bool}; if no thumbnail
    // "bool" is true if the app is display-only. That is, does not require keyboard inputs to run. Otherwise, it is false.


    apps["physics"] = App{&Physics::run, nullptr, true};
    //apps["fireworks"] = &Fireworks::run;
    //apps["tetris"] = &Tetris::run;
    apps["line"] = App{&LineBounce::run, nullptr, true};
    apps["dino"] = App{&Dino::run, nullptr, false};
    apps["snake"] = App{&Snake::run, nullptr, false};
    //apps["test"] = &Test::run;
    apps["pipes"] = App{&Pipes::run, nullptr, true};
    apps["club disp"] = App{&ClubDisplay::run, nullptr, true};
    apps["disp cycle"] = App{&display_cycle, nullptr, false}; // disp_only is false to prevent recursion
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

  void display_cycle() {
    cycling = true;
    while(1) {
      for (auto app : apps) {
        // iterate through only display apps
        if(app.second.display_only) start(app.first);

        // allow exiting display_cycle function
        if (Key::is_pressed(Key::ESC)) {
          cycling = false;
          return;
        }
      }
    }
  }

  void start(String name) {
    Serial.print("Starting App: ");
    Serial.println(name);
    apps[name].run(cycling);
  }
}