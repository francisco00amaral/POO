//
// Created by migue on 15/11/2020.
//

#ifndef TP_IMPERIO_H
#define TP_IMPERIO_H
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <unordered_map>
#include "Territorio.h"

using namespace std;

class Imperio {
    vector<Territorio*> territConquistados; // territorios conqusitados pelo imperio
    int cofre = 0, maxCofre = 3;
    int armazem = 0, maxArmazem = 3;
    int forcaMilitar = 0, maxMilitar = 3;
    unordered_map<string, tuple<bool, int>> tecnologias{
            {"drones", {false, 4}},
            {"misseis", {false, 4}},
            {"defesas", {false, 4}},
            {"bolsa", {false, 2}},
            {"banco", {false, 3}}
    };

public:
    Imperio();
    Imperio(const Imperio& aCopiar);
    ~Imperio();
    vector <Territorio*>& getConquistados();
    int getForcaMilitar() const;
    void setForcaMilitar(int val);
    int getCofre() const;
    void setCofre(int val);
    int getArmazem() const;
    void setArmazem(int val);
    void updateMilitar();
    int getMaxMilitar() const;
    void setMaxMilitar();
    void updateOP();
    void setMaxCofre();
    void setMaxArmazem();
    int getMaxCofre() const;
    int getMaxArmazem() const;
    vector<string>& getKeyValues() const;
    unordered_map<string, tuple<bool, int>> getUnMap() const;
    void compraTecnologia(const string &nome);
    bool verificaTecnologia(const string &nome) const;
    string toString() const;

    };


#endif //TP_IMPERIO_H
