//
// Created by Thibault on 16/05/2023.
//

#include <rdlib/SpriteAgent.h>
#include "hero.h"

hero::hero(const std::string &image, vec3 position, float angle,
     vec2 size, vec3 color, int pv): rdlib::SpriteAgent(image, position, angle, size, color), m_pv(20){



}
