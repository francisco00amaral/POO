//
// Created by migue on 15/12/2020.
//

#include "Mundo.h"

Mundo::Mundo() {

}

Mundo::~Mundo() {

}

resCria Mundo::mCria(const string &tipo, int quant) {
    return CRIADO;
}

resConquista Mundo::mConquista(const string &nome) {
    return INEXISTENTE;
}

void Mundo::mPassa() {

}

resMaisOP Mundo::mMaisOuro() {
    return NAO_TROCADO;
}

resMaisOP Mundo::mMaisProduto() {
    return NAO_TROCADO;
}

resMA Mundo::mMaisMilitar() {
    return ADQUIRIDO;
}

resMA Mundo::mAdquire(const string &tipo) {
    return ADQUIRIDO;
}

void Mundo::mLista(string nome) const {

}

void Mundo::mLista() const {

}

void Mundo::mGrava(fase &phase, istringstream &iss) {

}

void Mundo::mAtiva(fase &phase, istringstream &iss) {

}

void Mundo::mApaga(fase &phase, istringstream &iss) {

}

resToma Mundo::mTomaTerr(const string &nome) {
    return TECNOLOGIA_INEXISTENTE;
}

resToma Mundo::mTomaTech(const string &nome) {
    return TECNOLOGIA_INEXISTENTE;
}

resModifica Mundo::mModificaOuro(int quantidade) {
    return VAL_NEGATIVO;
}

resModifica Mundo::mModificaProduto(int quantidade) {
    return VAL_NEGATIVO;
}

void Mundo::mFevento() {

}

bool Mundo::mFevento(const string &tipo) {
    return false;
}

void Mundo::mAvanca(fase &phase) {

}

void Mundo::mUpdate() {

}

void Mundo::mHarvest() {

}

string Mundo::mostraImperio() const {
    return std::string();
}

