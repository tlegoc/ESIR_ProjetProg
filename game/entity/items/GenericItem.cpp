//
// Created by kiurow590 on 16/05/23.
//

#include "GenericItem.h"


GenericItem::GenericItem(const std::string &image, vec2 collider_pos, vec2 collider_size, vec3 position, bool isCollect,
                         float angle, vec2 size, vec3 color)
        : ColliderSpriteAgent(image,
                              collider_pos, collider_size,
                              position,
                              angle, size,
                              color), m_isCollect(isCollect) {
    setPassthrough(true);
}

bool GenericItem::isCollect() const {
    return m_isCollect;
}


void GenericItem::setIsCollect(bool isCollect){
    m_isCollect = isCollect;
}



