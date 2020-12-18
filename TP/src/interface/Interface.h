//
// Created by migue on 15/12/2020.
//

#ifndef TP_INTERFACE_H
#define TP_INTERFACE_H


#include "logica/Manager.h"
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

class Interface {
    Manager manager;
public:
    explicit Interface(Manager& manager);
    ~Interface();
    void startLoad();
    void startGame();
    void faseConquista(fase& phase);
    void faseRecolha(fase& phase);
    void faseCompra(fase& phase);
    void faseEvento(fase& phase);

};


#endif //TP_INTERFACE_H
