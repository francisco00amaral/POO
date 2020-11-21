//
// Created by migue on 14/11/2020.
//

#ifndef TP_ILHA_H
#define TP_ILHA_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

#include "Territorio.h"

class Ilha : protected Territorio{

public:
    Ilha(string nome);
    int getPontos() const;
};


#endif //TP_ILHA_H
