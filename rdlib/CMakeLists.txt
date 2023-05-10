# Fichiers de la librairie de rendu
# A toucher uniquement si vous voulez bidouiller le rendu

add_library(RDLIB SHARED
        src/Renderer.cpp
        src/LivableObject.h
        )

target_include_directories(RDLIB PUBLIC include)

install(TARGETS RDLIB DESTINATION lib/rdlib)
file(GLOB RDLIB_HEADERS include/**/*.h)
install(FILES ${RDLIB_HEADERS} DESTINATION include/rdlib)