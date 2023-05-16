# Fichiers du jeu
# C'est ici qu'on ajoute nos fichiers de jeu

add_executable(Game
        main.cpp
        entity/character/hero.cpp entity/character/hero.h)

target_link_libraries(Game RDLIB)