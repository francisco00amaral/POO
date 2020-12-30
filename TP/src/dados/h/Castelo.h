//
// Created by migue on 26/12/2020.
//

#ifndef TP_CASTELO_H
#define TP_CASTELO_H


#include <Continente.h>

class Castelo : public Continente{

public:
    explicit Castelo(string nome);
    ~Castelo();
    void update(int turn) override;
};


#endif //TP_CASTELO_H
