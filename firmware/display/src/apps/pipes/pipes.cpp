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
    RGB color = 0x440889;
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
          }
        timer += 100;
        }
        LED::draw(pipeX, pipeY, color);
        LED::write();
        
      }
      if (color == 0x440889) color = 0x265399;
      else color = 0x440889;
    }
      
          /*switch(direction)
          {
            case 0: // Up
            pipeY++;
            case 1: // Right
            pipeX++;
            case 2: // Down
            pipeY--;
            case 3: // Left
            pipeX--;
          }
          if (rand() % 10 == 0)
          {
            switch(rand() % 3)
            {
              case 0:
              direction = 0;
              case 1:
              direction = 1;
              case 2:
              direction = 2;
              case 3:
              direction = 3;
            }
          }
            */
      //Randomly set the start point for new pipe
      
      //Move forward in a given direction
        //Draw point, draw point one in the direction (Do change check)
      //0.1% chance to change direction randomly (Not the same direction)
      //Once pipe reaches the edge of the screen, create a new pipe

      //ADD TIMERS
     /* if millis() - timer >= 100
      {
        //This is probably wrong lol
        //while (pipeX <= width+1 || pipeX >= 0 || pipeY >= 0 || pipeY <= height+1)
        while (!stopped())
        {
          
        }
        timer += 100;
      }
      */
  
      

    }
    // return true if you want this app to stop running and return to the main menu 
  bool stopped() {
    return(Key::is_pressed(Key::ESC));
  }
  }

  
