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


    /**
     * Use the consumable
     * @param hero  The hero who use the consumable
     */
    void use(Hero & hero) override;
};


#endif //ESIR_PROJETPROG_ONEPV_H
