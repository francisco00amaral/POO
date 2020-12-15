//
// Created by migue on 14/11/2020.
//

#include "../h/Continente.h"

static int countMina = 1;
static int countMontanha = 1;
static int countPlanicie = 1;
static int countCastelo = 1;
static int countDuna = 1;
static int countFortaleza = 1;


Continente::Continente(string& nome) : Territorio(nome) {

    this->pontos = 1;

    if(nome.find("Mina") != string::npos){
        this->nome += to_string(countMina++);
        this->ouro = 1;
        this->resistencia = 5;
    }
    if(nome.find("Montanha") != string::npos){
        this->nome += to_string(countMontanha++);
        this->ouro = 0;
        this->resistencia = 6;
    }
    if(nome.find("Planicie") != string::npos){
        this->nome += to_string(countPlanicie++);
        this->ouro = 1;
        this->produtos = 1;
        this->resistencia = 5;
    }
    if(nome.find("Castelo") != string::npos){
        this->nome += to_string(countCastelo++);
        this->ouro = 1;
        this->resistencia = 7;
        this->produtos = 3;
    }
    if(nome.find("Duna") != string::npos){
        this->nome += to_string(countDuna++);
        this->produtos = 1;
        this->resistencia = 4;
        this->ouro = 0;

    }
    if(nome.find("Fortaleza") != string::npos){
        this->nome += to_string(countFortaleza++);
        this->produtos = 0;
        this->ouro = 0;
        this->resistencia = 8;
    }

}

int Continente::getPontos() const {
    return pontos;
}
