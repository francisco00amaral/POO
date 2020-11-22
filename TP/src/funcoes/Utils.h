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
#include "../dados/h/Imperio.h"

using namespace std;

//comandos pre jogo
bool cria(Imperio &ip, istringstream &iss);
bool carrega(Imperio &ip, istringstream &iss);
void lista(Imperio &ip, istringstream &iss);
void startJogo(Imperio &ip);

//auxiliar jogo
void runComando(Imperio& ip);//corre comandos do jogo

//comandos do jogo
bool conquista(Imperio &ip, istringstream &iss);

// funcao de teste , pode dar jeito;
void MostraConquistados(Imperio &ip);

#endif //TP_UTILS_H
