//
// Created by theo on 15/05/23.
//

#ifndef ESIR_PROJETPROG_VISIBLEAGENT_H
#define ESIR_PROJETPROG_VISIBLEAGENT_H

#include "Agent.h"

namespace rdlib {
    class VisibleAgent : public virtual Agent {
    public:
        VisibleAgent() : Agent() {}

        virtual void render() = 0;

    private:
    };
}


#endif //ESIR_PROJETPROG_VISIBLEAGENT_H
