#include "Engine.h"

Engine::Engine() :
        render("Renderer"),
        input("Input Handler"),
        worker("Worker") {

    if (SDL_Init(GameConf::SDL_INIT) != 0)
        spdlog::critical("SDL failed to initialize one or more required subsystem:\n\t{}", SDL_GetError());
    else
        spdlog::trace("SDL initialized all required subsystem.");

    window = SDL_CreateWindow(
            GameConf::NAME.c_str(),
            SDL_WINDOWPOS_CENTERED, //TODO: Allow specifying a display. Need to implement a runtime configuration
            SDL_WINDOWPOS_CENTERED, //      in addition to the static compile time configuration
            1366,
            768,
            0);

    if (!window)
        spdlog::critical("SDL failed to create window:\n\t{}", SDL_GetError());
    else
        spdlog::trace("SDL successfully created window.");

    renderer = SDL_CreateRenderer(window, -1, 0); //Create renderer with a preference toward hardware
    // accelerated options.
    // https://wiki.libsdl.org/SDL2/SDL_RendererFlags

    if (!renderer)
        spdlog::critical("SDL failed to initialize renderer:\n\t{}", SDL_GetError());
    else
        spdlog::trace("SDL successfully initialized renderer.");

    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

Engine::~Engine() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
