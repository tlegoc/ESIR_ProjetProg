//
// Created by kiurow590 on 16/05/23.
//

#include "GenericItem.h"


GenericItem::GenericItem(const std::string &image, vec3 position, bool isCollect, float angle, vec2 size, vec3 color)
        : ColliderSpriteAgent(image, position,
                      angle, size,
                      color) , m_isCollect(isCollect){}

bool GenericItem::isCollect() const {
    return m_isCollect;
}
