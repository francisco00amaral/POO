//
// Created by migue on 15/12/2020.
//

#include <Utils.h>
#include "Manager.h"

Manager::Manager() {

}

Manager::~Manager() {

}

void Manager::criaInicial(){
    mundo.mCriaInicial();
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
        cout << "Escolha ja feita anteriormente." << endl;
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
    //TODO
}

void Manager::ativa(fase& phase, istringstream &iss) {
    //ainda falta aprender isto
    //TODO
}

void Manager::apaga(fase& phase, istringstream &iss){
    //ainda falta aprender isto
    //TODO
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
    string tipo;
    if((iss >> tipo).fail()){
        cout << "Erro ao obter os argumentos." << endl;
        return;
    }
    toLower(tipo);

    int quantidade;
    if(tipo == "ouro"){
        if((iss >> quantidade).fail()){
            cout << "Erro ao obter os argumentos." << endl;
            return;
        }
        mundo.mModificaOuro(quantidade);
        return;
    }
    else if(tipo == "prod"){
        if((iss >> quantidade).fail()){
            cout << "Erro ao obter os argumentos." << endl;
            return;
        }
        mundo.mModificaProduto(quantidade);
        return;
    }

    cout << "Tipo inserido nao existe." << endl;
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

int Manager::random(){
    return rand() % 4 + 1;//valor random do evento [1, 4]
}

void Manager::evento(int turno){
        int a = random(); // meti isto numa funcao porque pensava que ia ser entre 1 a 6 entao ia meter a cena das resistencias random na func tambem
        string tipo;
        switch(a){
            case 1: // Recurso abandonado
                cout << "Foi encontrado um recurso abandonado" << endl;
                if(turno <= 6) { // primeiro ano adiciona uma unidade de produto
                    tipo = "prod";
                }
                if(turno > 6){
                    tipo ="ouro";
                }
                if(mundo.mEventoRecurso(tipo)){
                    cout << "Recurso abandonado adicionado com sucesso!" << endl;
                }
                else
                    cout << "Recurso foi desperdicado devido a valores maximos" << endl;
                break;
            case 2: // INVASAO A TERRITORIO
                cout << "INVASAO A UM TERRITORIO!!!" << endl;
                break;
            case 3: // Alianca
                cout << "Alianca diplomatica foi assinada!" << endl;
                if(mundo.mEventoAlianca()){
                    cout << "Forca militar aumentou uma unidade!" << endl;;
                }else
                    cout << "Forca militar ja estava no maximo!" << endl;
                break;
            case 4: // nada
                cout << "Nao aconteceu nenhum evento,podem ir dormir descansado" << endl;
                break;
        }
}


void Manager::fevento(istringstream &iss,int turn) {

        string tipo;
        if((iss >> tipo).fail()){
            cout << "Erro ao ler os argumentos." << endl;
            return;
        }

        if(mundo.mFevento(tipo,turn))
            cout << "Evento aplicado com sucesso." << endl;
        else
            cout << "Evento pedido nao existe." << endl;

    }


//passa para a proxima fase
//fase != turno
void Manager::avanca(fase& phase){
    mundo.mAvanca(phase);
}

//overload do avanca, somente chamado na fase EVENTO pra saber se está no final
void Manager::avanca(fase& phase, int turn){
    mundo.mAvanca(phase, turn);
}

//ocasião especial
//atualiza os valores de cada territorio(conquistados e nao conquistados)
void Manager::update() {
    mundo.mUpdate();
}

//recolhe ouro e produtos no inicio de cada fase de recolha(2ª fase)
//fase != turno
void Manager::harvest() {
    mundo.mHarvest();
}

//R info atual(status bar)
string Manager::mostraImperio() const {
    return mundo.mMostraImperio();
}

/*mostra info final
 * quantidade de dados
 * bonus extra(5 tecnologias adquiridas/todos os territorios conquistados)*/
void Manager::mostraResultadoFinal() {
    cout << mundo.mMostraImperio() << endl;
    cout << "Total de pontos: " << mundo.mPontos() << endl;
}


