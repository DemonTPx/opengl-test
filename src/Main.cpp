#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#include "Main.hpp"
#include "Circle.hpp"
#include "ActorLoader.hpp"
#include "Texture.h"
#include "ShaderProgram.hpp"

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

    auto textureContainer = Texture("./resources/image/container.jpg");
    auto textureAwesome = Texture("./resources/image/awesomeface.png");
    auto shaderArc = ShaderProgram(
            "./src/shader/arc.vert",
            "./src/shader/arc.frag",
            "./src/shader/arc.geom"
    );
    auto shaderBall = ShaderProgram(
            "./src/shader/ball.vert",
            "./src/shader/ball.frag",
            "./src/shader/ball.geom"
    );

    // setup vertices
    float vertices[] = {
            // positions
            0.0f, 0.8f, 0.0f,
            0.0f, 0.0f, 0.0f
    };

    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    unsigned int VBO;
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // positions
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);

    shaderArc.use();
    shaderArc.set1i("aTexture", 0);
    shaderArc.set1f("size", 30.0f);

    shaderBall.use();
    shaderBall.set1i("aTexture", 0);
    shaderBall.set1f("size", 0.2f);

    while (running) {
        process_events();

        glClear(GL_COLOR_BUFFER_BIT);

        shaderArc.use();
        shaderArc.set1f("angle", 30.0 * (float) SDL_GetTicks() / 1000);

        glActiveTexture(GL_TEXTURE0);
        textureContainer.bind();

        glBindVertexArray(VAO);
        glDrawArrays(GL_POINTS, 0, 1);
        glBindVertexArray(0);

        shaderBall.use();
        shaderBall.set1f("size", 0.2f + abs(cos((float) SDL_GetTicks() / 1000)) * 0.3f);

        glActiveTexture(GL_TEXTURE0);
        textureAwesome.bind();

        glBindVertexArray(VAO);
        glDrawArrays(GL_POINTS, 1, 1);
        glBindVertexArray(0);

        flip();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    clean_up();

    return 0;
}

bool Main::init() {

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Video initialization failed: %s\n", SDL_GetError());
        return false;
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

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

    glClearColor(0.2, 0.2, 0.2, 0.0);
    glMatrixMode(GL_PROJECTION);
    glOrtho(0, (GLdouble) VIEWPORT_W, (GLdouble) VIEWPORT_H, 0, -1.0, 1.0);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
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
        if (event.type == SDL_QUIT) {
            running = false;
        }
        if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_ESCAPE ||
                (event.key.keysym.mod & KMOD_ALT && event.key.keysym.sym == SDLK_F4)) {
                running = false;
            }
        }
    }
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

//    ActorLoader loader;
//    auto actor = loader.Load("resources/actor/ball.yml");
//
//    std::cout << actor->ListComponents() << std::endl;
//
//    actor->Update(100);
//
//    actor->Destroy();

    Main main;
    main.run();
}
