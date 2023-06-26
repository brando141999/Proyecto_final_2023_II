#ifndef STAR_CRAFT_FUNCIONES_ATAQUE_H
#define STAR_CRAFT_FUNCIONES_ATAQUE_H
#include <string>
#include "iostream"
#include "cctype"
#include <algorithm>
using namespace std;
string  minuscula(string texto){
    string a=texto;
    transform(a.begin(),a.end(),a.begin(),[](unsigned char c){return tolower(c);});
    return a;
}
#endif //STAR_CRAFT_FUNCIONES_ATAQUE_H
