//
// Created by kiurow590 on 16/05/23.
//

#ifndef ESIR_PROJETPROG_GENERICWEAPON_H
#define ESIR_PROJETPROG_GENERICWEAPON_H


#include "../GenericEquipment.h"

class GenericWeapon : public GenericEquipment {

    // class generique pour gerer les differentes armes

private :
    // Attributs
    int m_damage;
    std::string m_description;
    std::string m_name;

public:

    /**
     * @brief constructeur de GenericWeapon
     * @param img  image de l'arme
     * @param damage  degats de l'arme
     * @param name  nom de l'arme
     * @param description  description de l'arme
     */
    GenericWeapon(std::string  img, int damage, std::string  name, std::string  description);

    /**
     * @brief getter de m_damage
     * @return  m_damage
     */
    int getDamage();

    /**
     * @brief setter de m_damage
     * @param damage  degats de l'arme
     */
    void setDamage(int damage);

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


#endif //ESIR_PROJETPROG_GENERICWEAPON_H
