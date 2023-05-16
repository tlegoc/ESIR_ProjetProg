//
// Created by kiurow590 on 16/05/23.
//

#include "GenericEquipment.h"


GenericEquipment::GenericEquipment(const std::string &image, vec3 position, bool isCollect, float angle, vec2 size, vec3 color)
        : GenericItem(image, position,
                      isCollect, angle, size,
                      color) {}

