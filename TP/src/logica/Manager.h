//
// Created by migue on 15/12/2020.
//

#ifndef TP_MANAGER_H
#define TP_MANAGER_H

/*Esta classe recebe o input do utilizador através da classe interface
 * e desencadeia toda a lógica correspondente ao comando recebido
 *
 * Contém um objeto da classe Mundo, que só ele tem e deve aceder(sem gets e sets)
 *
 * A ideia é o manager obter os argumentos do comando recebido e passá-los para as funções que implementa*/

#include "Mundo.h"
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

class Manager {
    Mundo mundo;
public:
    Manager();
    ~Manager();

    void init();//função chamada quando o manager é criado

    //pre-jogo
    void cria(istringstream& iss);
    void carrega(istringstream& iss);

    //durante o jogo
    void conquista(istringstream& iss, fase& phase);
    void passa();
    void maisOuro(istringstream& iss);
    void maisProduto(istringstream& iss);
    void maisMilitar(istringstream& iss);
    void adquire(istringstream& iss);
    void lista(istringstream& iss) const;
    void grava(fase& phase, istringstream& iss);
    void ativa(fase& phase, istringstream& iss);
    void apaga(fase& phase, istringstream& iss);
    void toma(istringstream& iss);
    void modifica(istringstream& iss);
    void fevento(istringstream& iss);
    void avanca(fase& phase);

    //ocasiões especiais
    void update();//dá update aos territorios e às flags de repetição
    void harvest() const;//na fase de Recolha
    void mostraResultadoFinal();

    //mostra info atual(status bar)
    string mostraImperio() const;

};


#endif //TP_MANAGER_H
