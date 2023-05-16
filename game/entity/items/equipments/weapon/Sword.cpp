//
// Created by kiurow590 on 16/05/23.
//

#include "Sword.h"

Sword::Sword( int damage, std::string  name, std::string  description) : GenericWeapon("assets/sword/1.png", damage, name, description) {

}

void Sword::use(Hero *e) {
    e->setDamage(e->getDamage() + this->getDamage());
    kill();
}




