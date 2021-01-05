//
// Created by migue on 15/12/2020.
//

#ifndef TP_INTERFACE_H
#define TP_INTERFACE_H

/* Esta classe tem como objetivo apenas mostrar a informação ao utilizador e ler o comando introduzio pelo mesmo. MAIS NADA!!!
 *
 * De acordo com a fase atual do turno, ele demostra a informação pretendida.
 *
 * A fase é alterada dentro do mundo.*/

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
//    Interface();
    ~Interface();
    void startLoad();
    void startGame();
    void faseConquista(fase& phase, int& turn);
    void faseRecolha(fase& phase, int& turn);
    void faseCompra(fase& phase, int& turn);
    void faseEvento(fase& phase, int& turn);
    void fim();

};


#endif //TP_INTERFACE_H
