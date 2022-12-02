cmake_minimum_required(VERSION 3.22)
project(CPP_TP1)
set(CMAKE_CXX_STANDARD 11)
add_executable(CPP_TP1 Controleur/Catalogue.cpp Vue/main.cpp Modele/Trajet.cpp Modele/TrajetSimple.cpp
                Modele/LinkedList.cpp Modele/TrajetCompose.cpp Modele/Element.cpp Vue/Terminal.cpp)

SET(GCC_COVERAGE_COMPILE_FLAGS "-g -ansi -pedantic –Wall –std=c++11")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS}")