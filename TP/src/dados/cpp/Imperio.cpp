//
// Created by migue on 15/11/2020.
//

#include "../h/Imperio.h"
#include "../h/Continente.h"
#include "../h/Ilha.h"


//string Imperio::getAsString() const {
//    ostringstream os;
//    for(const auto &x : territorios){
//        os << x.getAsString();
//        os << endl;
//    }
//    //FALTA LISTAR TECNOLOGIAS
//    return os.str();
//}
//
//vector<Territorio>& Imperio::getTerritorios(){
//    return territorios;
//}
//
////recebe tipo de territorio e mostra todos os territorios do mesmo tipo
//void Imperio::mostra(const string &nome) const{
//    for(const auto &x : territorios){
//        if(x.getNome().find(nome) != string::npos){
//            cout << x.getAsString() << endl;
//            }
//    }
//    cout << endl;
//    for(const auto &x : territConquistados){
//        if(x.getNome().find(nome) != string::npos){
//            cout << "Conquistados" << endl;
//            cout << x.getAsString() << endl;
//        }
//    }
//}
//
//void Imperio::mostra() const{
//    for(const auto &x : territorios){
//           cout << x.getAsString() << endl;
//    }
//    cout << endl;
//
//    for(const auto &x : territConquistados){
//        cout << "Territorios conquistados: ";
//        cout << x.getAsString() << endl;
//    }
//}
//
//
//vector<string> Imperio::getNomesTerritorios() const {
//    return nomes;
//}
//
//string Imperio::getAsString(const string &str) const {
//    ostringstream os;
//    for(const auto &x : territorios){
//        if(x.getNome() == str){
//            os << x.getAsString();
//            os << endl;
//        }
//    }
//    return os.str();
//}
//
//bool Imperio::criaTerritorios(string &palavra,int n){
//    for(int i=0;i<n;i++){
//        if(palavra == "Pescaria" || palavra == "Refugio"){
//            Ilha t(palavra);
//            territorios.push_back(t);
//        }
//        else{
//            Continente c(palavra);
//            territorios.push_back(c);
//        }
//    }
//    return true;
//}
//
//// metodo para quando o jogo começa adicionar o territorio inicial ao vetor de territorios
//void Imperio::inicial(){
//    Territorio a;
//    territorios.push_back(a);
//    territConquistados.push_back(a);
//}
//
//
//void Imperio::conquer(Territorio t){
//
//    int sorte = (rand() % 6) + 1; // NUMERO ALEATORIO ENTRE 1 E 6 INCLUSIVE;
//    int forca = forcaMilitar;
//    forca += sorte;
//
//    vector<Territorio>::iterator  it = territorios.begin();
//
//    for(int i = 0; i < territorios.size(); i++){
//        if(t.getNome() == territorios[i].getNome()){
//            if(t.getRes() < forca){//conquista
//                territorios.erase(it + i);
//                territConquistados.push_back(t);
//            }
//            else{//n conquista
//                cout << "Nao foi possivel conquistar o territorio " << t.getNome() << endl;
//                forcaMilitar--;
//                if(forcaMilitar < 0)
//                    forcaMilitar = 0;
//            }
//        }
//    }
//
//}
//
//// POR AGORA ASSIM FUNCIONA, MAS QUANDO ACRESCENTARMOS AQUELAS CENAS Q AUMENTAM ESPAÇO COFRE VAI TER MUDANÇA
//void Imperio::adicionaProd(const Territorio &t){
//    armazem += t.getProd();
//            if(armazem > 3)
//                armazem = 3;
//}
//
//
//
//void Imperio::adicionaOuro(const Territorio &t){
//        cofre += t.getOuro();
//        if(cofre > 3)
//            cofre = 3;
//}

Imperio::Imperio(){

}

Imperio::Imperio(const Imperio& aCopiar){
    this->territConquistados = aCopiar.territConquistados;
    this->tecnologias = aCopiar.tecnologias;
    this->maxMilitar = aCopiar.maxMilitar;
    this->forcaMilitar = aCopiar.forcaMilitar;
    this->maxArmazem = aCopiar.maxArmazem;
    this->armazem = aCopiar.armazem;
    this->maxCofre = aCopiar.maxCofre;
    this->cofre = aCopiar.cofre;
}

Imperio::~Imperio(){
    for(const auto& p : territConquistados)//apaga informação para onde os ponteiros estão a apontar
        delete p;
    territConquistados.clear();//apaga os pointers
}

vector <Territorio*>& Imperio::getConquistados()
{
    return territConquistados;
}

int Imperio::getSizeConquistados() const{
    return territConquistados.size();
}

bool Imperio::verificaTecnologia(const string &nome) const {
    for(const auto &it : tecnologias){
        if(it.first == nome){//verifica key
            if(!get<bool>(it.second)){ // SE ELE AINDA NAO TEM A TECNOLOGIA
                return false;
            }
            else{
                return true;
            }
        }
    }
            //acede ao value(tuple) e acede ao primeiro valor dele(tuple<bool, int>)
            //este get podia ser feito por index, mas a partir do c++14 pode se usar o tipo do dado
            //https://en.cppreference.com/w/cpp/utility/tuple/get
    return false;
}

int Imperio::getForcaMilitar() const {
    return forcaMilitar;
}

void Imperio::setForcaMilitar(int val) {
    forcaMilitar = val;
}

int Imperio::getCofre() const {
    return cofre;
}

void Imperio::setCofre(int val) {
    cofre = val;
}

int Imperio::getArmazem() const {
    return armazem;
}

void Imperio::setArmazem(int val) {
    armazem = val;
}

void Imperio::updateMilitar() {
    maxMilitar = 5;
}

int Imperio::getMaxMilitar() const {
    return maxMilitar;
}

void Imperio::setMaxMilitar(){
    if(verificaTecnologia("drones")){
        maxMilitar = 5;
    }
}

void Imperio::updateOP() {
    maxArmazem = 5;
    maxCofre = 5;
}

int Imperio::getMaxCofre() const {
    return maxCofre;
}

void Imperio::setMaxCofre(){
    if(verificaTecnologia("drones")){
        maxCofre = 5;
    }
}

int Imperio::getMaxArmazem() const{
    return maxArmazem;
}

void Imperio::setMaxArmazem(){
    if(verificaTecnologia("banco")){
        maxArmazem = 5;
    }
}





vector<string>& Imperio::getKeyValues() const{
    static vector<string> nomes;
    for(const auto& it : tecnologias)
        nomes.push_back(it.first);
    return nomes;
}

unordered_map<string, tuple<bool, int>> Imperio::getUnMap() const{
    return tecnologias;
}

void Imperio::compraTecnologia(const string &nome) {
    for(auto &it : tecnologias){
        if(it.first == nome){
            tuple<bool, int> &tp = it.second;
            get<bool>(tp) = true;
        }
    }
}

string Imperio::toString() const{
    ostringstream oss;

    //ouro, produtos e militar
    oss << "Cofre: " << cofre << "/" << maxCofre << "\t" <<
           "Armazem: " << armazem << "/" << maxArmazem << "\t" <<
           "Forca militar: " << forcaMilitar << "/" << maxMilitar << endl;
    oss << endl;

    //tecnologias
    oss << "Tecnologias:\n";
    for(const auto &it : tecnologias)
            oss << "\t" << it.first << "\t Custo: " << get<int>(it.second) << "\tEstado:" << get<bool>(it.second) << endl;
    oss << endl;

    //territorios
    oss << "Territorios conquistados:" << endl;
    for(const auto &it : territConquistados)
        oss << "\t" << it->getAsString() << endl;

    return oss.str();
}

