#include "snake.h"
#define MAX_SNAKE_LENGTH 100

namespace Snake {

    bool gameOver;
    unsigned long timer;
    const uint16_t width = 56;
    const uint16_t height = 20;
    uint16_t x, y, score, fruitX, fruitY, ticks;
    std::deque<GFX::Point> body;
    std::deque<GFX::Point>::iterator it;
    enum Direction {Stop, Up, Down, Left, Right};
    enum GameState {Menu, Speed, Playing, Over};
    enum SnakeSpeed {Slow = 10, Medium = 20, Fast = 30};
    char scoreText[3];
    Direction dir;
    Direction lastMovedDir;
    GameState gs = Menu;
    SnakeSpeed ss = Slow;

    const char* getGameStateName(GameState state) {
        switch(state) {
            case Menu: return "Menu";
            case Speed: return "Speed";
            case Playing: return "Playing";
            case Over: return "Over";
            default: return "Unknown";
        }
    }


    void key_pressed(int key) {
        switch (key) {
            case 'a':
            case Key::Keys::LEFT: // Left arrow
                switch(gs){
                    case Speed:
                        if(ss == Medium){
                            ss = Slow;
                        } else if (ss == Fast) {
                            ss = Medium;
                        }
                        break;
                    case Playing:
                        if(lastMovedDir != Right){
                            dir = Left;
                        }
                        break;
                }
                break;
            case 'd':
            case Key::Keys::RIGHT: // Right arrow
                switch(gs){
                    case Speed:
                        if(ss == Slow){
                            ss = Medium;
                        } else if (ss == Medium) {
                            ss = Fast;
                        }
                        break;
                    case Playing:
                        if(lastMovedDir != Left){
                            dir = Right;
                        }
                        break;
                }
                break;
            case 'w':
            case Key::Keys::UP: // Up arrow
                if(lastMovedDir != Down){
                    dir = Up;
                }
                break;
            case 's':
            case Key::Keys::DOWN: // Down arrow
                if(lastMovedDir != Up){
                    dir = Down;
                }
                break;
            case Key::Keys::ENTER: // Enter key
                switch(gs){
                    case Menu:
                        gs = Speed;
                        break;
                    case Speed:
                        Setup();
                        gs = Playing;
                        break;
                    case Playing:
                        gs = Speed;
                        break;
                    case Over:
                        gs = Speed;
                        break;
                }
                Serial.print("The Game State is ");
                Serial.println(getGameStateName(gs));
                break;
        }
    }

    void scoreString() {
        uint16_t hundreds = score / 100;
        uint16_t tens = (score/10)%10;
        uint16_t ones = score%10;
        scoreText[0] = (char)(hundreds + '0');
        scoreText[1] = (char)(tens + '0');
        scoreText[2] = (char)(ones + '0');
    }

    void spawnFruit() {
        do {
            fruitX = rand() % width;
            fruitY = rand() % height;
        } while(std::find(body.begin(), body.end(), GFX::Point{fruitX, fruitY}) != body.end());
    }

    void Setup() {
        gameOver = false;
        ticks = ss;
        dir = Stop;
        lastMovedDir = Stop;
        x = width / 2;
        y = height / 2;
        body.clear();
        body.push_front(GFX::Point {x, y});
        fruitX = rand() % width;
        fruitY = rand() % height;
        score = 0;
    }

    void Logic() {

        if (dir == Stop) return;

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

        lastMovedDir = dir;

        // Game over if you hit wall
        if (x >= width || x < 0 || y >= height || y < 0)
            gameOver = true;

        // Game over if you hit your own tail
        for (GFX::Point point : body)
            if (point.x == x && point.y == y)
                gameOver = true;

        body.push_front(GFX::Point {x, y});

        // Eating fruit
        if (x == fruitX && y == fruitY) {
            score += 1;
            spawnFruit();
        } else {
            body.pop_back();
        }
    }

    void Draw() {
        LED::draw(x, height - y, 0x00FF00);
        for(GFX::Point point : body){
            LED::draw(point.x, height - point.y, 0x00FF00);
        }
        LED::draw(fruitX, height - fruitY, 0xFF0000);
    }

    void run() {
        Key::attach_press(key_pressed);        
        while(!stopped()) {
            switch(gs){
                case Menu:
                    GFX::clear();
                    GFX::drawText("Snake!", Font::font_5x7, 4, 12, 0x0aff2e);
                    GFX::drawText("hit", Font::font_5x7, 2, 2, 0xff0a0a);
                    GFX::drawText("enter:", Font::font_5x7, 22, 2, 0xff0a0a);
                    //GFX::drawBitmap(&bitmap_Snake_Menu, 40, 10);
                    LED::write();
                    break;
                case Speed:
                    GFX::clear();
                    GFX::drawText("Pick", Font::font_5x7, 2, 12, 0x0aff2e);
                    GFX::drawText("Speed", Font::font_5x7, 27, 12, 0x0aff2e);
                    switch(ss){
                        case Slow:
                            GFX::drawText("Slow", Font::font_5x7, 18, 2, 0xFFFFFF);
                            GFX::drawTri(44, 3, 6, 6, 0xFFFFFF, 1);
                            break;
                        case Medium:
                            GFX::drawText("Medium", Font::font_5x7, 12, 2, 0xFFFFFF);
                            GFX::drawTri(49, 3, 6, 6, 0xFFFFFF, 1);
                            GFX::drawTri(2, 3, 6, 6, 0xFFFFFF, 3);
                            break;
                        case Fast:
                            GFX::drawText("Fast", Font::font_5x7, 18, 2, 0xFFFFFF);
                            GFX::drawTri(8, 3, 6, 6, 0xFFFFFF, 3);
                            break;
                    }
                    LED::write();
                    break;
                case Playing:
                    timer = millis();
                    while(!(gameOver || stopped())) {
                        if(millis() - timer >= 1000/ticks){
                            GFX::clear();
                            Draw();
                            LED::write();
                            Logic();
                            timer = millis();
                        }
                    }
                case Over:
                    GFX::clear();
                    scoreString();
                    GFX::drawText("Score:", Font::font_5x7, 3, 7, 0x265399);
                    GFX::drawText(scoreText, Font::font_5x7, 38, 7, 0x265399);
                    LED::write();
                    break;    
            }
        }
    }

    bool stopped() {
        if (Key::is_pressed(Key::ESC)) {
            Key::clear_attach();
            gs = Menu;
            return(true);
        }
        return (false);
    }
}

