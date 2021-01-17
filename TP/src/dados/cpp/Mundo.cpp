//
// Created by migue on 15/12/2020.
//

#include <Duna.h>
#include <Castelo.h>
#include <Fortaleza.h>
#include <Mina.h>
#include <Montanha.h>
#include <Planicie.h>
#include <Pescaria.h>
#include <Refugio.h>
#include "Mundo.h"

Mundo::Mundo() {

}

Mundo::~Mundo() {
    for(const auto& it : territorios){
        delete it;
    }
    territorios.clear();
}


// FUNCIONA MAS NAO FICA NO VETOR DE TERRITORIOS DO MUNDO PORQUE O SETCONQUISTADO APAGA-O DE LA... VER SE É ASSIM
void Mundo::mCriaInicial(){
    Territorio *ptr;
    ptr = new Territorio();
    imperio.getConquistados().push_back(ptr);
//    territorios.push_back(ptr); // adicionar ao vetor de territorios do mundo
//    setConquistado(ptr);    // adicionar ao vetor de territorios do imperio
}

resCria Mundo::mCria(const string &tipo, int quant) {

    if(!verificaNomeTerritorio(tipo))
        return TIPO_INEXISTENTE;

    if(quant <= 0)
        return QUANTIDADE_NEGATIVA;


    Territorio* ptr;
    for(int i = 0; i < quant; i++){
        if(tipo == "castelo"){
            ptr = new Castelo("Castelo");
            territorios.push_back(ptr);
        }
        else if(tipo == "duna"){
            ptr = new Duna("Duna");
            territorios.push_back(ptr);
        }
        else if(tipo == "fortaleza"){
            ptr = new Fortaleza("Fortaleza");
            territorios.push_back(ptr);
        }
        else if(tipo == "mina"){
            ptr = new Mina("Mina");
            territorios.push_back(ptr);
        }
        else if(tipo == "montanha"){
            ptr = new Montanha("Montanha");
            territorios.push_back(ptr);
        }
        else if(tipo == "planicie"){
            ptr = new Planicie("Planicie");
            territorios.push_back(ptr);
        }
        else if(tipo == "pescaria"){
            ptr = new Pescaria("Pescaria");
            territorios.push_back(ptr);
        }
        else if(tipo == "refugio"){
            ptr = new Refugio("Refugio");
            territorios.push_back(ptr);
        }
    }
    return CRIADO;
}

int Mundo::aleatorio(){
    return rand()% 6 + 1; //valor random [1, 6]
}

resConquista Mundo::mConquista(const string &nome, fase& phase) {

    //comando repetido
    if(flagCP){
        cout << flagCP << endl;
        return RE_CP;
    }

    int val = aleatorio();
    int forcaMilitar = imperio.getForcaMilitar();

    if(!verificaExistenciaTerritorio(nome))//verifica se o territorio existe
        return INEXISTENTE;

    if(nome.find("Pescaria") != string::npos || nome.find("Refugio") != string::npos) {//verifica tecnologia necessária
        if (!imperio.verificaTecnologia("misseis"))
            return SEM_MISSEIS;
    }

    Territorio* ptr;
    ptr = getTerritorioByName(nome);

    // TIRAR ESTE +10 DAQUI!!!
    if(ptr->getRes() <= val+forcaMilitar+10){
        setConquistado(ptr); //remove o pointer do territorios e mete-o no conquistados
        flagCP = true;
        return CONQUISTADO;
    }
    else{
        imperio.setForcaMilitar(imperio.getForcaMilitar()-1);
        if(imperio.getForcaMilitar() < 0){
            imperio.setForcaMilitar(0);
        }
        return NAO_CONQUISTADO;
    }

}

void Mundo::mPassa() {
    flagCP = true;
}

resMaisOP Mundo::mMaisOuro() {

    if(flagOP)
        return RE_OP;

    if(!imperio.verificaTecnologia("bolsa"))//verifica se tem tecnologia necessaria
        return SEM_BOLSA;

    if(imperio.getArmazem() >= 2)//verifica se tem recursos para trocar
        if(imperio.getCofre() < imperio.getMaxCofre()){//verifica se tem espaço no cofre
            imperio.setArmazem(imperio.getArmazem()-2);
            imperio.setCofre(imperio.getCofre()+1);
            flagOP = true;
            return TROCADO;
        }
        else//se nao tiver espaço no cofre
            return NAO_TROCADO;
    else
        return SEM_RECURSOS;
}

resMaisOP Mundo::mMaisProduto() {
    if(flagOP)
        return RE_OP;

    if(!imperio.verificaTecnologia("bolsa"))//verifica se tem tecnologia necessaria
        return SEM_BOLSA;

    if(imperio.getCofre() >= 2)//verifica se tem recursos para trocar
        if(imperio.getArmazem() < imperio.getMaxArmazem()){//verifica se tem espaço no cofre
            imperio.setCofre(imperio.getCofre()-2);
            imperio.setArmazem(imperio.getArmazem()+1);
            flagOP = true;
            return TROCADO;
        }
        else//se nao tiver espaço no cofre
            return NAO_TROCADO;
    else
        return SEM_RECURSOS;
}

resMA Mundo::mMaisMilitar() {
    if(flagMaisMilitar)
        return RE_M;

    if(imperio.getArmazem() > 1 && imperio.getCofre() > 1){//verifica se tem recursos para trocar
        if(imperio.getForcaMilitar() < imperio.getMaxMilitar()){
            imperio.setForcaMilitar(imperio.getForcaMilitar()+1);
            flagMaisMilitar = true;
            return ADQUIRIDO;
        }
        else
            return NAO_ADQUIRIDO;
    }
    else
        return RECURSOS;
}

resMA Mundo::mAdquire(const string &tipo) {
    if(flagMaisTecno)//verifica se já repetiu a escolha
        return RE_T;

    if(!verificaExistenciaTecnologia(tipo))//verifica se existe
        return NAO_ADQUIRIDO;

    if(imperio.verificaTecnologia(tipo))//verifica se já foi adquirida
        return JA_ADQUIRDA;

    if(verificaPrecoTecnologia(tipo) <= imperio.getCofre()){//verifica se tem recursos
        imperio.compraTecnologia(tipo);
        mAtivaTec(tipo);
        flagMaisTecno = true;//ativa flag pra impedir repetição
        return ADQUIRIDO;
    }
    else//nao tem recursos
        return RECURSOS;

}

// problema de so funciona se for passado Mina ou Montanha, se for passado mina ou montanha não da
void Mundo::mLista(const string &nome) const {
    for(const auto &x : territorios){
        string str = x->getNome();
        toLower(str);
        if(str.find(nome) != string::npos){
            cout << x->getAsString() << endl;
        }
    }
}

void Mundo::mLista(){
    for(const auto &x : territorios){
        cout << x->getAsString() << endl;
    }
}



resDados Mundo::mGrava(const fase &phase, istringstream &iss,const int& turn) {
    string nome;//lê argumento
    if((iss >> nome).fail()){
        return FALHA;
    }

    for(const auto& it : saves){//verifica se nome n é repetido
        const tuple<string, Mundo*, int, fase> &tp = it;
        if(get<string>(tp) == nome)
            return NOME_REPETIDO;
    }

    Mundo* ptr = new Mundo();//cria uma cópia do mundo atual
    *ptr = *this;//copia

    tuple<string, Mundo*, int, fase> tuplo(nome, ptr, turn, phase);//cria tuple e adiciona o tuple aos saves
    saves.push_back(tuplo);
    return GRAVADO;
}

/* Aqui n foi possível utilizar o construtor por cópia, visto que o this é um ponteiro,
 * e n se pode usar ponteiros no construtor por cópia.
 * Isso iria apenas copiar o ponteiro e essa NÃO É A INTENÇÃO.
 * */
resDados Mundo::mAtiva(fase &phase, istringstream &iss, int& turn) {
    string nome;
    if((iss >> nome).fail()){
        return FALHA;
    }

    for(const auto &it : saves){
        const tuple<string, Mundo*, int, fase> &tp = it;//apanha referencia
        if(get<string>(tp) == nome){
            auto& var = get<Mundo*>(it);//buscar referencia do mundo
            *this = *var;
            phase = get<fase>(it);
            turn = get<int>(it);
            return ATIVADO;
        }
    }

    return NOME_INEXISTENTE;
}

/*Aqui será necessário usar os destrutores.*/
resDados Mundo::mApaga(istringstream &iss) {
    string nome;
    if((iss >> nome).fail()){
        return FALHA;
    }

    for(int i = 0; i < saves.size(); i++){
        const tuple<string, Mundo*, int, fase> &tp = saves[i];
        if(get<string>(tp) == nome){
            saves.erase(saves.begin()+i);
            return APAGADO;
        }
    }

    return NOME_INEXISTENTE;
}



resToma Mundo::mTomaTerr(const string &nome) {
    if(!verificaExistenciaTerritorio(nome)){
        return TERRITORIO_INEXISTENTE;
    }
    for(const auto &x : imperio.getConquistados()){
        if(x->getNome() == nome){
            return TERRITORIO_JA_CONQUISTADO;
        }
    }

    setConquistado(getTerritorioByName(nome));
    return TOMADO;
}

void Mundo::mAtivaTec(const string &nome){
    if(nome == "drones"){
        imperio.setMaxMilitar();
    }
    if(nome == "banco"){
        imperio.setMaxCofre();
        imperio.setMaxArmazem();
    }
}

resToma Mundo::mTomaTech(const string &nome){
    if(!verificaExistenciaTecnologia(nome)) {
        return TECNOLOGIA_INEXISTENTE;
    }

    if(imperio.verificaTecnologia(nome)){
        return TECNOLOGIA_JA_ADQUIRIDA;
    }

    imperio.compraTecnologia(nome);
    mAtivaTec(nome);
    return TOMADO;
}

void Mundo::mModificaOuro(int quantidade) {
    if(quantidade <= 0){
        imperio.setCofre(0);
        return;
    }
    if(quantidade >= imperio.getMaxCofre()){
        imperio.setCofre(imperio.getMaxCofre());
        return;
    }
}

void Mundo::mModificaProduto(int quantidade){
    if(quantidade <= 0){
        imperio.setArmazem(0);
        return;
    }
    if(quantidade >= imperio.getMaxCofre()){
        imperio.setArmazem(imperio.getMaxArmazem());
        return;
    }
}

resEvento Mundo::mEvento(int turno){
    int a = rand() % 4 + 1;//valor random do evento [1, 4]

    // evento ja aconteceu 1x
    if(flagEvento){
        return RE_EVENTO;
    }
    flagEvento = true;

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
            if(this->mEventoRecurso(tipo)){
                return ADICIONADO;
            }
            else
                return DESPERDICADO;
            break;
        case 54: // INVASAO A TERRITORIO
            cout << "TERRITORIO A SER INVADIDO!!" << endl;
            if(this->mInvasao(turno))
                return INVADIDO;
            else
                return N_INVADIDO;
            break;
        case 3: // Alianca
            if(this->mEventoAlianca()){
                cout << "Forca militar aumentou uma unidade!" << endl;;
            }else
                cout << "Forca militar ja estava no maximo!" << endl;
            return ALIANCA;
            break;
        case 4: // nada
            return NADA;
            break;
    }
    this->flagEvento = true;
    return NADA;
}

bool Mundo::mFevento(const string &tipo,int turn){
    if(tipo == "Recurso"){
        if(turn <= 6){
            mEventoRecurso("prod");
        }
        else
            mEventoRecurso("ouro");
        return true;
    }
    if(tipo == "Alianca"){
        mEventoAlianca();
        return true;
    }
    if(tipo == "Invasao"){
        mInvasao(turn);
        return true;
    }
    if(tipo == "sem"){
        cout << "Nao aconteceu nada e podem ir dormir descansados" << endl;
        return true;
    }
    return false;
}

bool Mundo::mEventoRecurso(const string &tipo){
    if(tipo == "ouro"){
        if(imperio.getCofre() == imperio.getMaxCofre())
            return false;
        else{
            imperio.setCofre(imperio.getCofre()+1);
            return true;
        }
    }
    if(tipo == "prod"){
        if(imperio.getArmazem() == imperio.getMaxArmazem())
            return false;
        else{
            imperio.setArmazem(imperio.getArmazem()+1);
            return true;
        }
    }
    return false;
}

bool Mundo::mEventoAlianca(){
    if(imperio.getForcaMilitar() == imperio.getMaxMilitar()){
        return false;
    }
    else{
        imperio.setForcaMilitar(imperio.getForcaMilitar()+1);
        return true;
    }
}

bool Mundo::mInvasao(int turno){
    // ULTIMA POSICAO DO VETOR imperio.getConquistados().back();
    int val = aleatorio();
    int forcaInv = 0;

    if(turno <= 6){
        forcaInv = 2; // FORCA DE INVASAO É DE 2 NO PRIMEIRO ANO
    }else
        forcaInv = 3;// FORCA DE INVASAO É DE 3 NO SEGUNDO ANO
    val += forcaInv;

    // ULTIMO CONQUISTADO
    Territorio *ptr = imperio.getConquistados().back();
    // SE TEM A TECNOLOGIA DEFESAS ACRESCENTA 1 VALOR À RESISTENCIA
    if(imperio.verificaTecnologia("defesas")){
        ptr->setRes(ptr->getRes()+1);
    }
    if(val <= ptr->getRes()-8){
        return false;
    }
    else{
        if(ptr->getNome() == "Inicial"){
            cout << "Ficou sem territorios disponiveis, perdeu o jogo!";
            exit(-1);
        }
        imperio.getConquistados().pop_back(); // apagar do vetor de conquistados
        return true;
    }
    return false;
}

void Mundo::mAvanca(fase &phase) {
    switch(phase){
        case CONQUISTA:
            phase = RECOLHA;
            break;
        case RECOLHA:
            phase = COMPRA;
            break;
        case COMPRA:
            phase = EVENTO;
            break;
        case EVENTO:
            phase = AVANCA;
            break;
        case AVANCA:
            phase = CONQUISTA;
            break;
    }
}

//este é diferente pk é o avanca que faz a verificação do turno
void Mundo::mAvanca(fase& phase, int turn){
    if(turn == 12)
        phase = FIM;
    else
        phase = CONQUISTA;
}

void Mundo::mUpdate() {
    //dá reset às flags no início de cada turno
    this->flagCP = false;
    this->flagOP = false;
    this->flagMaisMilitar = false;
    this->flagMaisTecno = false;
    this->flagEvento = false;
}

void Mundo::mHarvest() {
    for(const auto &it : imperio.getConquistados()){
        if(imperio.getCofre() + it->getOuro() <= imperio.getMaxCofre())
            imperio.setCofre(imperio.getCofre() + it->getOuro());
        else
            imperio.setCofre(imperio.getMaxCofre());

        if(imperio.getArmazem() + it->getProd() <= imperio.getMaxArmazem())
            imperio.setArmazem((imperio.getArmazem() + it->getProd()));
        else
            imperio.setArmazem(imperio.getMaxArmazem());
    }
}

string Mundo::mMostraImperio() const {
    return imperio.toString();
}

string Mundo::mPontos(){
    int pontos = 0;
    int i=0;
    int inicial = 0;
    bool flag = false;

    /* se territorios ficarem no vetor do mundo tambem:
    if(imperio.getSizeConquistados() == territorios.size()){
        pontos +=3;
    }
    */
    /* if(territorios.empty())//verifica se conquistou todos, n deve haver territorios para conquistar
        pontos += 3;
    */
    for(const auto &i : imperio.getConquistados()){
        if(i->getNome() == "Inicial"){
            pontos += 0;
            continue;
        }
        if(i->getNome().find("Pescaria") != string::npos || i->getNome().find("Refugio") != string::npos)
            pontos += 2;
        else{
            pontos += 1;
        }
    }

    for(const auto &it : imperio.getUnMap())
        if(get<bool>(it.second))
            pontos += 1;
        else//ativa caso n tenha uma tecnologia adquirida
            flag = true;

    if(!flag)//se a flag n foi ativada, tem todas as tecnologais adquiridas
        pontos += 1;

    return to_string(pontos);
}



/*funções private que servem apenas para auxiliar as funlções public
 * só podem ser chamadas de dentro das funçoes public*/

Territorio *Mundo::getTerritorioByName(const string &nome) {

    for(int i = 0; i < territorios.size(); i++){
        string str = territorios[i]->getNome();
        toLower(str);
        if(str == nome){
            Territorio* ptr = territorios[i];
            return ptr;
        }
    }

    return nullptr;
}

void Mundo::setConquistado(Territorio *ptr) {
    imperio.getConquistados().push_back(ptr);

    /* for(int i = 0; i < territorios.size(); i++){
        if(ptr->getNome() == territorios[i]->getNome())
            territorios.erase(territorios.begin()+i);
    } */
}

bool Mundo::verificaNomeTerritorio(const string &nome) const {
    for(const auto& it : nomes)
        if(nome == it)
            return true;
    return false;
}

bool Mundo::verificaExistenciaTerritorio(const string &nome) const {
    for (const auto &it : territorios) {
        string str = it->getNome();//copia valor pra poder passar pra lower sem problemas
        toLower(str);
        if (str == nome)//compara valores
            return true;
    }
    return false;
}

bool Mundo::verificaExistenciaTecnologia(const string &nome) const {
    for(const auto &it : imperio.getKeyValues())
        if(it == nome)
            return true;
    return false;
}

int Mundo::verificaPrecoTecnologia(const string &nome) const{
    auto mapa = imperio.getUnMap();
    for(const auto &it : mapa){
        if(it.first == nome)
            return get<int>(it.second);
    }
    return 0;
}

Mundo &Mundo::operator=(const Mundo &outro) {

//    if(this == &outro){ // auto atribuiçao
//        cout << "Auto atribuicao" << endl;
//        return *this;
//    }
//isto n é necessário pk o ponteiro que está no

    this->territorios = outro.territorios;
    this->imperio = outro.imperio;
    this->flagCP = outro.flagCP;
    this->flagOP = outro.flagOP;
    this->flagMaisMilitar = outro.flagMaisMilitar;
    this->flagMaisTecno = outro.flagMaisTecno;
    this->flagEvento = outro.flagEvento;

    return *this;
}