#include <iostream>
#include <fstream>
#include <sstream>
#include "src/dados/h/Territorio.h"
#include "src/dados/h/Imperio.h"
#include "src/funcoes/Utils.h"

using namespace std;

int main() {

    string linha;
    string palavra;
    Imperio ip;

    while(palavra != "exit"){
        cout << "Consola inicial do jogo.\n"
                "Comandos disponiveis:\tlista\tcria\tcarrega\tstart\texit\n" << endl;
        cout << "Indique o comando:" << endl;
        getline(cin, linha);
        istringstream iss(linha);
        if((iss >> palavra).fail()){
            cout << "Comando invalido." << endl;
            continue;
        }
        if(palavra == "lista"){
            lista(ip, iss);
        }   else if(palavra == "cria"){
            cria(ip, iss);
        } else if(palavra == "carrega"){
            carrega(ip, iss);
        }else if(palavra == "start"){
            startJogo(ip);
        }
    }

    return 0;
}
