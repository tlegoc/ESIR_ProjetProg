//
// Created by kiurow590 on 16/05/23.
//

#ifndef ESIR_PROJETPROG_GENERICITEM_H
#define ESIR_PROJETPROG_GENERICITEM_H

#include <rdlib/SpriteAgent.h>
#include "rdlib/ColliderSpriteAgent.h"
#include "../character/Hero.h"


class GenericItem : public rdlib::ColliderSpriteAgent {

private:
    // Si l'item est collecté
    bool m_isCollect;

public:

    /**
     * @brief Constructeur de l'item
     * @param image  Image de l'item
     * @param position  Position de l'item
     * @param isCollect  Si l'item est collecter
     * @param angle  Angle de l'item
     * @param size  Taille de l'item
     * @param color  Couleur de l'item
     */
    explicit GenericItem(const std::string& image, vec2 collider_pos, vec2 collider_size, vec3 position = vec3( 0,0,0), bool isCollect = false, float angle = 0, vec2 size =vec2 ( .25), vec3 color = vec3(1));

    /**
     * Si l'item est collecter
     * @return Si l'item est collecter
     */
    bool isCollect() const;

    /**
     * @brief Permet de changer l'état de l'item
     * @param isCollect
     */
     void setIsCollect(bool isCollect = true);

    /**
     * @brief Permet de mettre à jour l'item
     * @param hero  Héro
     */
     virtual void use(Hero *hero) = 0;

};


#endif //ESIR_PROJETPROG_GENERICITEM_H
