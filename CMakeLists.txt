cmake_minimum_required(VERSION 3.15)
project(abstractfactory)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
add_executable(abstractfactory driver.cpp maze_factory.cpp maze_factory.hpp maze_game.cpp maze_game.hpp enhancedfaeryland.cpp enhancedfaeryland.hpp futuristicdystopian.cpp futuristicdystopian.hpp)