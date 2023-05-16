//
// Created by kiurow590 on 16/05/23.
//

#ifndef ESIR_PROJETPROG_GENERICITEM_H
#define ESIR_PROJETPROG_GENERICITEM_H

#include <rdlib/SpriteAgent.h>

class GenericItem : public rdlib::SpriteAgent {

private:

    bool m_isCollect;

public:
    /**
     * @brief Constructeur de l'item
     * Objectif : faire une hierarchie d'item de façon a ce que cela ce spécialise de plus en plus
     * @param image  chemin vers l'image
     * @param position  position de l'item
     * @param isCollect si l'item est collecter
     * @param angle  angle de l'item
     * @param size  taille de l'item
     * @param color  couleur de l'item
     */
    explicit GenericItem(const std::string& image, vec3 position = vec3( 0,0,0), bool isCollect = false, float angle = 0, vec2 size =vec2 ( 0.2,0.2), vec3 color = vec3(1, 1, 1));

    /**
     * Si l'item est collecter
     * @return
     */
    bool isCollect() const;
};


#endif //ESIR_PROJETPROG_GENERICITEM_H
