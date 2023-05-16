//
// Created by kiurow590 on 16/05/23.
//

#include "GenericArmor.h"

GenericArmor::GenericArmor(std::string img, int armor, std::string name, std::string description) : GenericEquipment(img), m_armor(armor), m_description(description), m_name(name) {}

int GenericArmor::getArmor() {
    return m_armor;
}

void GenericArmor::setArmor(int armor) {
    m_armor = armor;
}

std::string GenericArmor::getDescription() {
    return m_description;
}

std::string GenericArmor::getName() {
    return m_name;
}

