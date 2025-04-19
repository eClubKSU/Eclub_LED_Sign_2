# Eclub_LED_Sign_V2

In order to upload code to the teensy you must have certain packages installed on your device.
Go to https://www.pjrc.com/teensy/td_download.html and follow the instructions to install 
teensyduino to your device before uploading.

## TODO(Partially ordered, mostly thrown together): 
    1. Store everything as a bitmap containing local positions - Blaine
    2. Objects system for making Apps/moving and colliding objects easier - Blaine
    3. DVD bouncing logo type App - Blaine
    4. Random Animations
    5. Interactives:
        - Snake - Zane
        - Tetris (potential multiplayer via widescreen?)
        - Drawn your own pixel art and it displays on the screen
        - Platformer (Chrome Dino Game)
    6. Perlin noise generator(grayscale and rgb versions)(at gannon's request)
    7. Fluid Simulation - Zane


## Draw Functions

```
bool draw(int16_t x, int16_t y, uint32_t color);
bool draw(Point p, uint32_t color);


bool draw(int16_t x, int16_t y, Bitmap map, uint32_t color);
bool draw(Point p, Bitmap map, uint32_t color);

bool draw(int16_t x, int16_t y, Bitmap map, uint32_t palette[]);
bool draw(Point p, Bitmap map, uint32_t palette[]);

bool draw(int16_t x, int16_t y, Bitmap map, ColorEffect color);
bool draw(Point p, Bitmap map, uint32_t ColorEffect color);
bool draw(int16_t x, int16_t y, Point points[], uint32_t color);
bool draw(Point p, Point points[], uint32_t color);

bool draw(int16_t x, int16_t y, Point points[], uint32_t palette[]);
bool draw(Point p, Point points[], uint32_t palette[]);

bool draw(int16_t x, int16_t y, Point points[], ColorEffect color);
bool draw(Point p, Point points[], ColorEffect color);

bool draw(int16_t x, int16_t y, Point points[], uint32_t color);
bool draw(Point p, Point points[], uint32_t color);

bool draw(int16_t x, int16_t y, Point points[], uint32_t palette[]);
bool draw(Point p, Point points[], uint32_t palette[]);

bool draw(int16_t x, int16_t y, Point points[], ColorEffect color);
bool draw(Point p, Point points[], ColorEffect color);
```
