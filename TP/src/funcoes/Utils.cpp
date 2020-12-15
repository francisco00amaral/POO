//
// Created by migue on 15/11/2020.
//

#include <algorithm>
#include "Utils.h"

//comandos pre jogo
bool cria(Imperio &ip, istringstream &iss){

    mostraNomes(ip);
    string palavra;
    bool flag = false;
    if((iss >> palavra).good())// verifica que e passado uma string;
        for(const auto &x : ip.getNomesTerritorios()){
            if (palavra == x)
                flag = true;
        }

    if(!flag){//se flag for ativada sai da função
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
    ifstream file;
    file.open(path);
    if(file.is_open()){
        while(getline(file, linha)){//lé linha a linha
            istringstream iss2(linha);//cada linha tem argumentos
            string str;
            iss2 >> str;
            flag = cria(ip, iss2);//enviar argumentos para a função que cria territorios
            cout << flag << true << endl;
            if(!flag){
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

void lista(Imperio &ip, istringstream &iss) {
    string palavra;

    if (!(iss >> palavra).fail()) {//garante que e introduzido uma string;
        for (const auto &x : ip.getNomesTerritorios()) { // verifica se nome passado existe
            if (palavra == x) { // / compara nome passado por argumento com os existentes
                ip.mostra(palavra);//envia tipo de territorio
            }
        }
    } else {
        ip.mostra();
    }
}

/* void startJogo(Imperio &ip){

} */ 


//auxiliar jogo
/* void runComandos(Imperio &ip){

} */

//comandos do jogo
bool conquista(Imperio &ip, istringstream &iss) {
    string palavra;
    if ((iss >> palavra).fail()){
        return false;
    }
    for (auto &x : ip.getTerritorios()) {
            if (palavra == x.getNome()) {
                ip.conquer(x);
                return true;
            }
        }
    for(const auto &x : ip.getConquistados()){
                if(palavra == x.getNome()) {
                    cout << "Territorio ja conquistado!" << endl;
                    return false;
                }
            }
        cout << "Territorio nao existente" << endl;
        return false;
}

void MostraConquistados(Imperio &ip){
    cout << "Territorios atualmente conquistados: " << endl;
    for(const auto &x : ip.getConquistados()){
        cout << x.getAsString() << endl;
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

/* void fase1(Imperio &ip,istringstream &iss,string comando){
    string palavra;
    if((iss >> palavra).fail()){
        cout << "Comando invalido." << endl;
        return;
    }
    if(palavra == "conquista") {
        conquista(ip, iss);
    }
    else if(comando == "passar"){
        return;
    }
}

void fase3(Imperio &ip,istringstream &iss,string comando){
    string palavra;
    string palavra2;
    if((iss >> palavra).fail()){
        cout << "Comando invalido." << endl;
        return;
    }
    if(palavra == "maismilitar"){
        // FAZ FUNCAO DE AUMENTAR FORCA MILITAR;
    }
    else if(palavra == "adquire"){
        if((iss >> palavra2).good()){// verifica que e passado uma string;
            // aqui vai percorrer um vetor com nomes de objetos de tecnologias e ver se existe;
            // depois vai ver se tem €€ para isso e desconta se tiver;
            }
        // VER SE TEM RECURSOS PARA ISSO
    }
    else if(comando == "avanca"){
        return;
    }

} */

void toLower(string& str){
    transform(str.begin(), str.end(), str.begin(), [](unsigned char c){
        return tolower(c);
    });
}