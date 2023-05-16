# Fichiers du jeu
# C'est ici qu'on ajoute nos fichiers de jeu

add_executable(Game
        main.cpp
        entity/character/Hero.cpp entity/character/Hero.h)

target_link_libraries(Game RDLIB)

add_custom_command(TARGET Game  POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/assets
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/assets)