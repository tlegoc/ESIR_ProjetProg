//
// Created by theo on 17/05/23.
//

#include "GameLoose.h"

#include <rdlib/UserInterface.h>
#include <rdlib/InputManager.h>

GameLoose::GameLoose(void(*callback)()) : rdlib::Agent(), m_callback(callback) {

}

void GameLoose::update() {

    rdlib::UserInterface::addImage("assets/ui/restart.png", vec2(-0.5), vec2(2, 1));

    if (rdlib::InputManager::isKeyPressed('e')) {
        killAll();
        m_callback();
    }
}