cmake_minimum_required(VERSION 3.25)
project(ESIR_ProjetProg)

# Cmake principal, crée le projet, et inclus nos dossiers

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Add the library first to be included in game
add_subdirectory(rdlib)
add_subdirectory(game)
