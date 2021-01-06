//
// Created by migue on 15/12/2020.
//

#ifndef TP_MUNDO_H
#define TP_MUNDO_H

/* Esta classe é a responsável pela lógica toda.
 *
 * Recebe o input da interface ATRAVÉS do manager, testa esse mesmo input e consoante o a veracidade do mesmo
 * desencadeia toda a lógica necessária.
 *
 * Possui certas funções que são private para auxiliar as funções principais.
 *
 * Não possui nem gets nem sets pk a lógica é somente referente ao mundo, não à interface nem ao manager.
 *
 * As únicas funções que dão return de algum valor servem somente para saber o resultado da função.
 * Não foram feitas com booleans pk os resultados eram mais para além de um simples sim ou não.
 * EX: confirmado, ação repetida, falta recursos, input incorreto
 * */

#include "Imperio.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <Utils.h>

using namespace std;

class Mundo {
    Imperio imperio;
    vector<Territorio*> territorios;//territorios do mundo(não pertencentes ao império)
    vector<tuple<string, Mundo*, int, fase>> saves;
    const vector<string> nomes{"planicie", "montanha", "fortaleza", "mina", "duna", "castelo", "refugio", "pescaria"}; // nomes dos territorios disponiveis para ele conqusitar


    //flags que impedem a repetição de comandos
    bool flagCP = false;
    bool flagOP = false;
    bool flagMaisMilitar = false;
    bool flagMaisTecno = false;
    bool flagEvento = false;

    //funções de auxílio
    Territorio* getTerritorioByName(const string &nome);
    void setConquistado(Territorio * ptr);
    bool verificaNomeTerritorio(const string &nome) const;
    bool verificaExistenciaTerritorio(const string &nome) const;
    bool verificaExistenciaTecnologia(const string &nome) const;
    int verificaPrecoTecnologia(const string &nome) const;
    int aleatorio();

public:

    Mundo();
    ~Mundo();

    void mCriaInicial();
    void mAtivaTec(const string &nome);
    resCria mCria(const string& tipo, int quant);
    resConquista mConquista(const string& nome, fase& phase);
    void mPassa();
    resMaisOP mMaisOuro();
    resMaisOP mMaisProduto();
    resMA mMaisMilitar();
    resMA mAdquire(const string& tipo);
    void mLista(const string &nome) const;
    void mLista();
    resDados mGrava(const fase& phase, istringstream& iss, const int& turn);
    resDados mAtiva(fase& phase, istringstream& iss, int& turn);
    resDados mApaga(istringstream& iss);
    resToma mTomaTerr(const string& nome);
    resToma mTomaTech(const string& nome);
    void mModificaOuro(int quantidade);
    void mModificaProduto(int quantidade);
    resEvento mEvento(int turno);
    bool mFevento(const string& tipo,int turn);
    bool mEventoRecurso(const string &tipo);
    bool mEventoAlianca();
    bool mInvasao(int turno);
    void mAvanca(fase& phase);
    void mAvanca(fase& phase, int turn);
    void mUpdate();
    void mHarvest();
    string mMostraImperio() const;
    string mPontos();

    Mundo &operator=(const Mundo &outro);

};


#endif //TP_MUNDO_H
