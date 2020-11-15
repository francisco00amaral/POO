
#include <string>

using namespace std;

class Territorio{
    string nome;
    int resistencia;
    int produtos;
    int ouro;
    int pontos;
    int oooo;

    public:
    Territorio();
    string getNome()const{return nome;}
    int getResistencia()const{return resistencia;}
    int getProdutos()const{return produtos;}
    int getOuro()const{return ouro;}
    int getPontos()const{return pontos;}
    
};
