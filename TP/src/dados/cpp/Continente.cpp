//
// Created by migue on 14/11/2020.
//

#include "../h/Continente.h"

static int count = 1;

Continente::Continente(string nome) : Territorio(nome + to_string(count++)) {

    this->pontos = 1;

    // FALTA VERIFICAR NOS X TURNOS ALGUNS RECEBEM + OURO E MAIS PRODUTOS

    if(nome.find("Mina") != string::npos){
        this->ouro = 1;
        this->resistencia = 5;
    }
    if(nome.find("Montanha") != string::npos){
        this->ouro = 0;
        this->resistencia = 6;
    }
    if(nome.find("Planicie") != string::npos){
        this->ouro = 1;
        this->produtos = 1;
        this->resistencia = 5;
    }
    if(nome.find("Castelo") != string::npos){
        this->ouro = 1;
        this->resistencia = 7;
        this->produtos = 3;
    }
    if(nome.find("Duna") != string::npos){
        this->produtos = 1;
        this->resistencia = 4;
        this->ouro = 0;

    }
    if(nome.find("Fortaleza") != string::npos){
        this->produtos = 0;
        this->ouro = 0;
        this->resistencia = 8;
    }

}

int Continente::getPontos() const {
    return pontos;
}
