//
// Created by migue on 26/12/2020.
//

#include "Fortaleza.h"

static int count = 0;

Fortaleza::Fortaleza(string nome) : Continente(nome.append(to_string(++count))){
    this->resistencia = 8;
    this->produtos = 0;
    this->ouro = 0;
    this->pontos = 1;
}

Fortaleza::~Fortaleza() {

}


