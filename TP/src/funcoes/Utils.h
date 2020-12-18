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
#include <algorithm>
#include "../dados/h/Imperio.h"

using namespace std;


//passa strings para lower case
void toLower(string& str);

//Enumerações
/*são usadas em certas funções para definir o resultado da função
 * como por exemplo, se a função tiver 3 ou mais resultados diferentes*/

enum fase{CONQUISTA, RECOLHA, COMPRA, EVENTO};//define a fase do turno

enum modRes{OK, SPACE, NEGATIVE};//resultado da função mModifica

enum tomaRes{SUCCESS, FAIL, UNKNOWN};//resultado da função mTomaTerr e mTomeTech

#endif //TP_UTILS_H
