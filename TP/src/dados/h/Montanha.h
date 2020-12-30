//
// Created by migue on 26/12/2020.
//

#ifndef TP_MONTANHA_H
#define TP_MONTANHA_H


#include <Continente.h>

class Montanha : public Continente{
    int cooldown;
public:
    explicit Montanha(string nome);
    ~Montanha();
    void update(int turn) override;
};


#endif //TP_MONTANHA_H
