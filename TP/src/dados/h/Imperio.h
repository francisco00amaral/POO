//
// Created by migue on 15/11/2020.
//

#ifndef TP_IMPERIO_H
#define TP_IMPERIO_H
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "Territorio.h"

using namespace std;

class Imperio {
    vector<Territorio> territorios; // todos os territorios existentes
    vector<Territorio> territConquistados; // territorios conqusitados pelo imperio
    vector<string> nomes{"Planicie", "Montanha", "Fortaleza", "Mina", "Duna", "Castelo", "Refugio dos Piratas", "Pescaria"};
    int banco;
    int tecnologia[5][2];
    int forcaMilitar;
public:
    string getAsString() const;
    string getAsString(string str) const;
    vector<Territorio> getTerritorios() const;
    vector<string> getNomesTerritorios() const;
    void mostra(string nome) const;
    void mostra() const;
    bool criaTerritorios(string palavra,int n);


};


#endif //TP_IMPERIO_H
