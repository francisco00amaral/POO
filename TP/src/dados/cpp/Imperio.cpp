//
// Created by migue on 15/11/2020.
//

#include "../h/Imperio.h"
#include "../h/Continente.h"


Imperio::Imperio(){}

Imperio::Imperio(const Imperio& aCopiar){
    this->territConquistados = aCopiar.territConquistados;
    this->tecnologias = aCopiar.tecnologias;
    this->maxMilitar = aCopiar.maxMilitar;
    this->forcaMilitar = aCopiar.forcaMilitar;
    this->maxArmazem = aCopiar.maxArmazem;
    this->armazem = aCopiar.armazem;
    this->maxCofre = aCopiar.maxCofre;
    this->cofre = aCopiar.cofre;
}

Imperio::~Imperio(){
    for(const auto& p : territConquistados)//apaga informação para onde os ponteiros estão a apontar
        delete p;
    territConquistados.clear();//apaga os pointers
}

vector <Territorio*>& Imperio::getConquistados(){ return territConquistados;}

bool Imperio::verificaTecnologia(const string &nome) const {
    //acede ao value(tuple) e acede ao primeiro valor dele(tuple<bool, int>)
    //este get podia ser feito por index, mas a partir do c++14 pode se usar o tipo do dado
    //https://en.cppreference.com/w/cpp/utility/tuple/get
    for(const auto &it : tecnologias){
        if(it.first == nome){//verifica key
            if(!get<bool>(it.second)){ // SE ELE AINDA NAO TEM A TECNOLOGIA
                return false;
            }
            else{
                return true;
            }
        }
    }
    return false;
}

int Imperio::getForcaMilitar() const { return forcaMilitar;}

void Imperio::setForcaMilitar(int val) { forcaMilitar = val;}

int Imperio::getCofre() const { return cofre;}

void Imperio::setCofre(int val) { cofre = val;}

int Imperio::getArmazem() const { return armazem;}

void Imperio::setArmazem(int val) { armazem = val;}

void Imperio::updateMilitar() {  maxMilitar = 5;}

int Imperio::getMaxMilitar() const { return maxMilitar;}

void Imperio::setMaxMilitar(){
    if(verificaTecnologia("drones")){
        maxMilitar = 5;
    }
}

void Imperio::updateOP() {
    maxArmazem = 5;
    maxCofre = 5;
}

int Imperio::getMaxCofre() const { return maxCofre;}

void Imperio::setMaxCofre(){
    if(verificaTecnologia("drones")){
        maxCofre = 5;
    }
}

int Imperio::getMaxArmazem() const{ return maxArmazem;}

void Imperio::setMaxArmazem(){
    if(verificaTecnologia("banco")){
        maxArmazem = 5;
    }
}

vector<string>& Imperio::getKeyValues() const{
    static vector<string> nomes;
    for(const auto& it : tecnologias)
        nomes.push_back(it.first);
    return nomes;
}

unordered_map<string, tuple<bool, int>> Imperio::getUnMap() const{ return tecnologias;}

void Imperio::compraTecnologia(const string &nome) {
    for(auto &it : tecnologias){
        if(it.first == nome){
            tuple<bool, int> &tp = it.second;
            get<bool>(tp) = true;
        }
    }
}

string Imperio::toString() const{
    ostringstream oss;

    //ouro, produtos e militar
    oss << "Cofre: " << cofre << "/" << maxCofre << "\t" <<
           "Armazem: " << armazem << "/" << maxArmazem << "\t" <<
           "Forca militar: " << forcaMilitar << "/" << maxMilitar << endl;
    oss << endl;

    //tecnologias
    oss << "Tecnologias:\n";
    for(const auto &it : tecnologias)
            oss << "\t" << it.first << "\t Custo: " << get<int>(it.second) << "\tEstado:" << get<bool>(it.second) << endl;
    oss << endl;

    //territorios
    oss << "Territorios conquistados:" << endl;
    for(const auto &it : territConquistados)
        oss << "\t" << it->getAsString() << endl;

    return oss.str();
}