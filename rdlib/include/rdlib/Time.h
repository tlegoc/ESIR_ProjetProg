//
// Created by theo on 12/05/23.
//

#ifndef ESIR_PROJETPROG_TIME_H
#define ESIR_PROJETPROG_TIME_H

#include "Engine.h"
#include <chrono>

namespace rdlib {
    class Time {
    public:
        Time() = delete;

        Time(const Time &other) = delete;

        Time &operator=(const Time &other) = delete;

        static float getDelta();

    private:
        friend Engine;

        static void update();

        static unsigned int s_last_time;
    };
} // rdlib

#endif //ESIR_PROJETPROG_TIME_H
