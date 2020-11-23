//
// Created by migue on 15/11/2020.
//

#include "Utils.h"

//comandos pre jogo
bool cria(Imperio &ip, istringstream &iss){
    mostraNomes(ip);
    string palavra;
    bool flag = false;
    if((iss >> palavra).good())// verifica que e passado uma string;
        for (const auto &x : ip.getNomesTerritorios()){
            if (palavra == x)
                flag = true;
        }

    if(flag == false){//se flag for ativada sai da função
        cout << "Sintaxe para criar territorios -> <cria> Tipo <numero>" << endl;
        cout << "Impossivel criar territorios com o nome indicado.(cria)" << endl;
        return false;
    }

    int val;
    if (!((iss >> val).fail())){ // garante que é passado um inteiro
        cout << val << endl;
        if (val < 0) {
            cout << "Valor impossivel.(cria)" << endl;
            return false;
        }
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
    return true;
}

void lista(Imperio &ip, istringstream &iss){
    string palavra;
    bool flag = false;
    iss >> palavra;

   // if ((iss >> palavra).good()){//garante que e introduzido uma string;
        cout << "Palavra ta boa" << endl;
        for(const auto &x : ip.getNomesTerritorios()){ // percorre vetor com nomes
            if(palavra == x){ // / compara nome passado por argumento com os existentes
                cout << "palavra existe no vetor de nomes" << endl;
                ip.mostra(palavra);
                flag = true;
            }
        }
    if(!(flag)){
        cout << "Nao existem territorios com esse nome.(lista)" << endl;
        cout << "Listando o mundo todo: " << endl;
        ip.mostra();
    }
}

/* void startJogo(Imperio &ip){

} */ 


//auxiliar jogo
/* void runComandos(Imperio &ip){

} */

//comandos do jogo
bool conquista(Imperio &ip, istringstream &iss){
    string palavra;
    iss >> palavra;
    // if((iss >> palavra).good()){
        cout << "ssss ss ss " << endl;
        for(const auto &x : ip.getTerritorios()){
            if(palavra == x.getNome()){
                cout << "ta conquistado ate saltas" << endl;
                ip.conquer(x); // falta verificar se dá para conquistar, ver resistencias bla bla
                return true;
            }
        }

    return false;
}

void MostraConquistados(Imperio &ip){
    cout << "Territorios atualmente conquistados: " << endl;
    for(const auto &x : ip.getConquistados()){
        cout << x.getNome() << endl;
    }
}

void mostraNomes(Imperio &ip){
    cout << "Lista de territorios que pode  criar: " << endl;
    for(const auto &x : ip.getNomesTerritorios()){
        cout << x << "     ";
    }
    cout << endl;
}

void startJogo(Imperio &ip){
    ip.inicial();
}