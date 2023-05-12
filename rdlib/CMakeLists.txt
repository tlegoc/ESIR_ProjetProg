# Rendering lib project file.

message("-- Setting up rdlib")
add_library(RDLIB SHARED
        src/Engine.cpp
        include/rdlib/Agent.h
        src/Agent.cpp
        src/Time.cpp
        include/rdlib/Time.h
        src/Sprite.cpp
        include/rdlib/Sprite.h)

target_include_directories(RDLIB PUBLIC include)


# Adding libs
find_package(SDL2 REQUIRED)
if (${SL2_FOUND})
    message("-- SDL2 Found")
else ()
    message("-- SDL Not found, downloading")
    add_subdirectory(thirdparty/SDL)
endif ()
add_subdirectory(thirdparty/GLM)
find_package(Threads)
find_package(OpenGL REQUIRED)

target_link_libraries(RDLIB PUBLIC Threads::Threads OpenGL::GL OpenGL::GLU SDL2 glm)

# Installation so you can use it with #include <rdlib/file.h>
install(TARGETS RDLIB DESTINATION lib/rdlib)
file(GLOB RDLIB_HEADERS include/**/*.h)
install(FILES ${RDLIB_HEADERS} DESTINATION include/rdlib)
