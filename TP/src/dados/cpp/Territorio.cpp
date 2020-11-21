//
// Created by migue on 14/11/2020.
//

#include "../h/Territorio.h"


static int count = 0;

Territorio::Territorio(string nome) : nome(nome) {
    this->ouro = 0;
    this->resistencia = 9;
    this->produtos = 0;
    this->pontos = 0;
}

string Territorio::getAsString() const {
    ostringstream os;
    os << "Territorio: " << nome << " Ouro: " << ouro << " Resistencia: " << resistencia;
    return os.str();
}