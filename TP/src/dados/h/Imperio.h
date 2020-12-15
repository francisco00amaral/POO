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
    vector<Territorio*> territConquistados; // territorios conqusitados pelo imperio
    const vector<string> nomes{"planicie", "montanha", "fortaleza", "mina", "duna", "castelo", "refugio", "pescaria"};
    int cofre = 0;
    bool tecnologias[5] = {false, false, false, false, false};
    int armazem = 0;
    int forcaMilitar = 0;
public:
    string getAsString() const;
    string getAsString(const string &str) const;

    vector<string>& getNomesTerritorios() const;
    void mostra(const string &nome) const;
    void mostra() const;
    bool criaTerritorios(string &palavra,int n);
    void conquer(Territorio t);
    vector <Territorio*>& getConquistados();
    void adicionaOuro(const Territorio &t);
    void adicionaProd(const Territorio &t);
    void inicial();




    };


#endif //TP_IMPERIO_H
