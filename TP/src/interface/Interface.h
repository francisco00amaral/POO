//
// Created by migue on 15/12/2020.
//

#ifndef TP_INTERFACE_H
#define TP_INTERFACE_H


#include "logica/LogicManager.h"
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

class Interface {
    LogicManager manager;
public:
    explicit Interface(LogicManager& manager);
    ~Interface();
    void startLoad();
    void startGame();

};


#endif //TP_INTERFACE_H
