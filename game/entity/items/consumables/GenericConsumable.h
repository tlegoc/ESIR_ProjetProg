//
// Created by kiurow590 on 16/05/23.
//

#ifndef ESIR_PROJETPROG_GENERICCONSUMABLE_H
#define ESIR_PROJETPROG_GENERICCONSUMABLE_H


#include "../GenericItem.h"

class GenericConsumable : public GenericItem{

public:

    /**
     * @brief Constructeur de la classe GenericConsumable
     * @param image  Chemin vers l'image du consommable
     * @param position  Position du consommable
     */
    GenericConsumable(const std::string &image, vec3 position = vec3(0, 0, 0));

    virtual void use(Hero *hero) = 0;
};


#endif //ESIR_PROJETPROG_GENERICCONSUMABLE_H
