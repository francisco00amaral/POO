//
// Created by migue on 26/12/2020.
//

#include "Castelo.h"

static int count = 0;

Castelo::Castelo(string nome) : Continente(nome.append(to_string(++count))){
    this->resistencia = 7;
    this->produtos = 0;
    this->ouro = 1;
    this->pontos = 1;
}

Castelo::~Castelo() {

}

void Castelo::update(int turn) {
    if((1 <= turn && turn <= 2) || (6 <= turn && turn <= 7))//[1, 2] e [6, 7]
        this->produtos = 3;
    else //resto
        this->produtos = 0;
}
