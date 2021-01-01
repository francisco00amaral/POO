//
// Created by migue on 15/12/2020.
//

#include <Utils.h>
#include "Manager.h"

Manager::Manager() {

}

Manager::~Manager() {

}

void Manager::init() {

}



//pre-jogo
void Manager::cria(istringstream &iss) {
    string tipo;
    if((iss >> tipo).fail()){
        cout << "Erro ao ler argumentos." << endl;
        return;
    }

    int quant;
    if((iss >> quant).fail()){
        cout << "Erro ao ler argumentos." << endl;
        return;
    }

    toLower(tipo);

    resCria res = mundo.mCria(tipo, quant);

    if(res == CRIADO)
        cout << "Territorio(s) criado(s) com sucesso." << endl;
    else if(res == TIPO_INEXISTENTE)
        cout << "Tipo de territorio nao existe." << endl;
    else if(res == QUANTIDADE_NEGATIVA)
        cout << "Quantidade definida nao e positiva." << endl;

}


void Manager::carrega(istringstream &iss) {
    string path;
    if((iss >> path).fail()){
        cout << "Erro ao obter o nome do ficheiro." << endl;
        return;
    }

    ifstream file;
    file.open(path);
    if(file.is_open()){

        string linha;
        resCria res = CRIADO;
        while(getline(file, linha) && res == CRIADO){

            istringstream iss2(linha);
            string tipo;
            int quant;

            if((iss2 >> tipo).fail()){
                cout << "Erro ao ler os argumentos do ficheiro." << endl;
                return;
            }else{
                toLower(tipo);
                if((iss2 >> quant).fail()){
                    cout << "Erro ao ler os argumentos do ficheiro." << endl;
                    return;
                }
            }
            res = mundo.mCria(tipo, quant);
        }

    }else{
        cout << "Erro ao abrir o ficheiro pretendido." << endl;
        return;
    }

}



//durante o jogo
void Manager::conquista(istringstream &iss, fase& phase) {

    string nome;
    if((iss >> nome).fail()){
        cout << "Erro ao ler os argumentos passados." << endl;
        return;
    }

    // toLower(nome);

    resConquista res = mundo.mConquista(nome, phase);

    if(res == CONQUISTADO)
        cout << "Territorio conquistado com sucesso." << endl;
    else if(res == NAO_CONQUISTADO)
        cout << "Territorio nao foi conquistado." << endl;
    else if(res == INEXISTENTE)
        cout << "Territorio passado nao existe." << endl;
    else if(res == SEM_MISSEIS)
        cout << "Nao possui a tecnologia misseis teleguiados para conquistar um territorio do tipo Ilha." << endl;
    else if(res == RE_CP)
        cout << "Escolha já feita anteriormente." << endl;
    else if(res == PERDEU_CP){
        cout << "Ficaste sem forca militar e perdeste." << endl;
    }

}


void Manager::passa() {
    mundo.mPassa();
}


void Manager::maisOuro(istringstream& iss) {

    //maisProduto impede a escolha desta opção
    resMaisOP res = mundo.mMaisOuro();
    if(res == TROCADO)
        cout << "Troca efetuada com sucesso." << endl;
    else if(res == NAO_TROCADO)
        cout << "Troca nao efetuada." << endl;
    else if(res == RE_OP)
        cout << "Ja foi feita uma troca." << endl;
    else if(res == SEM_RECURSOS)
        cout << "Sem recursos para efetuar a troca." << endl;
    else if(res == SEM_BOLSA)
        cout << "Adquira a Bolsa de Valores(tecnologia) primeiro." << endl;

}


void Manager::maisProduto(istringstream& iss) {

    //maisOuro impede a escolha desta opção
    resMaisOP res = mundo.mMaisProduto();
    if(res == TROCADO)
        cout << "Troca efetuada com sucesso." << endl;
    else if(res == NAO_TROCADO)
        cout << "Troca nao efetuada." << endl;
    else if(res == RE_OP)
        cout << "Ja foi feita a outra troca.(maisOuro)" << endl;
    else if(res == SEM_RECURSOS)
        cout << "Sem recursos para efetuar a troca." << endl;
    else if(res == SEM_BOLSA)
        cout << "Adquira a Bolsa de Valores(tecnologia) primeiro." << endl;

}


void Manager::maisMilitar(istringstream& iss) {

    resMA res = mundo.mMaisMilitar();
    if(res == ADQUIRIDO)
        cout << "Compra efetuada com sucesso." << endl;
    else if(res == RE_M)
        cout << "Compra já feita neste turno." << endl;
    else if(res == RECURSOS)
        cout << "Falta recursos para fazer a compra." << endl;
    else if(res == NAO_ADQUIRIDO)
        cout << "Força militar ja no maximo possivel." << endl;

}


void Manager::adquire(istringstream &iss) {

    string tipo;
    if((iss >> tipo).fail()){
        cout << "Erro ao ler os argumentos passados." << endl;
        return;
    }

    resMA res = mundo.mAdquire(tipo);
    if(res == ADQUIRIDO)
        cout << "Tecnologia adquirida com sucesso." << endl;
    else if(res == JA_ADQUIRDA)
        cout << "Tecnologia ja adquirida anteriormente." << endl;
    else if(res == RE_T)
        cout << "Escolha ja feita neste turno." << endl;
    else if(res == RECURSOS)
        cout << "Falta recursos para adquirir a tecnologia." << endl;
    else if(res == NAO_ADQUIRIDO)
        cout << "Tecnologia nao existente." << endl;

}


void Manager::lista(istringstream &iss){

    if(iss.rdbuf()->in_avail() > 0){

        string nome;
        if((iss >> nome).fail()){
            cout << "Erro ao ler os argumentos." << endl;
            return;
        }

        // toLower(nome);

        mundo.mLista(nome);


    }else{

        mundo.mLista();
    }

}


void Manager::grava(fase& phase, istringstream &iss) {
    //ainda falta aprender isto
}


void Manager::ativa(fase& phase, istringstream &iss) {
    //ainda falta aprender isto
}


void Manager::apaga(fase& phase, istringstream &iss){
    //ainda falta aprender isto
}


void Manager::toma(istringstream &iss) {

    string tipo;
    if((iss >> tipo).fail()){
        cout << "Erro ao obter os argumentos." << endl;
        return;
    }


    string nome;//nome do territorio ou da tecnologia

    if(tipo == "terr"){//escolhe territorio
        if((iss >> nome).fail()){
            cout << "Erro ao ler os argumentos." << endl;
            return;
        }

        resToma res = mundo.mTomaTerr(nome);
        if(res == TOMADO)
            cout << "Territorio tomado com sucesso." << endl;

        else if(res == TERRITORIO_INEXISTENTE)
            cout << "Territorio nao existente." << endl;
        else if(res == TERRITORIO_JA_CONQUISTADO)
            cout << "Territorio ja estava conquistado!" << endl;

        return;

    }else if(tipo == "tec"){//escolhe tecnologia
        if((iss >> nome).fail()){

            cout << "Erro ao ler os argumentos." << endl;
            return;
        }

        resToma res = mundo.mTomaTech(nome);
        if(res == TOMADO)
            cout << "Tecnologia tomada com sucesso." << endl;
        else if(res == TECNOLOGIA_JA_ADQUIRIDA)
            cout << "Tecnologia ja adquirida anteriormente." << endl;
        else if(res == TECNOLOGIA_INEXISTENTE)
            cout << "Tecnologia pedida nao existe." << endl;

        return;

    }

    //tipo escolhido nao existe
    cout << "Tipo nao reconhecido." << endl;
}

void Manager::modifica(istringstream &iss) {
    cout << "Teste" << endl;
}


/* void Manager::modifica(istringstream &iss) {

    string tipo;
    if((iss >> tipo).fail()){
        cout << "Erro ao obter os argumentos." << endl;
        return;
    }

    toLower(tipo);

    int quant;
    if(tipo == "ouro"){
        if((iss >> quant).fail()){
            cout << "Erro ao ler os argumentos." << endl;
            return;
        }

        resModifica res = mundo.mModificaOuro(quant);
        if(res == MODIFICADO)
            cout << "Modificacao feita ao ouro com sucesso." << endl;
        else if(res == VAL_ACIMA_MAX)
            cout << "Valor designado supera a capaciade maxima." << endl;
        else if(res == VAL_NEGATIVO)
            cout << "Valor negativo." << endl;

        return;

    }else if(tipo == "prod"){
        if((iss >> quant).fail()){
            cout << "Erro ao ler os argumentos." << endl;
            return;
        }

        resModifica res = mundo.mModificaProduto(quant);
        if(res == MODIFICADO)
            cout << "Alteracao feita aos produtos com sucesso." << endl;
        else if(res == VAL_ACIMA_MAX)
            cout << "Valor designado supera a capaciade maxima." << endl;
        else if(res == VAL_NEGATIVO)
            cout << "Valor negativo." << endl;

        return;
    }

    cout << "Tipo inserido nao existe." << endl;

} */


void Manager::fevento(istringstream &iss) {

    if(iss.rdbuf()->in_avail() == 0) {//se n tiver nada no iss

        mundo.mFevento();
        cout << "Evento random aplicado com sucesso." << endl;

    }else{//caso tenha alguma coisa no iss

        string tipo;
        if((iss >> tipo).fail()){
            cout << "Erro ao ler os argumentos." << endl;
            return;
        }

        if(mundo.mFevento(tipo))
            cout << "Evento aplicado com sucesso." << endl;
        else
            cout << "Evento pedido nao existe." << endl;

    }

}


//passa para a proxima fase
//fase != turno
void Manager::avanca(fase& phase){
    mundo.mAvanca(phase);
}


//ocasião especial
//atualiza os valores de cada territorio(conquistados e nao conquistados)
void Manager::update() {
    mundo.mUpdate();
}


//recolhe ouro e produtos no inicio de cada fase de recolha(2ª fase)
//fase != turno
void Manager::harvest() const {
    mundo.mHarvest();
}

//mostra info atual(status bar)
string Manager::mostraImperio() const {
    //return mundo.getInfoImperio();
    return "string somente para return\n";
}

void Manager::mostraResultadoFinal() {

}


