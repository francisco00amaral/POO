//
// Created by migue on 26/12/2020.
//

#include "Pescaria.h"

Pescaria::Pescaria(string nome) : Ilha(nome) {
    this->resistencia = 9;
    this->produtos = 2;
    this->ouro = 0;
    this->pontos = 2;
}

Pescaria::~Pescaria() {

}

void Pescaria::update(int turn) {
    if(turn == 7)
        this->produtos = 4;
}
