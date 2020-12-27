//
// Created by migue on 26/12/2020.
//

#ifndef TP_MINA_H
#define TP_MINA_H


#include <Continente.h>

class Mina : public Continente{

public:
    explicit Mina(string nome);
    ~Mina();
    void update(int turn) override;
};


#endif //TP_MINA_H
