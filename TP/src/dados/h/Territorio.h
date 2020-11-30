//
// Created by migue on 14/11/2020.
//

#ifndef TP_TERRITORIO_H
#define TP_TERRITORIO_H
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Territorio {//este vai ser usado como TERRITORIO INICIAL SOMENTE
protected:
    string nome;
    int resistencia;
    int produtos;
    int ouro;
    int pontos;
    bool conquistado;
public:
    Territorio(const string &nome = "Inicial");
    string getNome() const{return nome;}
    int getRes() const{return resistencia;}
    int getOuro() const{return ouro;}
    int getProd() const{return produtos;}
    bool getConquistado() const{return conquistado;}
    int getPts() const{return pontos;}
    void setRes(int val){this->resistencia = val;}
    void setOuro(int val){this->ouro = val;}
    void setProd(int val){this->produtos = val;}
    void setPts(int val){this->pontos = val;}
    void setConquistado(){cout << "Entrou aqui com " << this->conquistado << endl; this->conquistado = true; cout << " Saiu com: " << this->conquistado;}
    string getAsString() const;
    bool isConquistado() const;
};


#endif //TP_TERRITORIO_H
