#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#include "main.hpp"
#include "circle.hpp"

Main::Main():
        running(true),
        frame(0)
{
}

Main::~Main() {
}

int Main::run() {
    if ( ! init()) {
        return 1;
    }

    while (running) {
        process_events();
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
    glOrtho(0, (GLdouble) VIEWPORT_W, (GLdouble) VIEWPORT_H, 0, -0.1, 0.1);

    glBlendFunc(GL_SRC_ALPHA,GL_ONE);
    glEnable(GL_BLEND);

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

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
        glVertex3i(100, 200, 0);
        glVertex3i(200, 200, 0);
        glVertex3i(200, 100, 0);
        glVertex3i(100, 100, 0);
    glEnd();

    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_TRIANGLES);
        glVertex3i(500, 500, 0);
        glVertex3i(500, 400, 0);
        glVertex3i(400, 400, 0);
    glEnd();

    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINES);
        glVertex3i(100, 500, 0);
        glVertex3i(200, 500, 0);
        glVertex3i(200, 500, 0);
        glVertex3i(150, 550, 0);
        glVertex3i(150, 550, 0);
        glVertex3i(100, 500, 0);
    glEnd();

    float x = 205, y = 100, r = 100;
    x = x + (int) (sin((double) frame / 50) * 50);

    Circle circle(x, y, r, 50);
    circle.draw();
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
