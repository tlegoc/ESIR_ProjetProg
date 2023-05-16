//
// Created by kiurow590 on 16/05/23.
//

#ifndef ESIR_PROJETPROG_ONEHEART_H
#define ESIR_PROJETPROG_ONEHEART_H


#include "../GenericConsumable.h"

class OneHeart : public GenericConsumable {

public :

    OneHeart();

    void update() override ;

    void use(Agent & hero);


};


#endif //ESIR_PROJETPROG_ONEHEART_H