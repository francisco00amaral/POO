//
// Created by migue on 15/12/2020.
//

#ifndef TP_TRIGGER_H
#define TP_TRIGGER_H

/* Esta classe recebe o input do utilizador através da classe interface
 * e permite que a classe mundo desencadeia toda a lógica correspondente ao comando recebido.
 *
 * NÃO É ELA QUE FAZ A LÓGICA!!!
 *
 * Contém um objeto da classe Mundo, que só ele tem. Não é possível aceder diretamente ao mundo(não tem gets e sets)
 *
 * A ideia é o manager obter a linha de argumentos,
 * pegar nos argumentos como deve ser(NÃO OS TESTA, APNEAS VERIFICA SE EXISTEM) e envia-los para o mundo.
 * O mundo é que testa se os arguentos são válidos.*/

#include "Mundo.h"
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

class Trigger {
    Mundo mundo;
public:
    Trigger();
    ~Trigger();

    //pre-jogo
    void criaInicial();
    void cria(istringstream& iss);
    void carrega(istringstream& iss);

    //durante o jogo
    void conquista(istringstream& iss, fase& phase);
    void passa();
    void maisOuro(istringstream& iss);
    void maisProduto(istringstream& iss);
    void maisMilitar(istringstream& iss);
    void adquire(istringstream& iss);
    void lista(istringstream& iss);
    void grava(const fase& phase, istringstream& iss, const int& turn);
    void ativa(fase& phase, istringstream& iss, int& turn);
    void apaga(istringstream& iss);
    void toma(istringstream& iss);
    void modifica(istringstream& iss);
    void fevento(istringstream& iss,int turn);
    void evento(int turno);
    void avanca(fase& phase);
    void avanca(fase& phase, int turn);
    static void novoTurno(fase &phase, int turno);

    //ocasiões especiais
    void update();//dá update aos territorios e às flags de repetição
    void harvest();//na fase de Recolha
    void mostraResultadoFinal();

    //mostra info atual(status bar)
    string mostraImperio() const;

};


#endif //TP_TRIGGER_H
