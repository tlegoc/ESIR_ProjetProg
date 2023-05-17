//
// Created by theo on 17/05/23.
//

#include "GameWin.h"

#include <rdlib/UserInterface.h>
#include <rdlib/InputManager.h>

GameWin::GameWin(void(*callback)()) : rdlib::Agent(), m_callback(callback) {

}

void GameWin::update() {

    rdlib::UserInterface::addImage("assets/ui/win.png", vec2(-0.5, 0), vec2(2, 1));

    if (rdlib::InputManager::isKeyPressed('e')) {
        killAll();
        m_callback();
    }
}