cmake_minimum_required(VERSION 3.13)
project(gameoflife C)

set(CMAKE_C_STANDARD 11)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(gameoflife main.c core/gameoflife.c core/gameoflife.h)

target_link_libraries(gameoflife ${CURSES_LIBRARIES})