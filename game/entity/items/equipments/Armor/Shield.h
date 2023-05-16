//
// Created by kiurow590 on 16/05/23.
//

#ifndef ESIR_PROJETPROG_SHIELD_H
#define ESIR_PROJETPROG_SHIELD_H


#include "GenericArmor.h"

class Shield : public GenericArmor {

public :
    /**
     * @brief Constructeur de la classe Shield
     * @param armor  armure de l'armure
     * @param name  nom de l'armure
     * @param description  description de l'armure
     */
    Shield(int armor , std::string  name, std::string  description);

    void update() override;


};


#endif //ESIR_PROJETPROG_SHIELD_H
