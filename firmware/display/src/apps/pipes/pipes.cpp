#include "pipes.h"

namespace Pipes {

  //declare global variables for App here  

  void run() {
    //Declarations
    u8_t pipeX;
    u8_t pipeY;
    u8_t direction; // 0 Up, 1 Right, 2 Down, 3 Left
    GFX::clear();
    while(!stopped()) {
      start = random(3);

      //Set the start point
      if (random == 0) // X
      {
        pipeX = rand() % (width+1);
        pipeY = 0;
      }
      else // Y
      {
        fruitY = rand() % (height+1);
        pipeX = 0;
        
      }
      
      
      LED::write();

    }
  }

  // return true if you want this app to stop running and return to the main menu 
  bool stopped() {
    return(Key::is_pressed(Key::ESC));
  }

}