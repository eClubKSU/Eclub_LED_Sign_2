#include "test.h"

namespace Test {

  //declare global variables for App here  

  void run() {
    GFX::clear();
    while(!stopped()) {
      //do something
      //GFX::drawTri(23, 8, 10, 10, 0x008000);
      //GFX::drawRectFill(1, 1, 6, 6, 0xFFFFFF);
      //GFX::drawRectFill(0, 0, 56, 23, 0xFFFFFF);
      LED::write();

    }
  }

  // return true if you want this app to stop running and return to the main menu 
  bool stopped() {
    return(Key::is_pressed(Key::ESC));
  }

}