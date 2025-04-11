#include "snake.h"
#define MAX_SNAKE_LENGTH 100

namespace Snake {

    unsigned long timer;
    bool gameOver;
    const int width = 56;
    const int height = 20;
    uint16_t x, y, tailX, tailY, score;
    uint16_t tailX[MAX_SNAKE_LENGTH], tailY[MAX_SNAKE_LENGTH];
    int nTail;
    enum Direction {Stop, Up, Down, Left, Right};
    Direction dir;

    CRGB *bitmap = (CRGB*)malloc(GFX::NUM_LEDS*sizeof(CRGB));
    GFX::ColorBitmap field = {width, height, bitmap};

    void key_pressed(int key) {
        switch (key) {
            case 'a':
            case 75: // Left arrow
                dir = Left;
                break;
            case 'd':
            case 77: // Right arrow
                dir = Right;
                break;
            case 'w':
            case 72: // Up arrow
                dir = Up;
                break;
            case 's':
            case 80: // Down arrow
                dir = Down;
                break;
            case 'x':
                gameOver = true;
                break;
        }
    }

    void Setup() {
        gameOver = false;
        dir = Stop;
        x = width / 2;
        y = height / 2;
        fruitX = rand() % width;
        fruitY = rand() % height;
        score = 0;
    }

    void Logic() {
        int prevX = tailX[0];
        int prevY = tailY[0];
        int prev2X, prev2Y;

        tailX[0] = x;
        tailY[0] = y;

        for (int i = 1; i < nTail; i++) {
            prev2X = tailX[i];
            prev2Y = tailY[i];
            tailX[i] = prevX;
            tailY[i] = prevY;
            prevX = prev2X;
            prevY = prev2Y;
        }

        switch (dir) {
        case Left:
            x--;
            break;
        case Right:
            x++;
            break;
        case Up:
            y--;
            break;
        case Down:
            y++;
            break;
        }

        // Game over if you hit wall
        if (x >= width || x < 0 || y >= height || y < 0)
            gameOver = true;

        // Game over if you hit your own tail
        for (int i = 0; i < nTail; i++)
            if (tailX[i] == x && tailY[i] == y)
                gameOver = true;

        // Eating fruit
        if (x == fruitX && y == fruitY) {
            score += 10;
            fruitX = rand() % width;
            fruitY = rand() % height;
            nTail++;
        }
    }

    void Draw() {
        for(int i = 0; i < nTail; i++){
            GRX::drawPoint(tailX[i], tailY[i], CRGB(0x00FF00));
        }
        GRX::drawPoint(fruitX, fruitY, CRGB(0xFF0000));
    }

    void run() {
        Key::attach_press(key_pressed);        
        while(!stopped()) {
            Setup();
            timer = millis();
            while(!gameOver) {
                if(millis() - timer >= 250){
                    GFX::clear();
                    Draw();
                    FastLED.show();
                    Logic();
                    timer = millis();
                }
            }
        }
    }

    bool stopped() {
        if (Key::is_pressed(Key::ESC)) {
            Key::clear_attach();
            return(true);
        }
        return (false);
    }
}

