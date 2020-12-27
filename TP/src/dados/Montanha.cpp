//
// Created by migue on 26/12/2020.
//

#include "Montanha.h"

static int count = 0;

Montanha::Montanha(string nome) : Continente(nome.append(to_string(++count))) {
    this->resistencia = 6;
    this->produtos = 0;
    this->ouro = 0;
    this->pontos = 1;
    cooldown = 2;
}

Montanha::~Montanha() {

}

void Montanha::update(int turn) {
    if(cooldown > 0)
        cooldown--;
    else
        this->produtos = 1;
}
