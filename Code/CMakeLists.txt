cmake_minimum_required(VERSION 3.23)
project(Code)

set(CMAKE_CXX_STANDARD 11)
set(GPP_FLAGS "-ansi -pedantic -Wall -std=c++11 -Wextra")

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GPP_FLAGS}")
add_executable(Code main.cpp LinkedList.cpp Element.cpp Trajet.cpp)
add_definitions()
add_compile_definitions(MAP)