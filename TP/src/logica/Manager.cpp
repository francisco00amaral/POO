//
// Created by migue on 15/12/2020.
//

#include <Utils.h>
#include "Manager.h"

Manager::Manager() {

}

Manager::~Manager() {

}

void Manager::init() {

}



//pre-jogo
void Manager::cria(istringstream &iss) {
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

}


void Manager::carrega(istringstream &iss) {
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

}



//durante o jogo
void Manager::conquista(fase phase, istringstream &iss) const {

    string nome;
    if((iss >> nome).fail()){
        cout << "Erro ao ler os argumentos passados." << endl;
        return;
    }

    toLower(nome);

    if(mundo.verificaExistenciaTerritorio(nome))
        mundo.mConquista(nome);
    else
        cout << "Territorio nao existe ou ja foi conquistado." << endl;

}


void Manager::passa(istringstream &iss) {
    if(mundo.mPassa())
        cout << "Troca efetuada com sucesso." << endl;
    else
        cout << "Troca nao efetuada com sucesso." << endl;

}


void Manager::maisOuro(istringstream& iss) {
    if(mundo.mMaisOuro())
        cout << "Troca efetuada com sucesso." << endl;
    else
        cout << "Troca nao efetuada com sucesso." << endl;

}


void Manager::maisProduto(istringstream& iss) {
    if(mundo.mMaisProduto())
        cout << "Troca efetuada com sucesso." << endl;
    else
        cout << "Troca nao efetuada com sucesso." << endl;

}


void Manager::maisMilitar(istringstream& iss) {
    if(mundo.mMaisMilitar())
        cout << "Troca efetuada com sucesso." << endl;
    else
        cout << "Troca nao efetuada com sucesso." << endl;

}


void Manager::adquire(istringstream &iss) {
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


void Manager::lista(istringstream &iss) const {
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


void Manager::grava(istringstream &iss) {
    //ainda falta aprender isto
}


void Manager::ativa(istringstream &iss) {
    //ainda falta aprender isto
}


void Manager::apaga(istringstream &iss){
    //ainda falta aprender isto
}


void Manager::toma(istringstream &iss) {
    string tipo;
    if((iss >> tipo).fail()){
        cout << "Erro ao obter os argumentos." << endl;
        return;
    }

    string nome;
    int tecnologia;
    if(tipo == "terr"){//escolhe territorio
        if((iss >> nome).fail()){
            cout << "Erro ao ler os argumentos." << endl;
            return;
        }

        enum::tomaRes res = mundo.mTomaTerr(nome);
        if(res == SUCCESS)
            cout << "Territorio tomado com sucesso." << endl;
        else
            cout << "Territorio nao existente." << endl;

        return;

    }else if(tipo == "tech"){//escolhe tecnologia
        if((iss >> tecnologia).fail()){
            cout << "Erro ao ler os argumentos." << endl;
            return;
        }

        enum::tomaRes res = mundo.mTomaTech(tecnologia);
        if(res == SUCCESS)
            cout << "Tecnologia adquirida com sucesso." << endl;
        else if(res == FAIL)
            cout << "Tecnologia ja desbloqueada anteriormente." << endl;
        else
            cout << "Tecnologia pedida nao existe." << endl;

        return;

    }

    //tipo escolhido nao existe
    cout << "Tipo nao reconhecido." << endl;

}


void Manager::modifica(istringstream &iss) {
    string tipo;
    if((iss >> tipo).fail()){
        cout << "Erro ao obter os argumentos." << endl;
        return;
    }

    toLower(tipo);

    int quant;
    enum::modRes res;
    if(tipo == "ouro"){
        if((iss >> quant).fail()){
            cout << "Erro ao ler os argumentos." << endl;
            return;
        }

        res = mundo.mModificaOuro(quant);
        if(res == OK)
            cout << "Alteracao feita com sucesso." << endl;
        else if(res == SPACE)
            cout << "Valor designado supera a capaciade maxima." << endl;
        else
            cout << "Valor negativo." << endl;

        return;

    }else if(tipo == "prod"){
        if((iss >> quant).fail()){
            cout << "Erro ao ler os argumentos." << endl;
            return;
        }

        res = mundo.mModificaProduto(quant);
        if(res == OK)
            cout << "Alteracao feita com sucesso." << endl;
        else if(res == SPACE)
            cout << "Valor designado supera a capaciade maxima." << endl;
        else
            cout << "Valor negativo." << endl;

        return;
    }

    cout << "Tipo inserido nao existe." << endl;

}


void Manager::fevento(istringstream &iss) {
    int numEvento;
    if((iss >> numEvento).fail()){
        cout << "Erro ao ler os argumentos." << endl;
        return;
    }

    if(mundo.mForceEvent(numEvento))
        cout << "Evento aplicado com sucesso." << endl;
    else
        cout << "Evento pedido nao existe." << endl;

}



//ocasião especial
//atualiza os valores de cada territorio(conquistados e nao conquistados) no turno 6
void Manager::update() {
    mundo.mUpdate();
}


void Manager::harvest() const {
    mundo.mHarvest();
}

//mostra info atual(status bar)
string Manager::mostraImperio() const {
    return mundo.getInfoImperio();
}


