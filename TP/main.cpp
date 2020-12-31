#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include "interface/Interface.h"
#include "src/dados/h/Territorio.h"
#include "src/dados/h/Imperio.h"
#include "src/dados/h/Continente.h"
#include "src/dados/h/Ilha.h"
#include "src/funcoes/Utils.h"

using namespace std;

int main() {

    Manager manager;
    Interface interface(manager);

//    Interface interface;

    //começa ciclo de preparação
    interface.startLoad();

    return 0;
}
