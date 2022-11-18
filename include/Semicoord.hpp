#ifndef SEMICOORD_H
#define SEMICOORD_H

#include "Random.hpp"
#include <stdexcept>
using namespace std;

struct Semicoord
{
    //atributos
    int grados;
    int minutos;
    int segundos;
    //constructor
    Semicoord();
    //metodos
    bool esMenor(Semicoord semicoord);
};
//funciones
Semicoord crearSemicoordenada(int grados, int minutos, int segundos);
Semicoord generarSemicoord(Semicoord min, Semicoord max);
Semicoord puntoMedio(Semicoord a, Semicoord b);
#endif // SEMICOORD_H
