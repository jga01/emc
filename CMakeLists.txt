cmake_minimum_required(VERSION 3.20)

set(PROJECT_NAME emc)

project(${PROJECT_NAME})

add_subdirectory(external/raylib)

include_directories(include)

set(SOURCES src/main.c src/graph.c src/widgets.c)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} raylib)
