#pragma once
#ifndef PROJECTREDO_ENGINE_H
#define PROJECTREDO_ENGINE_H

#include <SDL_video.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

#include "util/Bundle.h"
#include "util/GlobalConf.h"

class Engine {
private:
    Bundle render;
    Bundle input;
    Bundle worker;

    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;

public:
    Engine();

    Engine(const Engine &) = delete;

    ~Engine();

    Engine &operator=(const Engine &) = delete;
};


#endif //PROJECTREDO_ENGINE_H
