//
// Created by migue on 15/11/2020.
//

#include "../h/Imperio.h"
#include "../h/Continente.h"
#include "../h/Ilha.h"


string Imperio::getAsString() const {
    ostringstream os;
    for(const auto &x : territorios){
        os << x.getAsString();
        os << endl;
    }
    //FALTA LISTAR TECNOLOGIAS
    return os.str();
}

vector<Territorio> Imperio::getTerritorios() const{
    return territorios;
}

//recebe tipo de territorio e mostra todos os territorios do mesmo tipo
void Imperio::mostra(const string &nome) const{
    for(const auto &x : territorios){
        if(x.getNome().find(nome) != string::npos){
            cout << x.getAsString() << endl; 
            }
    }
}

void Imperio::mostra() const{
    for(const auto &x : territorios){
           cout << x.getAsString() << endl; 
    }
}


vector<string> Imperio::getNomesTerritorios() const {
    return nomes;
}

string Imperio::getAsString(const string &str) const {
    ostringstream os;
    for(const auto &x : territorios){
        if(x.getNome() == str){
            os << x.getAsString();
            os << endl;
        }
    }
    return os.str();
}

bool Imperio::criaTerritorios(string &palavra,int n){
    for(int i=0;i<n;i++){
        if(palavra == "Pescaria" || palavra == "Refugio dos Piratas"){
            Ilha t(palavra);
            territorios.push_back(t);         
        }
        else{
            Continente c(palavra);
            territorios.push_back(c);
        }
    }
    return true;
}

// metodo para quando o jogo começa adicionar o territorio inicial ao vetor de territorios
void Imperio::inicial(){
    Territorio a;
    territorios.push_back(a);
    territConquistados.push_back(a);
}

void Imperio::conquer(Territorio &t){
    cout << "TÁ A QUANTO:  " << t.getConquistado() << endl;
    if(t.isConquistado()){
        cout << "Territorio ja esta conquistado!" << endl;
        return;
    }
    int sorte = (rand() % 6) + 1; // NUMERO ALEATORIO ENTRE 1 E 6 INCLUSIVE;
    int forca = forcaMilitar;

    forca += sorte;

    if(forca >= t.getRes()){
        adicionaProd(t);
        adicionaOuro(t);
        t.setConquistado();
        territConquistados.push_back(t); // FALTA ADICIONAR OS PRODUTOS E OURO...
    }
    else{
        cout << "Nao foi possivel conquistar o territorio " << t.getNome() << endl;
        forcaMilitar--;
        if(forcaMilitar < 0)
            forcaMilitar = 0;
            }
}

vector<Territorio> Imperio::getConquistados() const{
    return territConquistados;
}

// POR AGORA ASSIM FUNCIONA, MAS QUANDO ACRESCENTARMOS AQUELAS CENAS Q AUMENTAM ESPAÇO COFRE VAI TER MUDANÇA
void Imperio::adicionaProd(const Territorio &t){
armazem += t.getProd();
        if(armazem > 3)
            armazem = 3;
}

void Imperio::adicionaOuro(const Territorio &t){
        cofre += t.getOuro();
        if(cofre > 3)
            cofre = 3;

    }

