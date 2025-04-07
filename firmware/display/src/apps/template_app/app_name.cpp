#include "app_name.h"

namespace AppName {

  //declare global variables for App here  

  void run() {
    while(!stopped()) {
      //do something
    }
  }

  // return true if you want this app to stop running and return to the main menu 
  bool stopped() {
    return(Key::is_pressed(Key::ESC));
  }

}