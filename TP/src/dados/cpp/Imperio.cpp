//
// Created by migue on 15/11/2020.
//

#include "../h/Imperio.h"
#include "../h/Ilha.h"
#include "../h/Continente.h"

string Imperio::getAsString() const {
    ostringstream os;
    for(auto x : territorios){
        os << x.getAsString();
        os << endl;
    }
    //FALTA LISTAR TECNOLOGIAS
    return os.str();
}

vector<Territorio> Imperio::getTerritorios() const{
    return territorios;
}

void Imperio::mostra(string nome) const{
    for(auto x : territorios){
        if(x.getNome() == nome){
            cout << x.getAsString() << endl; 
            }
    }
}

void Imperio::mostra() const{
    for(auto x : territorios){
           cout << x.getAsString() << endl; 
    }
}


vector<string> Imperio::getNomesTerritorios() const {
    return nomes;
}

string Imperio::getAsString(string str) const {
    ostringstream os;
    for(auto x : territorios){
        if(x.getNome().compare(str)){
            os << x.getAsString();
            os << endl;
        }
    }
    return os.str();
}

bool Imperio::criaTerritorios(string palavra,int n){
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