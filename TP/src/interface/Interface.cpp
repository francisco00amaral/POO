//
// Created by migue on 15/12/2020.
//

#include <Utils.h>
#include "Interface.h"

/*
 * interface precisa obrigatoriamente de um LogicManager,
 * pk n faz sentido um interface receber argumentos de input e n ter para onde os enviar
 * */
Interface::Interface(LogicManager &manager) {
    this->manager = manager;
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

    cout << "O jogo vai comecar. Boa sorte ;)" << endl;

    while(count < 12){//o jogo só tem 12 turnos

        //vai atualizar a informação dos territorios(upgrade)
        if(count == 6)
            manager.update();

        cout << manager.mostraImperio() << "\n" << endl;

        cout << "Comandos disponiveis:(o que esta entre <> sao os argumentos)" << endl;
        cout << "conquista\tpassa\tmaisouro\tmaisprod\tmaismilitar\n"
                "adquire<tipo>\tlista<nome>\tgrava<nome do save>\tativa<nome do save>\ttoma<qual><nome>\n"
                "modifica<ouro|prod> N\tfevento<nome do evento>\tavanca\tsair" << endl;

        getline(cin, resposta);
        istringstream iss(resposta);
        if((iss >> resposta).fail()){
            cout << "Erro ao ler o comando.\n" << endl;
            continue;
        }

        //transforma a resposta recebida para lower case
        toLower(resposta);


        //AINDA FALTA VER MELHOR A ORDEM DO TURNO
        //E IMPEDIR QUE SEJAM REPETIDAS AS AÇÕES
        //PROVAVELMENTE TIRAR DÚVIDAS COM A PROFESSORA???
        if(resposta == "conquista"){
            manager.conquista(iss);
        }else if(resposta == "passa"){
            manager.passa();
        }else if(resposta == "maisouro"){
            manager.maisOuro();
        }else if(resposta == "maisprod"){
            manager.maisProduto();
        }else if(resposta == "maismilitar"){
            manager.maisMilitar();
        }else if(resposta == "adquire"){
            manager.adquire(iss);
        }else if(resposta == "lista"){
            manager.lista(iss);
        }else if(resposta == "grava"){
            manager.grava(iss);
        }else if(resposta == "ativa"){
            manager.ativa(iss);
        }else if(resposta == "toma"){//DEBUG
            manager.toma(iss);
        }else if(resposta == "modifica"){//DEBUG
            manager.modifica(iss);
        }else if(resposta == "fevento"){//DEBUG
            manager.fevento(iss);
        }else if(resposta == "avanca"){
            ++count;
        }else if(resposta == "sair"){
            exit(-2);
        }
        else
            cout << "Comando nao existente.\n" << endl;

    }

}
