//
// Created by kiurow590 on 16/05/23.
//

#ifndef ESIR_PROJETPROG_GENERICEQUIPMENT_H
#define ESIR_PROJETPROG_GENERICEQUIPMENT_H


#include "../GenericItem.h"

class GenericEquipment : public GenericItem {

public:
    /**
     * @brief Constructor of GenericEquipment
     * @param image  Path to the image of the equipment
     * @param position  Position of the equipment
     */
    GenericEquipment(const std::string &image, vec2 collider_pos, vec2 collider_size, vec3 position = vec3(0, 0, 0));




private:


};


#endif //ESIR_PROJETPROG_GENERICEQUIPMENT_H
