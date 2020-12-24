//
// Created by migue on 15/12/2020.
//

#include "Mundo.h"

Mundo::Mundo() {

}

Mundo::~Mundo() {

}

bool Mundo::verificaExistenciaTerritorio(string nome) const{
    for(const auto& x : territorios)
        if(x->getNome() == nome)
            return true;
    return false;
}


void Mundo::harvest(){


    for(const auto& x : territorios){
        x->getRes();
    }

}