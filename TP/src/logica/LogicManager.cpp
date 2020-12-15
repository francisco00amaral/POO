//
// Created by migue on 15/12/2020.
//

#include "LogicManager.h"

LogicManager::LogicManager() {

}

LogicManager::~LogicManager() {

}

void LogicManager::init() {

}


//pre-jogo
void LogicManager::cria(istringstream &iss) {

    string arg;
    if((iss >> arg).fail()){
        cout << "Erro ao criar territorio(s)." << endl;
        return;
    }

    /*
     * Falta lógica pk ainda
     * */

}

void LogicManager::carrega(istringstream &iss) {

}


//durante o jogo
void LogicManager::conquista(istringstream &iss) {

}

void LogicManager::passa() {

}

void LogicManager::maisOuro() {

}

void LogicManager::maisProduto() {

}

void LogicManager::maisMilitar() {

}

void LogicManager::adquire(istringstream &iss) {

}

void LogicManager::lista(istringstream &iss) const {

}

void LogicManager::grava(istringstream &iss) {

}

void LogicManager::ativa(istringstream &iss) {

}

void LogicManager::toma(istringstream &iss) {

}

void LogicManager::modifica(istringstream &iss) {

}

void LogicManager::fevento(istringstream &iss) {

}


//ocasião especial
void LogicManager::update() {

}


//mostra info atual(status bar)
string LogicManager::mostraImperio() const {
    return std::string();
}

