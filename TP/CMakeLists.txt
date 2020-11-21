cmake_minimum_required(VERSION 3.17)
project(TP)

set(CMAKE_CXX_STANDARD 14)

add_executable(TP main.cpp src/dados/cpp/Territorio.cpp src/dados/h/Territorio.h src/dados/cpp/Continente.cpp src/dados/h/Continente.h src/dados/cpp/Ilha.cpp src/dados/h/Ilha.h src/dados/cpp/Imperio.cpp src/dados/h/Imperio.h src/funcoes/Utils.cpp src/funcoes/Utils.h)