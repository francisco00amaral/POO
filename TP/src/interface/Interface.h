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
    void faseConquista(const Manager& manager, fase& phase);
    void faseRecolha(const Manager& manager, fase& phase);
    void faseCompra(const Manager& manager, fase& phase);
    void faseEvento(const Manager& manager, fase& phase);

};


#endif //TP_INTERFACE_H
