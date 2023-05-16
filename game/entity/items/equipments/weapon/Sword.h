//
// Created by kiurow590 on 16/05/23.
//

#ifndef ESIR_PROJETPROG_SWORD_H
#define ESIR_PROJETPROG_SWORD_H


#include "GenericWeapon.h"

class Sword : public GenericWeapon {

public :

    /**
     * @brief Constructeur de la classe Sword
     * @param damage  degats de l'arme
     * @param name  nom de l'arme
     * @param description  description de l'arme
     */
    Sword(int damage , std::string  name, std::string  description);

    void update() override;

};


#endif //ESIR_PROJETPROG_SWORD_H
