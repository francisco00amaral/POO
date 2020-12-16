//
// Created by migue on 15/12/2020.
//

#include <Utils.h>
#include "LogicManager.h"

LogicManager::LogicManager() {

}

LogicManager::~LogicManager() {

}

void LogicManager::init() {

}



//pre-jogo
void LogicManager::cria(istringstream &iss) {
    string tipo;
    if((iss >> tipo).fail()){
        cout << "Erro ao criar territorio(s)." << endl;
        return;
    }

    toLower(tipo);

    if(!mundo.verificaExistenciaTerritorio(tipo)){
        cout << "Tipo de territorio passado nao existe." << endl;
        return;
    }

    int quant;
    if((iss >> quant).fail()){
        cout << "Quantidade invalida." << endl;
        return;
    }

    mundo.mCria(tipo, quant);

    iss.clear();//para prevenir caso o utilizador tenha posto algum input a mais que n faça sentido
}


void LogicManager::carrega(istringstream &iss) {
    string path;
    if((iss >> path).fail()){
        cout << "Erro ao obter o nome do ficheiro." << endl;
        return;
    }

    ifstream file;
    file.open(path);
    if(file.is_open()){

        string linha;
        while(getline(file, linha)){

            istringstream iss2(linha);
            string tipo;
            int quant;

            if((iss2 >> tipo).fail()){
                cout << "Erro ao ler os argumentos do ficheiro." << endl;
                return;
            }else{
                toLower(tipo);
                if((iss2 >> quant).fail()){
                    cout << "Erro ao ler os argumentos do ficheiro." << endl;
                    return;
                }
            }
            mundo.mCria(tipo, quant);
        }

    }else{
        cout << "Erro ao abrir o ficheiro pretendido." << endl;
        return;
    }

    iss.clear();
}






//durante o jogo
void LogicManager::conquista(istringstream &iss) {

    string nome;
    if((iss >> nome).fail()){
        cout << "Erro ao ler os argumentos passados." << endl;
        return;
    }

    //TODO verificar se fazer tolower de um int dá erro
    //toLower(nome);

    if(mundo.verificaExistenciaTerritorio(nome))
        mundo.mConquista(nome);
    else
        cout << "Territorio nao existe ou ja foi conquistado." << endl;

}


void LogicManager::passa() {
    if(mundo.mPassa())
        cout << "Troca efetuada com sucesso." << endl;
    else
        cout << "Troca nao efetuada com sucesso." << endl;
}


void LogicManager::maisOuro() {
    if(mundo.mMaisOuro())
        cout << "Troca efetuada com sucesso." << endl;
    else
        cout << "Troca nao efetuada com sucesso." << endl;
}


void LogicManager::maisProduto() {
    if(mundo.mMaisProduto())
        cout << "Troca efetuada com sucesso." << endl;
    else
        cout << "Troca nao efetuada com sucesso." << endl;
}


void LogicManager::maisMilitar() {
    if(mundo.mMaisMilitar())
        cout << "Troca efetuada com sucesso." << endl;
    else
        cout << "Troca nao efetuada com sucesso." << endl;
}


void LogicManager::adquire(istringstream &iss) {
    int tipo;
    if((iss >> tipo).fail()){
        cout << "Erro ao ler os argumentos passados." << endl;
        return;
    }

    if(tipo > 5 || tipo < 1){
        cout << "Tipo nao existente." << endl;
        return;
    }

    if(mundo.mAdquire(tipo))
        cout << "Tecnologia obtida com sucesso." << endl;
    else
        cout << "Tecnologia nao obtida." << endl;
}

void LogicManager::lista(istringstream &iss) const {
    string nome;
    if((iss >> nome).fail())
        mundo.mLista();

    toLower(nome);

    if(mundo.verificaExistenciaTerritorio(nome))
        mundo.mLista(nome);
    else{
        cout << "Territorio nao existente. A mostrar todos os territorios existentes." << endl;
        mundo.mLista();
    }

}

void LogicManager::grava(istringstream &iss) {
    //ainda falta aprender isto
}


void LogicManager::ativa(istringstream &iss) {
    //ainda falta aprender isto
}


void LogicManager::apaga(istringstream &iss){
    //ainda falta aprender isto
}


void LogicManager::toma(istringstream &iss) {
    string tipo;
    if((iss >> tipo).fail()){
        cout << "Erro ao obter os argumentos." << endl;
        return;
    }

    string nome;
    int tecnologia;
    if(tipo == "terr"){//escolhe territorio
        if((iss >> nome).fail()){//verifica integridade dos argumentos
            cout << "Erro ao ler os argumentos." << endl;
            return;
        }
        if(mundo.verificaExistenciaTerritorio(nome))//verifica se existe
            mundo.mTomaTerr(nome);
        else{//nao existe
            cout << "Territorio nao existente." << endl;
            return;
        }
    }else if(tipo == "tech"){//escolhe tecnologia
        if((iss >> tecnologia).fail()){//verifica integridade dos argumentos
            cout << "Erro ao ler os argumentos." << endl;
            return;
        }
        if(tecnologia > 5 || tecnologia < 1){
            cout << "Tecnologia nao existente." << endl;
        }else{
            if(mundo.mTomaTech(tecnologia))
                cout << "Tecnologia adquirida com sucesso." << endl;
            else
                cout << "Tecnologia ja adquirida anteriormente." << endl;
        }
    }else{
        cout << "Tipo nao reconhecido." << endl;
        return;
    }
}


void LogicManager::modifica(istringstream &iss) {
    string tipo;
    if((iss >> tipo).fail()){
        cout << "Erro ao obter os argumentos." << endl;
        return;
    }

    toLower(tipo);

    int quant;
    if(tipo == "ouro"){
        if((iss >> quant).fail()){
            cout << "Erro ao ler os argumentos." << endl;
            return;
        }
        //TODO esta parte pode ser resolvida com Enums(para saber o resultado/n me apetece usar ints e quero dar flex)
//        if(quant > mundo.get || quant < 1){
//            cout << "Quantidade fora do intervalo definido." << endl;
//                return;
//        }
    }else if(tipo == "prod"){
        if((iss >> quant).fail()){
            cout << "Erro ao ler os argumentos." << endl;
            return;
        }
        //TODO esta parte pode ser resolvida com Enums(para saber o resultado/n me apetece usar ints e quero dar flex)
//        if(quant > mundo.get || quant < 1){
//            cout << "Quantidade dora do intervalo definido." << endl;
//            return;
//        }
    }else{
        cout << "Tipo inserido nao existe." << endl;
        return;
    }
}


void LogicManager::fevento(istringstream &iss) {
    int numEvento;
    if((iss >> numEvento).fail()){
        cout << "Erro ao ler os argumentos." << endl;
        return;
    }

    //TODO esta parte pode ser resolvida com Enums(para saber o resultado/n me apetece usar números mágicos(ints) e quero dar flex)
//    mundo.mFevento();

}


//ocasião especial
void LogicManager::update() {
    mundo.mUpdate();
}


//mostra info atual(status bar)
string LogicManager::mostraImperio() const {
    return mundo.getInfoImperio();
}

