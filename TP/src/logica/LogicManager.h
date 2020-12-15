//
// Created by migue on 15/12/2020.
//

#ifndef TP_LOGICMANAGER_H
#define TP_LOGICMANAGER_H

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

using namespace std;

class LogicManager {
    Mundo mundo;
public:
    LogicManager();
    ~LogicManager();

    void init();//função chamada quando o manager é criado

    //pre-jogo
    void cria(istringstream& iss);
    void carrega(istringstream& iss);

    //durante o jogo
    void conquista(istringstream& iss);
    void passa();
    void maisOuro();
    void maisProduto();
    void maisMilitar();
    void adquire(istringstream& iss);
    void lista(istringstream& iss) const;
    void grava(istringstream& iss);
    void ativa(istringstream& iss);
    void toma(istringstream& iss);
    void modifica(istringstream& iss);
    void fevento(istringstream& iss);

    //ocasião especial(turno 6)
    void update();

    //mostra info atual(status bar)
    string mostraImperio() const;

};


#endif //TP_LOGICMANAGER_H
