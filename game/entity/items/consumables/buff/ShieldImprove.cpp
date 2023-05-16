//
// Created by kiurow590 on 16/05/23.
//

#include "ShieldImprove.h"

ShieldImprove::ShieldImprove(int shieldImprove) : GenericConsumable( " " ),
                                                  m_shieldImprove(shieldImprove) {}

void ShieldImprove::use(Hero & hero) {
    if(hero.getMShield() + m_shieldImprove < hero.getMMaxShield()){
        hero.setMShield(hero.getMShield() + m_shieldImprove);
    }
    kill();
}


