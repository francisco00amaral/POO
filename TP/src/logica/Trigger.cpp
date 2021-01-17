//
// Created by migue on 15/12/2020.
//

#include <Utils.h>
#include "Trigger.h"

Trigger::Trigger() {

}

Trigger::~Trigger() {

}

void Trigger::criaInicial(){
    mundo.mCriaInicial();
}

//pre-jogo
void Trigger::cria(istringstream &iss) {
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

void Trigger::carrega(istringstream &iss) {
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
void Trigger::conquista(istringstream &iss, fase& phase) {

    string nome;
    if((iss >> nome).fail()){
        cout << "Erro ao ler os argumentos passados." << endl;
        return;
    }

     toLower(nome);

    resConquista res = mundo.mConquista(nome, phase);

    if(res == CONQUISTADO)
        cout << "Territorio conquistado com sucesso." << endl;
    else if(res == NAO_CONQUISTADO)
        cout << "Territorio nao foi conquistado." << endl;
    else if(res == INEXISTENTE)
        cout << "Territorio passado nao existe." << endl;
    else if(res == CONQ_INSUF)
        cout << "Territorios conquistados inferior a 5 e/ou nao possui misseis" << endl;
    else if(res == RE_CP)
        cout << "Escolha ja feita anteriormente." << endl;
    else if(res == PERDEU_CP){
        cout << "Ficaste sem forca militar e perdeste." << endl;
    }

}

void Trigger::passa() {
    mundo.mPassa();
}

void Trigger::maisOuro(istringstream& iss) {

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

void Trigger::maisProduto(istringstream& iss) {

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

void Trigger::maisMilitar(istringstream& iss) {

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

void Trigger::adquire(istringstream &iss) {

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

void Trigger::lista(istringstream &iss){

    if(iss.rdbuf()->in_avail() > 0){

        string nome;
        if((iss >> nome).fail()){
            cout << "Erro ao ler os argumentos." << endl;
            return;
        }

        toLower(nome);

        mundo.mLista(nome);


    }else{

        mundo.mLista();
    }

}

void Trigger::grava(const fase& phase, istringstream &iss, const int& turn) {

    resDados res = mundo.mGrava(phase, iss, turn);

    if(res == FALHA)
        cout << "Falha ao ler os argumentos passados." << endl;
    else if(res == NOME_REPETIDO)
        cout << "Nome passado ja e referente a um save diferente." << endl;
    else if(res == GRAVADO)
        cout << "Save feito com sucesso." << endl;

}

void Trigger::ativa(fase& phase, istringstream &iss, int& turn) {

    resDados res = mundo.mAtiva(phase, iss, turn);

    if(res == FALHA)
        cout << "Erro ao ler os argumentos passados." << endl;
    else if(res == NOME_INEXISTENTE)
        cout << "Nome do save passado nao existe." << endl;
    else if(res == ATIVADO)
        cout << "Carregamento do save feito com sucesso." << endl;

}

void Trigger::apaga(istringstream &iss){

    resDados res = mundo.mApaga(iss);

    if(res == FALHA)
        cout << "Erro ao ler os argumentos passados." << endl;
    else if(res == NOME_INEXISTENTE)
        cout << "Nome do save passado nao existe." << endl;
    else if(res == APAGADO)
        cout << "Save apagado com sucesso." << endl;

}

void Trigger::toma(istringstream &iss) {

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

void Trigger::modifica(istringstream &iss) {
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

void Trigger::evento(int turno, fase& phase){
     resEvento res = mundo.mEvento(turno, phase);
     if(res == ALIANCA){
         cout << "Alianca diplomatica foi assinada!" << endl;
     }
     if(res == INVADIDO){
         cout << "Territorio foi conquistado" << endl;
     }
    if(res == N_INVADIDO){
        cout << "Territorio nao foi conquistado" << endl;
    }
     if(res == ADICIONADO){
         cout << "Recurso abandonado adicionado com sucesso!" << endl;
     }
    if(res == DESPERDICADO){
        cout << "Recurso foi desperdicado devido a valores maximos" << endl;
    }
     if(res == NADA){
         cout << "Nao aconteceu nenhum evento,podem ir dormir descansado" << endl;
     }
     if(res == RE_EVENTO){
         cout << "Ja aconteceu o evento deste turno!" << endl;
     }
}


void Trigger::fevento(istringstream &iss, int turn, fase& phase) {

        string tipo;
        if((iss >> tipo).fail()){
            cout << "Erro ao ler os argumentos." << endl;
            return;
        }

        if(mundo.mFevento(tipo,turn, phase))
            cout << "Evento aplicado com sucesso." << endl;
        else
            cout << "Evento pedido nao existe." << endl;

    }


//passa para a proxima fase
//fase != turno
void Trigger::avanca(fase& phase){
    mundo.mAvanca(phase);
}

//overload do avanca, somente chamado na fase EVENTO pra saber se está no final
void Trigger::avanca(fase& phase, int turn){
    mundo.mAvanca(phase, turn);
}

void Trigger::novoTurno(fase &phase, int turn){
    if(turn == 12)
        phase = FIM;
    else
        phase = CONQUISTA;
}

//ocasião especial
//atualiza os valores de cada territorio(conquistados e nao conquistados)
void Trigger::update(int turno) {
    mundo.mUpdate(turno);
}

//recolhe ouro e produtos no inicio de cada fase de recolha(2ª fase)
//fase != turno
void Trigger::harvest() {
    mundo.mHarvest();
}

//info atual(status bar)
string Trigger::mostraImperio() const {
    return mundo.mMostraImperio();
}

/*mostra info final
 * quantidade de dados
 * bonus extra(5 tecnologias adquiridas/todos os territorios conquistados)*/
void Trigger::mostraResultadoFinal() {
    cout << mundo.mMostraImperio() << endl;
    cout << "Total de pontos: " << mundo.mPontos() << endl;
}