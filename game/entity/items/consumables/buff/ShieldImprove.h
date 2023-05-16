//
// Created by kiurow590 on 16/05/23.
//

#ifndef ESIR_PROJETPROG_SHIELDIMPROVE_H
#define ESIR_PROJETPROG_SHIELDIMPROVE_H


#include "../GenericConsumable.h"

class ShieldImprove : public GenericConsumable {

    int m_shield_improve;

public:

    ShieldImprove(int shield_improve);

    void use(Hero *hero) override;

};


#endif //ESIR_PROJETPROG_SHIELDIMPROVE_H
