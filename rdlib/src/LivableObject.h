//
// Created by theo on 10/05/2023.
//

#ifndef ESIR_PROJETPROG_LIVABLEOBJECT_H
#define ESIR_PROJETPROG_LIVABLEOBJECT_H

#include <vector>

namespace rdlib {
    class LivableObject {
    public:
        LivableObject();
        LivableObject(const LivableObject & other) = delete;
        LivableObject(const LivableObject && other) = delete;

    private:
        enum Status {
            ALIVE,
            DEAD
        };
        static std::vector<LivableObject *> s_objects;
    };
}

#endif //ESIR_PROJETPROG_LIVABLEOBJECT_H
