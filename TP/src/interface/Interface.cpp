//
// Created by migue on 15/12/2020.
//

#include <Utils.h>
#include "Interface.h"

/*
 * interface precisa obrigatoriamente de um Trigger,
 * pk n faz sentido um interface receber argumentos de input e n ter para onde os enviar
 * */
//Interface::Interface(Trigger &manager) : manager(manager){}

Interface::Interface(){}

Interface::~Interface(){}

/*
 * esta função tem como objetivo apresentar ao utilizador o menu pre-jogo
 * onde o utilizador pode preparar o ambiente da maneira que bem entender
*/
void Interface::startLoad() {

    string resposta;

    cout << "Bem vindo ao jogo." << endl;
    manager.criaInicial();

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
            return;
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

    int count = 1;
    string resposta;
    enum::fase phase = CONQUISTA;

    cout << "O jogo vai comecar. Boa sorte!!! :D" << endl;

    while(count < 12){//o jogo só tem 12 turnos
        cout << "\n\n" << "Turno " << count << endl;
        cout << manager.mostraImperio() << "\n" << endl;//mostra estado do imperio

        switch(phase){
            case CONQUISTA:
                faseConquista(phase, count);
                break;
            case RECOLHA:
                faseRecolha(phase, count);
                break;
            case COMPRA:
                faseCompra(phase, count);
                break;
            case EVENTO:
                faseEvento(phase, count);
                break;
            case AVANCA: // NAO FACO A MENOR IDEIA PORQUE E Q ELE NAO ENTRA AQUI
                manager.update(count);//reseta as flags de repetição
                Trigger::novoTurno(phase, count);
                count++;
                break;
            case FIM:
                count = 12;
                break;
        }

    }

    fim();

}


/*código correspondente a cada fase do jogo*/
void Interface::faseConquista(fase& phase, int& turn){

    cout << "Comandos disponiveis:(o que esta entre <> sao os argumentos / ? significa opcional)" << endl;
    cout << "conquista <nome>\tpassa\tlista <nome?>\ttoma <tipo> <nome>\tavanca\n"
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
        manager.conquista(iss, phase);
    else if(resposta == "passa")
        manager.passa();
    else if(resposta == "lista")
        manager.lista(iss);
    else if(resposta == "avanca")
        manager.avanca(phase);
    else if(resposta == "toma")
        manager.toma(iss);
    else if(resposta == "grava")
        manager.grava(phase, iss, turn);
    else if(resposta == "ativa")
        manager.ativa(phase, iss, turn);
    else if(resposta == "apaga")
        manager.apaga(iss);
    else if(resposta == "sair"){
        phase = FIM;
    }

}

void Interface::faseRecolha(fase& phase, int& turn){

    manager.harvest();

    cout << "Comandos disponiveis:(o que esta entre <> sao os argumentos / ? significa opcional)" << endl;
    cout << "maisouro <quantidade>\tmaisprod <quantidade>\tavanca\n"
            "modifica <tipo recurso> <quantidade pretendida>\tgrava <nome>\tativa <nome>\tapaga <nome>" << endl;

    string resposta;
    getline(cin, resposta);
    istringstream iss(resposta);
    if((iss >> resposta).fail()){
        cout << "Erro ao ler o comando.\n" << endl;
        return;
    }

    toLower(resposta);

    if(resposta == "maisouro")
        manager.maisOuro(iss);
    else if(resposta == "maisprod")
        manager.maisProduto(iss);
    else if(resposta == "avanca")
        manager.avanca(phase);
    else if(resposta == "modifica")
        manager.modifica(iss);
    else if(resposta == "grava")
        manager.grava(phase, iss, turn);
    else if(resposta == "ativa")
        manager.ativa(phase, iss, turn);
    else if(resposta == "apaga")
        manager.apaga(iss);
    else if(resposta == "sair"){
        phase = FIM;
    }

}

void Interface::faseCompra(fase &phase, int& turn) {

    cout << "Comandos disponiveis:(o que esta entre <> sao os argumentos / ? significa opcional)" << endl;
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
        manager.maisMilitar(iss);
    else if(resposta == "adquire")
        manager.adquire(iss);
    else if(resposta == "avanca")
        manager.avanca(phase);
    else if(resposta == "modifica")
        manager.modifica(iss);
    else if(resposta == "grava")
        manager.grava(phase, iss, turn);
    else if(resposta == "ativa")
        manager.ativa(phase, iss, turn);
    else if(resposta == "apaga")
        manager.apaga(iss);
    else if(resposta == "sair"){
        phase = FIM;
    }

}

void Interface::faseEvento(fase &phase, int& turn) {
    cout << "Comandos disponiveis:(o que esta entre <> sao os argumentos / ? significa opcional)" << endl;
    cout << "fevento <nome-evento?>\tgrava <nome>\tativa <nome>\tapaga <nome>" << endl;

    manager.evento(turn); // AQUI VAI ACONTECER O EVENTO RANDOM

    string resposta;
    getline(cin, resposta);
    istringstream iss(resposta);
    if((iss >> resposta).fail()){
        cout << "Erro ao ler o comando.\n" << endl;
        return;
    }

    toLower(resposta);

    if(resposta == "fevento")
        manager.fevento(iss,turn);
    else if(resposta == "avanca")
        manager.avanca(phase);
    else if(resposta == "grava")
        manager.grava(phase, iss, turn);
    else if(resposta == "ativa")
        manager.ativa(phase, iss,turn);
    else if(resposta == "apaga")
        manager.apaga(iss);
    else if(resposta == "sair"){
        phase = FIM;
    }
}

void Interface::fim(){
    cout << "\n\n-------Chegou ao fim.-------\n" << endl;
    manager.mostraResultadoFinal();
}