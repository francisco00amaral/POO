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

//Enumerações
/*são usadas em certas funções para definir o resultado da função
 * como por exemplo, se a função tiver 3 ou mais resultados diferentes*/

enum fase{CONQUISTA, RECOLHA, COMPRA, EVENTO, AVANCA, FIM};//define a fase do turno

/*resultados possiveis da função mCria*/
enum resCria{CRIADO, TIPO_INEXISTENTE, QUANTIDADE_NEGATIVA};

/*resultados possiveis da funcao mConquista*/
enum resConquista{CONQUISTADO, NAO_CONQUISTADO, INEXISTENTE, SEM_MISSEIS, RE_CP, PERDEU_CP};

/*resultados das funcoes maisOuro e maisProd */
enum resMaisOP{TROCADO, NAO_TROCADO, SEM_RECURSOS, SEM_BOLSA, RE_OP};

/*resultados das funcoes mMaisMilitar e mAdquire*/
enum resMA{ADQUIRIDO, NAO_ADQUIRIDO, RECURSOS, JA_ADQUIRDA, RE_M, RE_T};

/*resultados da funcao mToma*/
enum resToma{TOMADO, TERRITORIO_INEXISTENTE,TERRITORIO_JA_CONQUISTADO,TECNOLOGIA_INEXISTENTE, TECNOLOGIA_JA_ADQUIRIDA};

/*resultados da funcao mModifica*/
// enum resModifica{MODIFICADO, VAL_NEGATIVO, VAL_ACIMA_MAX};

//passa strings para lower case
void toLower(string& str);

#endif //TP_UTILS_H
