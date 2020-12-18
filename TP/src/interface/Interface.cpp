//
// Created by migue on 15/12/2020.
//

#include <Utils.h>
#include "Interface.h"

/*
 * interface precisa obrigatoriamente de um Manager,
 * pk n faz sentido um interface receber argumentos de input e n ter para onde os enviar
 * */
Interface::Interface(Manager &manager) : manager(manager){
    //this->manager = manager;
    //manager.init();
}

Interface::~Interface(){

}

/*
 * esta função tem como objetivo apresentar ao utilizador o menu pre-jogo
 * onde o utilizador pode preparar o ambiente da maneira que bem entender
*/
void Interface::startLoad() {

    string resposta;

    cout << "Bem vindo ao jogo." << endl;

    while(true){
        cout << "Comandos pre-jogo(preparacao):" << endl;
        cout << "cria\tcarrega\tlista\tstart\tsair\t" << endl;

        getline(cin, resposta);
        istringstream iss(resposta);
        if((iss >> resposta).fail()){
            cout << "Erro ao ler o comando.\n" << endl;
            continue;
        }

        toLower(resposta);

        if(resposta == "cria"){
            manager.cria(iss);
        }   else if(resposta == "carrega"){
            manager.carrega(iss);
        } else if(resposta == "lista"){
            manager.lista(iss);
        }else if(resposta == "start"){
            this->startGame();
        }
        else if(resposta == "sair"){
            exit(-1);
        }else
            cout << "Comando nao existente.\n" << endl;

    }

}


/*
 * esta função tem como objetivo apresentar as opções do jogo em si,
 * onde o utilizador de facto está a jogar
 * e pode controlar o seu territorio e fazer as suas escolhas
 */
void Interface::startGame(){

    int count = 0;
    string resposta;
    enum::fase phase = CONQUISTA;

    cout << "O jogo vai comecar. Boa sorte!!! :D" << endl;

    while(count < 12){//o jogo só tem 12 turnos

        //vai atualizar a informação dos territorios(upgrade)
        if(count == 6)
            manager.update();

        cout << manager.mostraImperio() << "\n" << endl;//mostra estado do imperio

        switch(phase){
            case CONQUISTA:
                faseConquista(manager, phase);
                break;
            case RECOLHA:
                faseRecolha(manager, phase);
                break;
            case COMPRA:
                faseCompra(manager, phase);
                break;
            case EVENTO:
                faseEvento(manager, phase);
                break;
        }


    }

}


void Interface::faseConquista(const Manager& manager, fase& phase){

    cout << "Comandos disponiveis:(o que esta entre <> sao os argumentos / ??? significa opcional)" << endl;
    cout << "conquista <nome>\tpassa\tlista <nome???>\ttoma <tipo> <nome>\n"
            "grava <nome>\tativa <nome>\tapaga <nome>" << endl;

    string resposta;
    getline(cin, resposta);
    istringstream iss(resposta);
    if((iss >> resposta).fail()){
        cout << "Erro ao ler o comando.\n" << endl;
        return;
    }

    toLower(resposta);

    if(resposta == "conquista")
        manager.conquista(phase, iss);
    else if(resposta == "passa")
        manager.passa(phase, iss);
    else if(resposta == "lista")
        manager.lista(iss);
    else if(resposta == "toma")
        manager.toma(phase, iss);
    else if(resposta == "grava")
        manager.grava(phase, iss);
    else if(resposta == "ativa")
        manager.ativa(phase, iss);
    else if(resposta == "apaga")
        manager.apaga(phase, iss);

}

void Interface::faseRecolha(const Manager& manager, fase& phase){

    manager.harvest();

    cout << "Comandos disponiveis:(o que esta entre <> sao os argumentos / ??? significa opcional)" << endl;
    cout << "maisouro <quantidade>\tmaisprod <quantidade>\tmodifica <tipo recurso> <quantidade pretendida>\n"
            "grava <nome>\tativa <nome>\tapaga <nome>" << endl;

    string resposta;
    getline(cin, resposta);
    istringstream iss(resposta);
    if((iss >> resposta).fail()){
        cout << "Erro ao ler o comando.\n" << endl;
        return;
    }

    toLower(resposta);

    if(resposta == "maisouro")
        manager.maisOuro(phase, iss);
    else if(resposta == "maisprod")
        manager.maisProduto(phase, iss);
    else if(resposta == "modifica")
        manager.modifica(phase, iss);
    else if(resposta == "grava")
        manager.grava(phase, iss);
    else if(resposta == "ativa")
        manager.ativa(phase, iss);
    else if(resposta == "apaga")
        manager.apaga(phase, iss);

}

void Interface::faseCompra(const Manager &manager, fase &phase) {

    cout << "Comandos disponiveis:(o que esta entre <> sao os argumentos / ??? significa opcional)" << endl;
    cout << "maismilitar\tadquire <tipo de tecnologia>\tmodifica <tipo de recurso> <quantidade>\tavanca\n"
            "grava <nome>\tativa <nome>\tapaga <nome>" << endl;

    string resposta;
    getline(cin, resposta);
    istringstream iss(resposta);
    if((iss >> resposta).fail()){
        cout << "Erro ao ler o comando.\n" << endl;
        return;
    }

    toLower(resposta);

    if(resposta == "maismilitar")
        manager.maisMilitar(phase, iss);
    else if(resposta == "adquire")
        manager.adquire(phase, iss);
    else if(resposta == "modifica")
        manager.modifica(phase, iss);
    else if(resposta == "avanca")
        manager.avanca(phase);
    else if(resposta == "grava")
        manager.grava(phase, iss);
    else if(resposta == "ativa")
        manager.ativa(phase, iss);
    else if(resposta == "apaga")
        manager.apaga(phase, iss);

}

void Interface::faseEvento(const Manager &manager, fase &phase) {

    cout << "Comandos disponiveis:(o que esta entre <> sao os argumentos / ??? significa opcional)" << endl;
    cout << "fevento <nome-evento???>\tgrava <nome>\tativa <nome>\tapaga <nome>" << endl;

    string resposta;
    getline(cin, resposta);
    istringstream iss(resposta);
    if((iss >> resposta).fail()){
        cout << "Erro ao ler o comando.\n" << endl;
        return;
    }

    toLower(resposta);

    if(resposta == "fevento")
        manager.fevento(phase, iss);
    else if(resposta == "grava")
        manager.grava(phase, iss);
    else if(resposta == "ativa")
        manager.ativa(phase, iss);
    else if(resposta == "apaga")
        manager.apaga(phase, iss);

}