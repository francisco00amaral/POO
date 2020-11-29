//
// Created by migue on 14/11/2020.
//

#ifndef TP_CONTINENTE_H
#define TP_CONTINENTE_H
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#include "Territorio.h"

class Continente : public Territorio{

public:
    Continente(string &nome);
    int getPontos() const;
};


#endif //TP_CONTINENTE_H
