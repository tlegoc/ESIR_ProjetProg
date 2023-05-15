//
// Created by theo on 15/05/23.
//

#include "rdlib/InputManager.h"

#include <iostream>

namespace rdlib {

    InputManager *InputManager::s_instance = nullptr;

    InputManager *InputManager::instanciate() {
        if (s_instance) throw std::runtime_error("An input manager instance already exists !");

        s_instance = new InputManager();

        return s_instance;
    }

    InputManager *InputManager::getInstance() {
        if (!s_instance) throw std::runtime_error("No input manager instance exists !");

        return s_instance;
    }

    void InputManager::finalize() {
        delete s_instance;
    }

    std::set<char> InputManager::getKeys() {
        return s_instance->m_keys;
    }

    bool InputManager::isKeyPressed(char key) {
        return s_instance->m_keys.find(key) != s_instance->m_keys.end();
    }

    void InputManager::addKey(char key) {
        s_instance->m_keys.insert(key);
    }

    void InputManager::removeKey(char key) {
        s_instance->m_keys.erase(key);
    }

    void InputManager::clearKeys() {
        s_instance->m_keys.clear();
    }
} // rdlib