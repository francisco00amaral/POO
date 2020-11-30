#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include "src/dados/h/Territorio.h"
#include "src/dados/h/Imperio.h"
#include "src/dados/h/Continente.h"
#include "src/dados/h/Ilha.h"
#include "src/funcoes/Utils.h"

using namespace std;

int main() {
    srand(time(0));
    string linha;
    string palavra;
    Imperio ip;

    ip.inicial(); // serve para adicionar o Territorio inicial aos vetor de territoriso total e conquistados
    // interpretacao que tive do enunciado é que ele começa com o territorio incial já "conquistado"


    // istringstream iss;
    cout << "\nBem vindo ao jogo single-player de conquista e expansao territorial" << endl;

    int turnos = 0;
    cout << "Inicio de jogo" << endl;
    // VER ESTA PARTE DE TROCAS DE PRODUTOS POR OURO
    while(palavra != "avanca"){
        // COMPOR ISTO BLA BLA
        cout <<  "Comandos disponiveis:\tlista\tcria\tcarrega\tstart\t" << endl;
        cout << "Indique o comando:" << endl;
        getline(cin, linha);
        istringstream iss(linha);
        if((iss >> palavra).fail()){
            cout << "Comando invalido." << endl;
            continue;
        }
        if(palavra == "lista"){
            lista(ip,iss);
        }   else if(palavra == "cria"){
            cria(ip, iss);
        } else if(palavra == "carrega"){
            carrega(ip, iss);
        }else if(palavra == "start"){
            startJogo(ip);
        }
        else if(palavra == "conquista"){
            conquista(ip,iss);
        }
        else if(palavra == "mostraConquer"){ // teste para ver se fica no vetor dos conquistados
            MostraConquistados(ip);
            ip.getAsString();
        }
    }


    return 0;
}
