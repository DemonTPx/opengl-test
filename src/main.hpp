#pragma once

#include <SDL2/SDL.h>

#include "timer.h"

#define WINDOW_W 1280
#define WINDOW_H 720

#define VIEWPORT_W 1280
#define VIEWPORT_H 720

#define FRAMES_PER_SECOND 60
#define FRAME_DELAY 1000 / FRAMES_PER_SECOND

class Main {
public:
    Main();
    ~Main();

    int run();

    SDL_Window * window;
    SDL_Renderer * renderer;

    bool running;
    int frame;

    Timer fps;
private:
    bool init();
    void clean_up();

    void process_events();
    void draw_screen();

    void flip();
};
