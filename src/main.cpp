#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#include "main.hpp"
#include "circle.hpp"

Main::Main():
        running(true),
        frame(0),
        ball(VIEWPORT_H / 2, VIEWPORT_H / 2)
{
}

Main::~Main() {
}

int Main::run() {
    if ( ! init()) {
        return 1;
    }

    srand(time(NULL));

    ball.velX = -4.0f + (((float) rand()) / (float) RAND_MAX) * 8.0f;
    ball.velY = -4.0f + (((float) rand()) / (float) RAND_MAX) * 8.0f;

    std::cout << "VelX: " << ball.velX << " VelY: " << ball.velY << std::endl;

    while (running) {
        process_events();
        ball.move();

        const float originX = VIEWPORT_H / 2;
        const float originY = VIEWPORT_H / 2;

        float distance;

        distance = sqrtf(pow(fabs(ball.x - originX), 2) + pow(fabs(ball.y - originY), 2));

        if (distance > ((VIEWPORT_H / 2) - ball.r)) {
            ball.velX = ball.velX * -1.0f;
            ball.velX = fmin(ball.velX * (1 + ((((float) rand()) / (float) RAND_MAX) * 0.1f)), 10);
            ball.velY = ball.velY * -1.0f;
            ball.velY = fmin(ball.velY * (1 + ((((float) rand()) / (float) RAND_MAX) * 0.1f)), 10);

            std::cout << "BOUNCE!" << std::endl;
            std::cout << "VelX: " << ball.velX << " VelY: " << ball.velY << std::endl;
        }

        draw_screen();
        flip();
    }

    clean_up();

    return 0;
}

bool Main::init() {

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Video initialization failed: %s\n", SDL_GetError());
        return false;
    }

    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_CreateWindowAndRenderer(WINDOW_W, WINDOW_H, SDL_WINDOW_OPENGL, &window, &renderer);
    SDL_SetWindowTitle(window, "OpenGL test");

    SDL_RendererInfo rendererInfo;
    SDL_GetRendererInfo(renderer, &rendererInfo);

    int expectedFlags = (SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);

    if ((rendererInfo.flags & expectedFlags) != expectedFlags) {
        fprintf(stderr, "Failed to create OpenGL context\n");
        return false;
    }

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glOrtho(0, (GLdouble) VIEWPORT_W, (GLdouble) VIEWPORT_H, 0, -1.0, 1.0);

//    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
//    glEnable(GL_BLEND);

    return true;
}

void Main::clean_up() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Main::process_events() {
    SDL_Event event;

    while(SDL_PollEvent(&event)) {
        if(event.type == SDL_QUIT) {
            running = false;
        }
        if(event.type == SDL_KEYDOWN) {
            if(event.key.keysym.mod & KMOD_ALT && event.key.keysym.sym == SDLK_F4) {
                running = false;
            }
        }
    }
}

void Main::draw_screen() {
    glMatrixMode(GL_MODELVIEW);

    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    Color red(1.0, 0.0, 0.0),
            green(0.0, 1.0, 0.0),
            blue(0.0, 0.0, 1.0),
            white(1.0, 1.0, 1.0),
            black(0.0, 0.0, 0.0);

    Color(0.5, 0.5, 0.5).commit();
    glBegin(GL_QUADS);
        glVertex3i(0, VIEWPORT_H, 0);
        glVertex3i(VIEWPORT_H, VIEWPORT_H, 0);
        glVertex3i(VIEWPORT_H, 0, 0);
        glVertex3i(0, 0, 0);
    glEnd();

    Circle circle(VIEWPORT_H / 2, VIEWPORT_H / 2, VIEWPORT_H / 2, black, black);
    circle.draw();

    ball.draw();
}

void Main::flip()
{
    if (fps.get_ticks() < FRAME_DELAY) {
        SDL_Delay(FRAME_DELAY - fps.get_ticks());
    }

    SDL_GL_SwapWindow(window);
    frame++;
}

int main(int argc, char *args[]) {
    Main main;
    main.run();
}
