//
// Created by theo on 12/05/23.
//

#include "rdlib/Time.h"

#include <iostream>

using namespace std::chrono;

namespace rdlib {

    high_resolution_clock::time_point Time::s_last_time = std::chrono::high_resolution_clock::now();

    float Time::getDelta() {
        // Return delta time in seconds
        return duration_cast<duration<float>>(high_resolution_clock::now() - s_last_time).count();
    }

    void Time::update() {
        s_last_time = std::chrono::high_resolution_clock::now();
    }
}