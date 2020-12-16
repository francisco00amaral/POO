//
// Created by migue on 15/11/2020.
//

#ifndef TP_UTILS_H
#define TP_UTILS_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "../dados/h/Imperio.h"

using namespace std;

//comandos pre jogo
void startJogo(Imperio &ip);
bool cria(Imperio &ip, istringstream &iss);
void mostraNomes(Imperio &ip);
bool carrega(Imperio &ip, istringstream &iss);
void lista(Imperio &ip, istringstream &iss);
void fase1(Imperio &ip,istringstream &iss,string comando);
void fase3(Imperio &ip,istringstream &iss,string comando);


//auxiliar jogo
void runComando(Imperio& ip);//corre comandos do jogo

//comandos do jogo
bool conquista(Imperio &ip, istringstream &iss);

// funcao de teste , pode dar jeito;
void MostraConquistados(Imperio &ip);

//passa strings para lower case
void toLower(string& str);


#endif //TP_UTILS_H
