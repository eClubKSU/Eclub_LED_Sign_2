#include "dino.h"

namespace Dino {


    struct Obstacle {
        uint16_t x;
        uint16_t y;
        GFX::Bitmap* map;
    };

    //declare global variables for Dino here  
    unsigned long delta;
    unsigned long nextObs;
    uint8_t jump_boost;
    uint16_t x;
    uint16_t y;
    uint16_t score;
    CRGB color;
    int16_t vx;
    int16_t vy;
    std::deque<Obstacle*> obstacles;

    void physics_frame();


    void physics_frame() {
        if(millis() - delta > (1000/FPS)) {
            delta = millis();
            GFX::clear();
            for(Obstacle* obs : obstacles) {
                if(obs->x - vx < 0) {
                    obstacles.pop_back();
                    score++;
                }
                else {
                    int py = y>>3;
                    if(obs->x >= 10 - obs->map->wid && obs->x <= 15) {
                        if ((py+5 >= obs->y && py <= obs->y) || (py <= obs->y+obs->map->hth && py >= obs->y)) {
                            y = 0;
                            vy = 0;
                            obstacles.clear();
                            GFX::clear();
                        }
                    }
                    obs->x -= vx;
                    GFX::drawBitmap(obs->map, obs->x >> 1, obs->y, CRGB(0x040404));
                }
            }
            if(Key::is_pressed(' ')) {
                if(jump_boost > 0) {
                    if(vy == 0) {
                        vy += 4;
                    }
                    vy += 4;
                    jump_boost--;
                }
            }
            if(y + vy < 1 || y + vy > 120) {
                y = y + vy > 120 ? 120 : 0;
                vy = 0;
            }
            y += vy;
            vy -= GRAVITY;
            if(y >> 3 == 0) {
                jump_boost = 5;
            }
            GFX::drawBitmap(&bitmap_Dino, x, y >> 3, color);
            FastLED.show();
        }
    }

    void run() {
        score = 0;
        x = 10;
        y = 1;
        vx = 3;
        vy = 0;
        color = CRGB(0x040404);
        delta = millis();
        jump_boost = 4;
        nextObs = millis() + random(1000) + 1000;

        while(!stopped()) {
            if(millis() > nextObs) {
                nextObs = millis() + random(1000) + 1000;
                if(random(2) == 1) {
                    Obstacle* temp = new Obstacle;
                    temp->x = 110;
                    temp->y = 0;
                    temp->map = &bitmap_Cactus;
                    obstacles.push_front(temp);
                }
                else {
                    Obstacle* temp = new Obstacle;
                    temp->x = 110;
                    temp->y = random(4, 16);
                    temp->map = &bitmap_UFO;
                    obstacles.push_front(temp);
                }
            }
            physics_frame();  
        }
    }

    // return true if you want this app to stop running and return to the main menu 
    bool stopped() {
        if (Key::is_pressed(Key::ESC)) {
            return(true);
        }
        return (false);
    }
}