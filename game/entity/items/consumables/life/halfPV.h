//
// Created by kiurow590 on 16/05/23.
//

#ifndef ESIR_PROJETPROG_HALFPV_H
#define ESIR_PROJETPROG_HALFPV_H


#include "../GenericConsumable.h"

class halfPV : public GenericConsumable {


public :

    halfPV();


    void use(Hero *hero) override;


};


#endif //ESIR_PROJETPROG_HALFPV_H
