//
// Created by migue on 14/11/2020.
//

#include "../h/Territorio.h"


// static int count = 0;

Territorio::Territorio(const string &nome) : nome(nome) {
    this->ouro = 0;
    this->resistencia = 9;
    this->produtos = 0;
    this->pontos = 0;
    this->conquistado = true;
}

string Territorio::getAsString() const {
    ostringstream os;
    os << "Territorio: " << nome << "Conquistado: "  << conquistado << " Ouro: " << ouro << " Resistencia: " << resistencia;
    return os.str();
}
bool Territorio::isConquistado() const{
    if(getConquistado())
        return true;
    else
        return false;
}