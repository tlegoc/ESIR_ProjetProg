//
// Created by kiurow590 on 16/05/23.
//

#include "Shield.h"


Shield::Shield(int armor, std::string  name, std::string  description) : GenericArmor("assets/Sword/Shield Pack.png", armor, name, description) {

}

void Shield::use(Hero *e) {
    if(e->getShield() + this->getArmor() < e->getMaxShield()){
        e->setShield(e->getShield() + this->getArmor());
    }
    kill();
}

