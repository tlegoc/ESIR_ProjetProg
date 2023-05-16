//
// Created by theo on 14/05/2023.
//

#ifndef ESIR_PROJETPROG_INCLUDE_SDL_H
#define ESIR_PROJETPROG_INCLUDE_SDL_H

//#define NO_SDL_GLEXT
#if LINUX
#include <SDL2/SDL.h>
#else
#define SDL_MAIN_HANDLED
#include <SDL.h>
#endif

#endif //ESIR_PROJETPROG_INCLUDE_SDL_H
