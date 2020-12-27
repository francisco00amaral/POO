cmake_minimum_required(VERSION 3.17)
project(TP)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(src)
include_directories(src/dados)
include_directories(src/dados/cpp)
include_directories(src/dados/h)
include_directories(src/funcoes)

add_executable(TP
        src/dados/cpp/Continente.cpp
        src/dados/cpp/Ilha.cpp
        src/dados/cpp/Imperio.cpp
        src/dados/cpp/Territorio.cpp
        src/dados/h/Continente.h
        src/dados/h/Ilha.h
        src/dados/h/Imperio.h
        src/dados/h/Territorio.h
        src/funcoes/Utils.cpp
        src/funcoes/Utils.h
        main.cpp
        src/interface/Interface.cpp
        src/interface/Interface.h
        src/logica/Manager.cpp
        src/logica/Manager.h
        src/dados/cpp/Mundo.cpp
        src/dados/h/Mundo.h src/dados/Planicie.cpp src/dados/Planicie.h src/dados/Montanha.cpp src/dados/Montanha.h src/dados/Fortaleza.cpp src/dados/Fortaleza.h src/dados/Mina.cpp src/dados/Mina.h src/dados/Duna.cpp src/dados/Duna.h src/dados/Castelo.cpp src/dados/Castelo.h src/dados/Refugio.cpp src/dados/Refugio.h src/dados/Pescaria.cpp src/dados/Pescaria.h)
