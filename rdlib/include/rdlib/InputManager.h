//
// Created by theo on 15/05/23.
//

#ifndef ESIR_PROJETPROG_INPUTMANAGER_H
#define ESIR_PROJETPROG_INPUTMANAGER_H

#include "Engine.h"

#include "include_sdl.h"

#include <set>

namespace rdlib {
    class InputManager {
        // singleton
    public:
        InputManager(const InputManager &) = delete;

        InputManager &operator=(const InputManager &) = delete;

        static InputManager *instanciate();

        static InputManager *getInstance();

        static void finalize();

        static std::set<char> getKeys();

        static bool isKeyPressed(char key);

    private:
        friend class Engine;

        InputManager() = default;

        ~InputManager() = default;

        static InputManager *s_instance;

        static void addKey(char key);

        static void removeKey(char key);

        static void clearKeys();

        std::set<char> m_keys;
    };

}

#endif //ESIR_PROJETPROG_INPUTMANAGER_H
