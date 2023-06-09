# Rendering lib project file.

message("-- Setting up rdlib")
add_library(RDLIB
        src/Engine.cpp
        include/rdlib/Agent.h
        src/Agent.cpp
        src/Time.cpp
        include/rdlib/Time.h
        src/SpriteAgent.cpp
        include/rdlib/SpriteAgent.h
        include/rdlib/include_sdl.h
        include/rdlib/VisibleAgent.h
        src/Shader.cpp
        include/rdlib/Shader.h
        include/stb_image.h
        src/InputManager.cpp
        include/rdlib/InputManager.h
        src/ColliderAgent.cpp
        include/rdlib/ColliderAgent.h
        src/ColliderSpriteAgent.cpp
        include/rdlib/ColliderSpriteAgent.h
        src/Map.cpp
        include/rdlib/Map.h
        src/SpriteSheetAgent.cpp
        include/rdlib/SpriteSheetAgent.h
        src/TextureManager.cpp
        include/rdlib/TextureManager.h
        src/ColliderSpriteSheetAgent.cpp
        include/rdlib/ColliderSpriteSheetAgent.h
        src/UserInterface.cpp
        include/rdlib/UserInterface.h)

target_include_directories(RDLIB PUBLIC include)


# Adding libs

# SDL2
if (UNIX AND NOT APPLE)
    add_compile_definitions(LINUX)
    message("-- Building on linux, using find_package")

    find_package(SDL2 REQUIRED)
    set(THREADS_PREFER_PTHREAD_FLAG ON)
    find_package(Threads REQUIRED)

    if (${SDL2_FOUND})
        message("-- SDL2 Found")
        include_directories(${SDL2_INCLUDE_DIRS})
        target_link_libraries(RDLIB PUBLIC ${SDL2_LIBRARIES} Threads::Threads)
    else ()
        message("-- SDL2 Not found, downloading")
        add_compile_definitions(SDL2_GIT)
        add_subdirectory(thirdparty/SDL)
        target_link_libraries(RDLIB PUBLIC SDL2 Threads::Threads)
    endif ()
elseif (WIN32)
    add_compile_definitions(WINDOWS)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
    message("-- Building on windows, downloading SDL2")
    add_compile_definitions(SDL2_GIT)
    add_subdirectory(thirdparty/SDL)
    target_link_libraries(RDLIB PUBLIC SDL2-static)
endif ()


add_subdirectory(thirdparty/GLM)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})

target_link_libraries(RDLIB PUBLIC OpenGL::GL OpenGL::GLU glm ${GLEW_LIBRARIES})

# Installation so you can use it with #include <rdlib/file.h>
install(TARGETS RDLIB DESTINATION lib/rdlib)
file(GLOB RDLIB_HEADERS include/**/*.h)
install(FILES ${RDLIB_HEADERS} DESTINATION include/rdlib)
