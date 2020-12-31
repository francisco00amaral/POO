//
// Created by migue on 15/12/2020.
//

#include <Duna.h>
#include <Castelo.h>
#include <Fortaleza.h>
#include <Mina.h>
#include <Montanha.h>
#include <Planicie.h>
#include <Pescaria.h>
#include <Refugio.h>
#include "Mundo.h"

Mundo::Mundo() {
    srand(time(NULL));//inicializa random seed
    //n deve ter grande problema uma vez que só há 1 Mundo
}

Mundo::~Mundo() {

}

resCria Mundo::mCria(const string &tipo, int quant) {

    if(!verificaNomeTerritorio(tipo))
        return TIPO_INEXISTENTE;

    if(quant <= 0)
        return QUANTIDADE_NEGATIVA;


    Territorio* ptr;
    for(int i = 0; i < quant; i++){
        if(tipo == "castelo"){
            ptr = new Castelo("Castelo");
            territorios.push_back(ptr);
        }
        else if(tipo == "duna"){
            ptr = new Duna("Duna");
            territorios.push_back(ptr);
        }
        else if(tipo == "fortaleza"){
            ptr = new Fortaleza("Fortaleza");
            territorios.push_back(ptr);
        }
        else if(tipo == "mina"){
            ptr = new Mina("Mina");
            territorios.push_back(ptr);
        }
        else if(tipo == "montanha"){
            ptr = new Montanha("Montanha");
            territorios.push_back(ptr);
        }
        else if(tipo == "planicie"){
            ptr = new Planicie("Planicie");
            territorios.push_back(ptr);
        }
        else if(tipo == "pescaria"){
            ptr = new Pescaria("Pescaria");
            territorios.push_back(ptr);
        }
        else if(tipo == "refugio"){
            ptr = new Refugio("Refugio");
            territorios.push_back(ptr);
        }
    }
    return CRIADO;
}

resConquista Mundo::mConquista(const string &nome, fase& phase) {

    //comando repetido
    if(flagCP){
        cout << flagCP << endl;
        return RE_CP;
    }

    int val = rand() % 6 + 1;//valor random da conquista [1, 6]
    int forcaMilitar = imperio.getForcaMilitar();

    if(!verificaExistenciaTerritorio(nome))//verifica se o territorio existe
        return INEXISTENTE;

    if(nome == "refugio" || nome == "pescaria") {//verifica tecnologia necessária
        if (!imperio.verificaTecnologia("misseis"))
            return SEM_MISSEIS;
    }

    Territorio* ptr;
    ptr = getTerritorioByName(nome);

    if(ptr->getRes() <= val+forcaMilitar+10){
        setConquistado(ptr); //remove o pointer do territorios e mete-o no conquistados
        this->flagCP = true;
        return CONQUISTADO;
    }
    else{
        imperio.setForcaMilitar(imperio.getForcaMilitar()-1);
        if(imperio.getForcaMilitar() <= 0){
            phase = FIM;
            return PERDEU_CP;
        }
        return NAO_CONQUISTADO;
    }

}

void Mundo::mPassa() {
    flagCP = true;
}

resMaisOP Mundo::mMaisOuro() {

    if(flagOP)
        return RE_OP;

    if(!imperio.verificaTecnologia("bolsa"))//verifica se tem tecnologia necessaria
        return SEM_BOLSA;

    if(imperio.getArmazem() >= 2)//verifica se tem recursos para trocar
        if(imperio.getCofre() < imperio.getMaxCofre()){//verifica se tem espaço no cofre
            imperio.setArmazem(imperio.getArmazem()-2);
            imperio.setCofre(imperio.getCofre()+1);
            flagOP = true;
            return TROCADO;
        }
        else//se nao tiver espaço no cofre
            return NAO_TROCADO;
    else
        return SEM_RECURSOS;
}

resMaisOP Mundo::mMaisProduto() {
    if(flagOP)
        return RE_OP;

    if(!imperio.verificaTecnologia("bolsa"))//verifica se tem tecnologia necessaria
        return SEM_BOLSA;

    if(imperio.getCofre() >= 2)//verifica se tem recursos para trocar
        if(imperio.getArmazem() < imperio.getMaxArmazem()){//verifica se tem espaço no cofre
            imperio.setCofre(imperio.getCofre()-2);
            imperio.setArmazem(imperio.getArmazem()+1);
            flagOP = true;
            return TROCADO;
        }
        else//se nao tiver espaço no cofre
            return NAO_TROCADO;
    else
        return SEM_RECURSOS;
}

resMA Mundo::mMaisMilitar() {
    if(flagMaisMilitar)
        return RE_M;

    if(imperio.getArmazem() > 1 && imperio.getCofre() > 1){//verifica se tem recursos para trocar
        if(imperio.getForcaMilitar() < imperio.getMaxMilitar()){
            imperio.setForcaMilitar(imperio.getForcaMilitar()+1);
            flagMaisMilitar = true;
            return ADQUIRIDO;
        }
        else
            return NAO_ADQUIRIDO;
    }
    else
        return RECURSOS;
}

resMA Mundo::mAdquire(const string &tipo) {
    if(flagMaisTecno)//verifica se já repetiu
        return RE_T;

    if(!verificaExistenciaTecnologia(tipo))//verifica se existe
        return NAO_ADQUIRIDO;

    if(verificaPrecoTecnologia(tipo) <= imperio.getCofre()){//verifica se tem recursos
        imperio.compraTecnologia(tipo);
        flagMaisTecno = true;
        return ADQUIRIDO;
    }
    else//nao tem recursos
        return RECURSOS;

}


// problema de so funciona se for passado Mina ou Montanha, se for passado mina ou montanha não da
void Mundo::mLista(const string &nome) const {
    for(const auto &x : territorios){
        if(x->getNome().find(nome) != string::npos){
            cout << x->getAsString() << endl;
        }
    }
}


void Mundo::mLista(){
    for(const auto &x : territorios){
        cout << x->getAsString() << endl;
    }
    for(const auto &x : imperio.getConquistados()){
        cout << "Conquistados: " << endl;
        cout << x->getAsString() << endl;
    }

}

void Mundo::mGrava(fase &phase, istringstream &iss) {

}

void Mundo::mAtiva(fase &phase, istringstream &iss) {

}

void Mundo::mApaga(fase &phase, istringstream &iss) {

}

resToma Mundo::mTomaTerr(const string &nome) {
    if(!verificaExistenciaTerritorio(nome)){
        return TERRITORIO_INEXISTENTE;
    }
    for(const auto &x : imperio.getConquistados()){
        if(x->getNome() == nome){
            return TERRITORIO_JA_CONQUISTADO;
        }
    }

    setConquistado(getTerritorioByName(nome));
    return TOMADO;
}

resToma Mundo::mTomaTech(const string &nome){
    if(!verificaExistenciaTecnologia(nome)) {
        return TECNOLOGIA_INEXISTENTE;
    }

    if(!imperio.verificaTecnologia(nome))
        return TECNOLOGIA_JA_ADQUIRIDA;

    imperio.compraTecnologia(nome);
    return TOMADO;
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
    //dá reset às flags no início de cada turno
    this->flagCP = false;
    this->flagOP = false;
    this->flagMaisMilitar = false;
    this->flagMaisTecno = false;
    this->flagInvasao = false;
}

void Mundo::mHarvest() const {

}


/*funções private que servem apenas para auxiliar as funlções public
 * só podem ser chamadas de dentro das funçoes public*/
string Mundo::mostraImperio() const {
    return std::string();
}

Territorio *Mundo::getTerritorioByName(string nome) {

    for(int i = 0; i < territorios.size(); i++){
        if(territorios[i]->getNome() == nome){
            Territorio* ptr = territorios[i];
            //territorios.erase(territorios.begin() + i);
            return ptr;
        }
    }

    return nullptr;
}

void Mundo::setConquistado(Territorio *ptr) {
    imperio.getConquistados().push_back(ptr);

    for(int i = 0; i < territorios.size(); i++){
        if(ptr->getNome() == territorios[i]->getNome())
            territorios.erase(territorios.begin()+i);
    }
}

bool Mundo::verificaNomeTerritorio(string nome) const {
    for(const auto& it : nomes)
        if(nome == it)
            return true;
    return false;
}

bool Mundo::verificaExistenciaTerritorio(string nome) const {
    for(const auto& it : territorios)
        if(it->getNome() == nome)
            return true;
    return false;
}

bool Mundo::verificaExistenciaTecnologia(string nome) const {
    for(const auto &it : imperio.getKeyValues())
        if(it == nome)
            return true;
    return false;
}

int Mundo::verificaPrecoTecnologia(string nome) const{
    auto mapa = imperio.getUnMap();
    for(const auto &it : mapa){
        if(it.first == nome)
            return get<int>(it.second);
    }
    return 0;
}
