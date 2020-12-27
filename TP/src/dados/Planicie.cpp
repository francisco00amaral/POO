//
// Created by migue on 26/12/2020.
//

#include "Planicie.h"

static int count = 0;

Planicie::Planicie(string nome) : Continente(nome.append(to_string(++count))){
    this->resistencia = 5;
    this->produtos = 1;
    this->ouro = 1;
    this->pontos = 1;
}

Planicie::~Planicie() {

}

void Planicie::update(int turn) {
    if(turn == 6)
        this->produtos = 2;
}


