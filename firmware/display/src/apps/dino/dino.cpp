#include "dino.h"

namespace Dino {


    struct Obstacle {
        u16_t x;
        u16_t y;
        GFX::Bitmap* map;
    };

    //declare global variables for Dino here  
    unsigned long delta;
    unsigned long nextObs;
    char scoreText[3];
    bool gameover;
    u8_t difficulty;
    u8_t jump_boost;
    u16_t x;
    u16_t y;
    u16_t score;
    RGB color;
    i16_t vx;
    i16_t vy;
    std::deque<Obstacle*> obstacles;

    void score_frame();
    void scoreString();
    void physics_frame();
    void spawn();
    void setup();

    void setup() {
        GFX::clear();
        // Setup variables
        gameover = false;
        difficulty = 0;
        score = 0;
        x = 10;
        y = 0;
        vx = 3;
        vy = 0;
        color = 0x990099;
        delta = millis();
        jump_boost = 4;
        nextObs = millis() + random(1000) + 1000;

        // Draw Main Menu Screen
        GFX::drawText("Dino Game", Font::font_5x7, 2, 11, 0x265399);
        GFX::drawText("Hit Space", Font::font_5x7, 2, 2, 0x265399);
        GFX::drawBitmap(Bitmaps::Dino, 26, 11, color);
        GFX::drawBitmap(Bitmaps::Cactus, 19, 2, 0x009900);
        
        LED::write();

        // Buffer so the game starts when the space bar is pressed
        while(Key::is_pressed(' ') && !Key::is_pressed(Key::ESC));
        while(!Key::is_pressed(' ') && !Key::is_pressed(Key::ESC));
    }

    void score_frame() {
        GFX::clear();
        // Convert score to a string and draw it
        scoreString();
        GFX::drawText("Score:", Font::font_5x7, 2, 6, 0x265399);
        GFX::drawText(scoreText, Font::font_5x7, 37, 6, 0x265399);
        LED::write();

        // Buffer to stay on this screen until the space bar is pressed
        while(Key::is_pressed(' ') && !Key::is_pressed(Key::ESC));
        while(!Key::is_pressed(' ') && !Key::is_pressed(Key::ESC));
        setup();
    }

    void scoreString() {
        u16_t hundreds = score / 100;
        u16_t tens = (score/10)%10;
        u16_t ones = score%10;
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
                temp->map = Bitmaps::Cactus;
                obstacles.push_front(temp);
            }
            else {
                Obstacle* temp = new Obstacle;
                temp->x = 110;
                temp->y = random(3, 15);
                temp->map = Bitmaps::UFO;
                obstacles.push_front(temp);
            }
            // Manage difficulty
            difficulty += 1;
            if(difficulty % 5 == 0) {
                vx += 1;
            }
        }
    }

    // Main game loop
    void physics_frame() {
        // Limit FPS with a timer
        if(millis() - delta > (1000/FPS)) {
            delta = millis();
            GFX::clear();
            // Iterate through the obstacles
            for(Obstacle* obs : obstacles) {
                // Delete obstacles that went off screen or update them
                if(obs->x - vx < 0) {
                    obstacles.pop_back();
                    score++;
                }
                else {
                    // player y divided by 8 for physics smoothness
                    i32_t py = y>>3;
                    // Check if obstacle is in the x range of the player for collision
                    if(obs->x > 10 - obs->map->wid && obs->x < 15) {
                        // Check if the y also matches for collision
                        if ((py+5 > obs->y && py <= obs->y) || (py <= obs->y+obs->map->hth && py >= obs->y)) {
                            y = 0;
                            vy = 0;
                            gameover = true;
                            obstacles.clear();
                            GFX::clear();
                        }
                    }
                    // Update obstacle positions
                    obs->x -= vx;
                    // Redraw the obstacle at its new position with the correct color based on which obstacle it is
                    GFX::drawBitmap(obs->map, obs->x >> 1, obs->y, obs->map->wid == 5 ? 0x009900 : 0x265399);
                }
            }
            // Jump
            if(Key::is_pressed(' ')) {
                if(jump_boost > 0) {
                    if(vy == 0) {
                        vy += 4;
                    }
                    vy += 4;
                    jump_boost--;
                }
            }
            // Keep player inside the bounds of the screen
            if(y + vy < 0 || y + vy > 119) {
                y = y + vy > 119 ? 119 : 0;
                vy = 0;
            }
            y += vy;
            vy -= GRAVITY;
            if(y >> 3 == 0) {
                jump_boost = 5;
            }
            GFX::drawBitmap(Bitmaps::Dino, x, y >> 3, color);
            LED::write();
        }
    }

    GFX::Bitmap* thumbnail() {
        return Bitmaps::Dino_Menu;
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