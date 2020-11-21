//
// Created by migue on 15/11/2020.
//

#include "../h/Imperio.h"

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
