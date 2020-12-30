//
// Created by migue on 26/12/2020.
//

#include "Duna.h"

static int count = 0;

Duna::Duna(string nome) : Continente(nome.append(to_string(++count))){
    this->resistencia = 4;
    this->produtos = 1;
    this->ouro = 0;
    this->pontos = 1;
}

Duna::~Duna() {

}
