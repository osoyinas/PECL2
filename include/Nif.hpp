#ifndef NIF_H
#define NIF_H

#include <cstring>
#include <string>
#include "Random.hpp"
#include <stdexcept>
using namespace std;

struct Nif
{
    //Constructor
    Nif();

    //Atributos
    char digitos[9]= "00000000";
    char letra = 'X';
};
//Funciones
Nif crearNif(char nif[]);
string getNifStr(Nif nif);
Nif generarNif();

#endif // NIF_H
