//
// Created by kiurow590 on 16/05/23.
//

#include "ShieldImprove.h"

ShieldImprove::ShieldImprove(int shieldImprove) : GenericConsumable( " " ),
                                                  m_shieldImprove(shieldImprove) {}

void ShieldImprove::use(Agent & hero) {
    //hero.setShield(hero.getShield() + m_shieldImprove);
    kill();
}

void ShieldImprove::update() {}


