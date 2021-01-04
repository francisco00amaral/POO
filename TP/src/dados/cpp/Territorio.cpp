//
// Created by migue on 14/11/2020.
//

#include "../h/Territorio.h"


// static int count = 0;

Territorio::Territorio(const string &nome) : nome(nome) {
    this->ouro = 1;
    this->resistencia = 9;
    this->produtos = 1;
    this->pontos = 0;
}

string Territorio::getAsString() const {
    ostringstream os;
    os << "Territorio: " << nome  << " Ouro: " << ouro << " Produtos: " << produtos << " Resistencia: " << resistencia;
    return os.str();
}
