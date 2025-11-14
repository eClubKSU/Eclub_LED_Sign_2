#include "pipes.h"

namespace Pipes {
  //declare global variables for App here  
  const u16_t width = 55;
  const u16_t height = 19;
  void run() {
    //Declarations
    u8_t pipeX = 0;
    u8_t pipeY = 0;
    u8_t direction = 0; // 0 Up, 1 Right, 2 Down, 3 Left
    u32_t timer = millis();
    RGB color = GFX::randomColor();
    GFX::clear();
    while(!stopped()) 
    {
      switch(rand() % 4)
        {
          case 0: //North
          pipeX = rand() % (width);
          pipeY = height;
          direction = 2;
          break;
          case 1: //East
          pipeX = width;
          pipeY = rand() % (height);
          direction = 3;
          break;
          case 2: //South
          pipeX = rand() % (width);
          pipeY = 0;
          direction = 0;
          break;
          case 3: //West
          pipeX = 0;
          pipeY = rand() % (height);
          direction = 1;
          break;
        }
      
      //for (int i = 0; i < 50; i++)
      while (pipeX <= width && pipeX >= 0 && pipeY >= 0 && pipeY <= height && !stopped())
      {
        if (millis() - timer >= 100)
        {
          switch(direction)
          {
            case 0: // Up
            pipeY++;
            break;
            case 1: // Right
            pipeX++;
            break;
            case 2: // Down
            pipeY--;
            break;
            case 3: // Left
            pipeX--;
            break;
          }
          if (rand() % 10 == 0)
          {
            u8_t oldDirection = direction;
            
            do{
              switch(rand() % 3)
              {
                case 0:
                direction = 0;
                break;
                case 1:
                direction = 1;
                break;
                case 2:
                direction = 2;
                break;
                case 3:
                direction = 3;
                break;
              }
            }while (direction == (oldDirection+2)%4);             
          }
        timer += 100;
        }
        
        LED::draw(pipeX, pipeY, color);
        LED::write();
        
      }
      //if (color == 0x440889) color = 0x265399;
      //else color = 0x440889;
      color = GFX::randomColor();
    }
  }

    // return true if you want this app to stop running and return to the main menu 
  bool stopped() {
    return(Key::is_pressed(Key::ESC));
  }
}
  
