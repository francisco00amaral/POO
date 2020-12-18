//
// Created by migue on 15/11/2020.
//

#include "Utils.h"

void toLower(string& str){
    transform(str.begin(), str.end(), str.begin(), [](unsigned char c){
        return tolower(c);
    });
}