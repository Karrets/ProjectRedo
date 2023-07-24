#pragma once
#ifndef PROJECTREDO_GLOBALCONF_H
#define PROJECTREDO_GLOBALCONF_H

#include <SDL.h>

namespace GameConf {
    //Logger configuration
    const spdlog::level::level_enum LOG_LEVEL = spdlog::level::trace;

    //SDL configuration
    const unsigned int SDL_INIT = SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_EVENTS;

    //Game configuration
    const unsigned int WORKER_THREADS = 32;
    const std::string NAME = "Project Redo";
}

#endif //PROJECTREDO_GLOBALCONF_H
