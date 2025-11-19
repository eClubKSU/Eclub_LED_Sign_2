# Eclub_LED_Sign_V2

In order to upload code to the teensy you must have certain packages installed on your device.
Go to https://www.pjrc.com/teensy/td_download.html and follow the instructions to install 
teensyduino to your device before uploading.

## TODO(Partially ordered, mostly thrown together): 
    1. Update apps to use new map graphics system
    2. DVD bouncing logo type App - Blaine
    3. Random Animations
    4. Interactives:
        - Tetris (potential multiplayer via widescreen?)
        - Draw your own pixel art and it displays on the screen
    5. Perlin noise generator(grayscale and rgb versions)(at gannon's request)
    6. Fluid Simulation - Zane
    7. Thumbnails for menu system
    8. Give app_manager control over app loops


## Draw Functions

```
bool draw(i16_t x, i16_t y, u32_t color);
bool draw(Point p, u32_t color);


bool draw(i16_t x, i16_t y, Bitmap map, u32_t color);
bool draw(Point p, Bitmap map, u32_t color);

bool draw(i16_t x, i16_t y, Bitmap map, u32_t palette[]);
bool draw(Point p, Bitmap map, u32_t palette[]);

bool draw(i16_t x, i16_t y, Bitmap map, ColorEffect color);
bool draw(Point p, Bitmap map, u32_t ColorEffect color);


bool draw(i16_t x, i16_t y, Point points[], u32_t color);
bool draw(Point p, Point points[], u32_t color);

bool draw(i16_t x, i16_t y, Point points[], u32_t palette[]);
bool draw(Point p, Point points[], u32_t palette[]);

bool draw(i16_t x, i16_t y, Point points[], ColorEffect color);
bool draw(Point p, Point points[], ColorEffect color);
```
