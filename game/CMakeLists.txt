# Fichiers du jeu
# C'est ici qu'on ajoute nos fichiers de jeu


add_executable(Game
        main.cpp
        entity/character/Hero.cpp
        entity/character/Hero.h
        entity/character/Monster.cpp
        entity/character/Monster.h
        entity/character/Monster.h
        entity/items/GenericItem.cpp
        entity/items/GenericItem.h
        entity/items/equipments/GenericEquipment.h
        entity/items/equipments/GenericEquipment.cpp
        entity/items/equipments/weapon/Sword.h
        entity/items/equipments/weapon/Sword.cpp
        entity/items/equipments/Armor/Shield.h
        entity/items/equipments/Armor/Shield.cpp
        entity/items/equipments/Armor/GenericArmor.h
        entity/items/equipments/Armor/GenericArmor.cpp
        entity/items/equipments/weapon/GenericWeapon.h
        entity/items/equipments/weapon/GenericWeapon.cpp
        entity/items/consumables/GenericConsumable.h
        entity/items/consumables/GenericConsumable.cpp
        entity/items/consumables/life/OnePV.h
        entity/items/consumables/life/OnePV.cpp
        entity/items/consumables/life/halfPV.cpp
        entity/items/consumables/life/OneHeart.h
        entity/items/consumables/life/OneHeart.cpp
        entity/items/consumables/buff/ShieldImprove.cpp
        entity/character/SwordAgent.cpp
        entity/character/SwordAgent.h)

target_link_libraries(Game RDLIB)

add_custom_command(TARGET Game POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/assets
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/assets)

if(WIN32 AND CMAKE_BUILD_TYPE MATCHES Debug)
        target_compile_options(Game PRIVATE -mconsole)
endif()