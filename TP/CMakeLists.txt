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
        src/dados/h/Mundo.h)
