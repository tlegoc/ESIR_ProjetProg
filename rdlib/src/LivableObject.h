//
// Created by theo on 10/05/2023.
//

#ifndef ESIR_PROJETPROG_LIVABLEOBJECT_H
#define ESIR_PROJETPROG_LIVABLEOBJECT_H

namespace rdlib {
    class LivableObject {
    public:
        LivableObject();
        LivableObject(const LivableObject & other) = delete;
        LivableObject(const LivableObject && other) = delete;
    };
}

#endif //ESIR_PROJETPROG_LIVABLEOBJECT_H
