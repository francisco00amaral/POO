//
// Created by migue on 26/12/2020.
//

#ifndef TP_PESCARIA_H
#define TP_PESCARIA_H


#include <Ilha.h>

class Pescaria : public Ilha{

public:
    explicit Pescaria(string nome);
    ~Pescaria();
    void update(int turn) override;
};


#endif //TP_PESCARIA_H
