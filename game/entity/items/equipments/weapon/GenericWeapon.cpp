//
// Created by kiurow590 on 16/05/23.
//

#include "GenericWeapon.h"


GenericWeapon::GenericWeapon(const std::string &image, vec3 position, bool isCollect, float angle, vec2 size,
                             vec3 color, int damage, std::string & name, std::string & description) : GenericEquipment(
                                     image, position, isCollect, angle, size, color), m_damage(damage), m_description(description), m_name(name) {}

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

