//
// Created by migue on 15/11/2020.
//

#include "../h/Imperio.h"
#include "../h/Continente.h"
#include "../h/Ilha.h"

// for autos com const &?

string Imperio::getAsString() const {
    ostringstream os;
    for(const auto &x : territorios){
        os << x.getAsString();
        os << endl;
    }
    //FALTA LISTAR TECNOLOGIAS
    return os.str();
}

vector<Territorio> Imperio::getTerritorios() const{
    return territorios;
}


void Imperio::mostra(const string &nome) const{
    for(const auto &x : territorios){
        if(x.getNome() == nome){ // N FUNCIONA PORQUE O NOME DA CENA É DUNA1 E ELE RECEBE COMO PARAMETRO DUNA;
            cout << "Abcd" << endl;
            cout << x.getAsString() << endl; 
            }
    }
}

void Imperio::mostra() const{
    for(const auto &x : territorios){
           cout << x.getAsString() << endl; 
    }
}


vector<string> Imperio::getNomesTerritorios() const {
    return nomes;
}

string Imperio::getAsString(const string &str) const {
    ostringstream os;
    for(const auto &x : territorios){
        if(x.getNome() == str){
            os << x.getAsString();
            os << endl;
        }
    }
    return os.str();
}

bool Imperio::criaTerritorios(const string &palavra,int n){
    for(int i=0;i<n;i++){
        if(palavra == "Pescaria" || palavra == "Refugio dos Piratas"){
            Ilha t(palavra);
            territorios.push_back(t);         
        }
        else{
            Continente c(palavra);
            territorios.push_back(c);
        }
    }
    return true;
}

// metodo para quando o jogo começa adicionar o territorio inicial ao vetor de territorios
void Imperio::inicial(){
    Territorio a;
    territorios.push_back(a);
    territConquistados.push_back(a);
}
