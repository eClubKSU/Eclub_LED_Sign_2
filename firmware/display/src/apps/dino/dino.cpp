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
    char scoreText[3];
    bool gameover;
    uint8_t difficulty;
    uint8_t jump_boost;
    uint16_t x;
    uint16_t y;
    uint16_t score;
    CRGB color;
    int16_t vx;
    int16_t vy;
    std::deque<Obstacle*> obstacles;

    void score_frame();
    void scoreString();
    void physics_frame();
    void spawn();
    void setup();

    void setup() {
        GFX::clear();
        gameover = false;
        difficulty = 0;
        score = 0;
        x = 10;
        y = 1;
        vx = 3;
        vy = 0;
        color = CRGB(0x990099);
        delta = millis();
        jump_boost = 4;
        nextObs = millis() + random(1000) + 1000;
        Serial.println("setup");
        GFX::drawText("Dino Game", Font, 3, 12, CRGB(0x265399));
        GFX::drawText("Hit Space", Font, 3, 3, CRGB(0x265399));
        GFX::drawBitmap(&bitmap_Dino, 27, 12, color);
        GFX::drawBitmap(&bitmap_Cactus, 20, 3, CRGB(0x009900));
        
        FastLED.show();
        while(Key::is_pressed(' ') && !Key::is_pressed(Key::ESC));
        while(!Key::is_pressed(' ') && !Key::is_pressed(Key::ESC));
    }

    void score_frame() {
        GFX::clear();
        scoreString();
        GFX::drawText("Score:", Font, 3, 7, CRGB(0x265399));
        GFX::drawText(scoreText, Font, 38, 7, CRGB(0x265399));
        FastLED.show();
        Serial.println("score");
        while(Key::is_pressed(' ') && !Key::is_pressed(Key::ESC));
        while(!Key::is_pressed(' ') && !Key::is_pressed(Key::ESC));
        setup();
    }

    void scoreString() {
        uint16_t hundreds = score / 100;
        uint16_t tens = (score/10)%10;
        uint16_t ones = score%10;
        scoreText[0] = (char)(hundreds + '0');
        scoreText[1] = (char)(tens + '0');
        scoreText[2] = (char)(ones + '0');
    }

    void spawn() {
        if(millis() > nextObs) {
            nextObs = millis() + random(1000) + 1000 - difficulty;
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
            difficulty += 1;
            if(difficulty % 5 == 0) {
                vx += 1;
            }
        }
    }

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
                    if(obs->x > 10 - obs->map->wid && obs->x < 15) {
                        if ((py+5 > obs->y && py <= obs->y) || (py <= obs->y+obs->map->hth && py >= obs->y)) {
                            y = 0;
                            vy = 0;
                            Serial.println("Gameover");
                            gameover = true;
                            obstacles.clear();
                            GFX::clear();
                        }
                    }
                    obs->x -= vx;
                    if(obs->map->wid == 5) {
                        GFX::drawBitmap(obs->map, obs->x >> 1, obs->y, CRGB(0x009900));
                    }
                    else {
                        GFX::drawBitmap(obs->map, obs->x >> 1, obs->y, CRGB(0x265399));
                    }
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
        setup();
        while(!stopped()) {
            if(!gameover) {
                spawn();
                physics_frame();  
            }
            else {
                score_frame();
            }
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