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

# SDL2
if (UNIX AND NOT APPLE)
    add_compile_definitions(LINUX)
    message("-- Building on linux, using find_package")

    find_package(SDL2 REQUIRED)
    find_package(Threads)

    target_include_directories(RDLIB ${SDL2_INCLUDE_DIRS})
    target_link_libraries(RDLIB PUBLIC ${SDL2_LIBRARIES} Threads::Threads)
    if (${SL2_FOUND})
        message("-- SDL2 Found")
    else ()
        message("-- SDL2 Not found, downloading")
        add_compile_definitions(SDL2_GIT)
        add_subdirectory(thirdparty/SDL)
    endif ()
elseif (WIN32)
    add_compile_definitions(WINDOWS)
    message("-- Building on windows, downloading SDL2")
    add_compile_definitions(SDL2_GIT)
    add_subdirectory(thirdparty/SDL)
    target_link_libraries(RDLIB PUBLIC SDL2-static)
endif ()


add_subdirectory(thirdparty/GLM)

find_package(OpenGL REQUIRED)

target_link_libraries(RDLIB PUBLIC OpenGL::GL OpenGL::GLU glm)

# Installation so you can use it with #include <rdlib/file.h>
install(TARGETS RDLIB DESTINATION lib/rdlib)
file(GLOB RDLIB_HEADERS include/**/*.h)
install(FILES ${RDLIB_HEADERS} DESTINATION include/rdlib)
