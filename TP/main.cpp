#include <iostream>
#include <fstream>
#include <sstream>
#include "src/dados/h/Territorio.h"
#include "src/dados/h/Imperio.h"
#include "src/dados/h/Continente.h"
#include "src/dados/h/Ilha.h"
#include "src/funcoes/Utils.h"

using namespace std;

int main() {

    string linha;
    string palavra;
    Imperio ip;

    /* Territorio a;

    cout << a.getAsString() << endl;

    Continente b("Mina");
    Continente c("Mina");
        Continente d("Mina");
    Ilha e("Pescaria");
    Ilha f("Pescaria");
    cout << e.getAsString();
    cout << f.getAsString();
        cout << b.getAsString();
    cout << d.getAsString();

    cout << c.getAsString(); */


    istringstream iss;

    while(palavra != "exit"){
        cout << "Consola inicial do jogo.\n"
                "Comandos disponiveis:\tlista\tcria\tcarrega\tstart\t"
                "exit\n" << endl;
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
            // startJogo(ip);
        }
        else if(palavra == "conquista"){
            conquista(ip,iss);
        }
        else if(palavra == "mostraConquer"){ // teste para ver se fica no vetor dos conquistados
            MostraConquistados(ip);

        }
    }

    return 0;
}
