#ifndef CODIGOID_H
#define CODIGOID_H

#include <cstring>
#include <string>
#include "Random.hpp"

using namespace std;

struct CodigoId
{
    //Constructor
    CodigoId();
    //Atributos
    int secN = 0;
    char rdigitos[3] = "00";
    char letra = 'X';

};
//Funciones
string getCodigoIdStr(CodigoId);
CodigoId generarCodigoId(int);

#endif // CODIGOID_H
