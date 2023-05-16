//
// Created by kiurow590 on 16/05/23.
//

#ifndef ESIR_PROJETPROG_GENERICARMOR_H
#define ESIR_PROJETPROG_GENERICARMOR_H


#include "../GenericEquipment.h"

class GenericArmor : public GenericEquipment{

    // class generique pour gerer les differentes armures

private :
    // Attributs
    int m_armor;
    std::string m_description;
    std::string m_name;

public:

    /**
     * @brief Constructeur de la classe GenericArmor
     * @param image  path de l'image
     * @param position  position de l'armure
     * @param isCollect  si l'armure est ramassé
     * @param angle  angle de l'armure
     * @param size  taille de l'armure
     * @param color  couleur de l'armure
     * @param armor  armure de l'armure
     * @param name  nom de l'armure
     * @param description  description de l'armure
     */
    GenericArmor(std::string  img, int armor, std::string  name, std::string  description);

    /**
     * @brief getter de m_armor
     * @return  m_armor
     */
    int getArmor();

    /**
     * @brief setter de m_armor
     * @param armor  armure de l'armure
     */
    void setArmor(int armor);

    /**
     * @brief getter de m_description
     * @return  m_description
     */
    std::string getDescription();

    /**
     * @brief getter de m_name
     * @return  m_name
     */
    std::string getName();

};


#endif //ESIR_PROJETPROG_GENERICARMOR_H
