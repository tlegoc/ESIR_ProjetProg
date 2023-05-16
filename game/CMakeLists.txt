# Fichiers du jeu
# C'est ici qu'on ajoute nos fichiers de jeu



add_executable(Game
        main.cpp entity/items/GenericItem.cpp entity/items/GenericItem.h
        entity/items/equipments/GenericEquipment.h entity/items/equipments/GenericEquipment.cpp entity/items/equipments/weapon/Sword.h entity/items/equipments/weapon/Sword.cpp entity/items/equipments/Armor/Shield.h entity/items/equipments/Armor/Shield.cpp entity/items/equipments/Armor/GenericArmor.h entity/items/equipments/Armor/GenericArmor.cpp entity/items/equipments/weapon/GenericWeapon.h entity/items/equipments/weapon/GenericWeapon.cpp)

target_link_libraries(Game RDLIB)

add_custom_command(TARGET Game  POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/assets
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/assets)