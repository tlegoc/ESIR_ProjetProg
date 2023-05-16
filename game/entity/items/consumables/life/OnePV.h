//
// Created by kiurow590 on 16/05/23.
//

#ifndef ESIR_PROJETPROG_ONEPV_H
#define ESIR_PROJETPROG_ONEPV_H


#include "../GenericConsumable.h"

class OnePV : public GenericConsumable{

public :

    /**
     * Constructor of the class OnePV
     */
    OnePV();


    void update() override ;

    /**
     * Use the consumable
     * @param hero  The hero who use the consumable
     */
    void use(Agent & hero);
};


#endif //ESIR_PROJETPROG_ONEPV_H
