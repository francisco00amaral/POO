//
// Created by migue on 15/12/2020.
//

#ifndef TP_MUNDO_H
#define TP_MUNDO_H


#include "Imperio.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Mundo {
    Imperio imperio;
    vector<Territorio*> territorios;//territorios do mundo(não pertencentes ao império)
//    const vector<string> nomes{"planicie", "montanha", "fortaleza", "mina", "duna", "castelo", "refugio", "pescaria"};
public:
    Mundo();
    ~Mundo();
    bool verificaExistenciaTerritorio(string nome) const;

    //métodos relacionados com o Império
    /*
     * etc
     * */

    //métodos NÃO relacionados com o Império
    /*
     * etc
     * */
};


#endif //TP_MUNDO_H
