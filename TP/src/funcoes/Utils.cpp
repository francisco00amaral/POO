//
// Created by migue on 15/11/2020.
//

#include "Utils.h"




//comandos pre jogo
bool cria(Imperio &ip, istringstream &iss) {
    string palavra;
    bool flag = false;

    if ((iss >> palavra).fail())//verifica se existe o tipo de territorio pedido
        for(auto x : ip.getNomesTerritorios())
            if(palavra == x)
                flag = true;
    if(!flag){//se flag for ativada sai da função
        cout << "Nao ha territorios com o nome indicado.(cria)" << endl;
        return false;
    }

    int val;
    if ((iss >> val).fail())
        if (val < 0) {
            cout << "Valor impossivel.(cria)" << endl;
            return false;
        }

    return ip.criaTerritorios(palavra, val);
}

bool carrega(Imperio &ip, istringstream &iss){
    string path, linha;
    bool flag = false;
    if((iss >> path).fail()){
        cout << "Path incorreto." << endl;
        return false;
    }
    ifstream file(path);
    if(file.is_open()){
        while(getline(file, linha)){//lé linha a linha
            istringstream iss2(linha);//cada linha tem argumentos
            flag = cria(ip, iss2);//enviar argumentos para a função que cria territorios
            if(flag){
                cout << "Erro ao criar territorios(carrega)." << endl;
            }
        }
        file.close();
    }else{
        cout << "Nao foi possivel abrir o ficheiro pretendido.(carrega)" << endl;
        return false;
    }
}

void lista(Imperio &ip, istringstream &iss){
    string palavra;
    bool flag = false;

    if ((iss >> palavra).fail()){//verifica se existe o tipo de territorio pedido
        for(auto x : ip.getNomesTerritorios()){//percorre vetor com nomes
            if(palavra == x){//compara nome com os existentes
                ip.mostra(palavra);
                flag = true;
            }
        }
    }
    if(flag == false){
        cout << "Nao ha territorios com esse nome.(lista)" << endl;
        cout << "Listando o mundo todo: " << endl;
        ip.mostra();
    }
}

void startJogo(Imperio &ip){

}


//auxiliar jogo
void runComandos(Imperio &ip){

}

//comandos do jogo
bool conquista(Imperio &ip, istringstream &iss){
    bool confirm = false;
    return confirm;
}
