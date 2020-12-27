//
// Created by migue on 26/12/2020.
//

#ifndef TP_PLANICIE_H
#define TP_PLANICIE_H


#include <Continente.h>
#include <iostream>

using namespace std;

class Planicie : public Continente{

public:
    explicit Planicie(string nome);
    ~Planicie();
    void update(int turn) override;
};


#endif //TP_PLANICIE_H
