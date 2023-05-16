//
// Created by kiurow590 on 16/05/23.
//

#include "GenericWeapon.h"


GenericWeapon::GenericWeapon(std::string & img, int damage, std::string & name, std::string & description) :
    GenericEquipment( img), m_damage(damage), m_description(description), m_name(name) {}

int GenericWeapon::getDamage() {
    return m_damage;
}

void GenericWeapon::setDamage(int damage) {
    m_damage = damage;
}

std::string GenericWeapon::getDescription() {
    return m_description;
}

std::string GenericWeapon::getName() {
    return m_name;
}

