#pragma once

#include <SDL2/SDL.h>

#include "timer.h"

#define WINDOW_W 1280
#define WINDOW_H 720

#define VIEWPORT_W 1280
#define VIEWPORT_H 720

#define FRAMES_PER_SECOND 60

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
    Uint32 frame_delay;
private:
    bool init();
    void clean_up();

    void process_events();
    void draw_screen();

    void flip();
};
