#include "club_display.h"

namespace ClubDisplay {

  //declare global variables for App here
  u16_t state = CLUB_SCROLL;
  i32_t txt_pos = 0;
  i32_t txt_delta = 1;
  u32_t flash_duration = 500;
  u64_t timer;
  u64_t delta;
  bool name_on = true;
  u32_t flash_ctr = 0;
  

  void run() {
    GFX::clear();
    timer = millis();
    delta = millis();
    txt_pos = 56;
    GFX::clear();
    while(!stopped()) {
        if(millis() - delta > (1000/FPS)) {
            GFX::clear();
            switch (state) {
                case CLUB_SCROLL:
                    GFX::drawText("Electronics Design Club", Font::font_5x7, (u16_t)txt_pos, TEXT_Y_POS, 0x265399);
                    txt_pos -= txt_delta;
                    if (txt_pos < -150) {
                        state = CLUB_FLASH;
                        timer = millis();
                        flash_ctr = 0;
                    }
                    break;
                case CLUB_FLASH:
                    if(millis() - timer >= flash_duration) {
                        if (flash_ctr >= 4) {
                            state = DEPT_SCROLL;
                            txt_pos = 56;
                        }
                        name_on = !name_on;
                        flash_ctr++;
                        timer = millis();
                    } 
                    if (name_on)
                        GFX::drawText("E-Club", Font::font_5x7, 10, TEXT_Y_POS, 0x265399);
                    
                    break;
                case DEPT_SCROLL:
                    GFX::drawText("Electrical and Computer Engineering", Font::font_5x7, (u16_t)txt_pos, TEXT_Y_POS, 0x265399);
                    txt_pos -= txt_delta;
                    if (txt_pos < -225) {
                        state = CLUB_SCROLL;
                        txt_pos = 56;
                    }
                    break;
                default:
                    state = CLUB_SCROLL;
                    txt_pos = 56;
                    break;
            }
            delta = millis();
        }
        LED::write();
    }
  }

  // return true if you want this app to stop running and return to the main menu 
  bool stopped() {
    return(Key::is_pressed(Key::ESC));
  }

}