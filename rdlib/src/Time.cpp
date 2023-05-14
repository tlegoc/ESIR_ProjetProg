//
// Created by theo on 12/05/23.
//

#include <rdlib/Time.h>
#include <rdlib/include_sdl.h>

#include <iostream>

using namespace std::chrono;

namespace rdlib {

    unsigned int Time::s_last_time = 0;

    float Time::getDelta() {
        // Return delta time in seconds
        return (float) (SDL_GetTicks() - s_last_time) / 1000.0f;
    }

    void Time::update() {
        s_last_time = SDL_GetTicks();
    }
}