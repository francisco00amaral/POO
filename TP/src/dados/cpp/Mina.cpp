//
// Created by migue on 26/12/2020.
//

#include "Mina.h"

static int count = 0;

Mina::Mina(string nome) : Continente(nome.append(to_string(++count))){
    this->resistencia = 5;
    this->produtos = 0;
    this->ouro = 0;
    this->pontos = 1;
}

Mina::~Mina() {

}

void Mina::update(int turn) {
    if((turn >= 1 && turn <= 3) || (turn >= 7 && turn <= 9))//[1, 3] e [7, 9]
        this->ouro = 1;
    else//[4, 6] e [10, 12]
        this->ouro = 2;
}
