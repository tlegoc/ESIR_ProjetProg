//
// Created by kiurow590 on 16/05/23.
//

#include "Shield.h"


Shield::Shield(int armor, std::string  name, std::string  description) : GenericArmor("assets/Sword/Shield Pack.png", armor, name, description) {

}

void Shield::use(Hero & e) {
    if(e.getMShield() + this->getArmor() < e.getMMaxShield()){
        e.setMShield(e.getMShield() + this->getArmor());
    }
    kill();
}

