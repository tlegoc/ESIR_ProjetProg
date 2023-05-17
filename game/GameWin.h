//
// Created by theo on 17/05/23.
//

#ifndef ESIR_PROJETPROG_GAMEWIN_H
#define ESIR_PROJETPROG_GAMEWIN_H

#include <rdlib/Agent.h>

class GameWin : rdlib::Agent {
public:
    GameWin(void(*callback)());

    void update() override;

private:
    void(*m_callback)();
};


#endif //ESIR_PROJETPROG_GAMEWIN_H
