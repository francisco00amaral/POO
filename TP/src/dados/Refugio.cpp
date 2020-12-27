//
// Created by migue on 26/12/2020.
//

#include "Refugio.h"

static int count = 0;

Refugio::Refugio(string nome) : Ilha(nome.append(to_string(++count))) {
    this->resistencia = 9;
    this->produtos = 0;
    this->ouro = 1;
    this->pontos = 2;
}

Refugio::~Refugio() {

}
