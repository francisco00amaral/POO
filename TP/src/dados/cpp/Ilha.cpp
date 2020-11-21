//
// Created by migue on 14/11/2020.
//

#include "../h/Ilha.h"

static int count = 1;

Ilha::Ilha(string nome) : Territorio(nome + to_string(count++)) {

    this->pontos = 1;

    // FALTA VERIFICAR NOS X TURNOS ALGUNS RECEBEM + OURO E MAIS PRODUTOS

    if(nome.find("Pescaria") != string::npos){
        this->ouro = 0;
        this->resistencia = 9;
        this->produtos = 2; // em cada turno do primeiro ano produz 2 unidades de prod, no segundo produz 4;
        this->
    }
    if(nome.find("Refugio") != string::npos){
        this->ouro = 1;
        this->resistencia = 9;
        this->produtos = 0;
    }

}

int Ilha::getPontos() const {
    return pontos;
}