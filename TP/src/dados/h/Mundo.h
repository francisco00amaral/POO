//
// Created by migue on 15/12/2020.
//

#ifndef TP_MUNDO_H
#define TP_MUNDO_H


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

    const vector<string> nomes{"planicie", "montanha", "fortaleza", "mina", "duna", "castelo", "refugio", "pescaria"}; // nomes dos territorios disponiveis para ele conqusitar


    //flags que impedem a repetição de comandos
    bool flagCP = false;
    bool flagOP = false;
    bool flagMaisMilitar = false;
    bool flagMaisTecno = false;
    bool flagEvento = false;

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

    //métodos relacionados com o Império
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
    void mGrava(fase& phase, istringstream& iss);
    void mAtiva(fase& phase, istringstream& iss);
    void mApaga(fase& phase, istringstream& iss);
    resToma mTomaTerr(const string& nome);
    resToma mTomaTech(const string& nome);
    void mModificaOuro(int quantidade);
    void mModificaProduto(int quantidade);
    void mFevento();
    bool mFevento(const string& tipo,int turn);
    bool mEventoRecurso(const string &tipo);
    bool mEventoAlianca();
    bool mInvasao(int turno);
    void mAvanca(fase& phase);
    void mAvanca(fase& phase, int turn);
    void mUpdate();
    void mHarvest();
    string mMostraImperio() const;
    string mPontos() const;

    //métodos NÃO relacionados com o Império
    /*
     * etc
     * */
};


#endif //TP_MUNDO_H
