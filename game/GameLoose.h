//
// Created by theo on 17/05/23.
//

#ifndef ESIR_PROJETPROG_GAMELOOSE_H
#define ESIR_PROJETPROG_GAMELOOSE_H


#include <rdlib/Agent.h>

class GameLoose : rdlib::Agent {
public:
    GameLoose(void(*callback)());

    void update() override;

private:
    void(*m_callback)();
};



#endif //ESIR_PROJETPROG_GAMELOOSE_H
