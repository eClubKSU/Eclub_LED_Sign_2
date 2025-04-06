#include "example_applet_2.h"

bool check2Stop();

unsigned int count2 = 0;

void play_Spritefireworks() {
  while(check2Stop()) {

    clear();
    for(int i = 0; i <= 7; i++){
      
    }
  }
}

bool checkSPStop() {
  if(count2 >= 4) {
    count2 = 0;
    return false;
  }
  else{
    count2++;
    return true;
  }
}