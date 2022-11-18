#ifndef COORD_H
#define COORD_H

#include "Semicoord.hpp"
#include <string>
#include <iostream>

using namespace std;

struct Coord
{
    //constructor
    Coord();
    //atributos
    Semicoord longitud;
    Semicoord latitud;

};
//Funciones
string getCoordenadaStr(Coord coord);
Coord crearCoordenada(Semicoord latitud, Semicoord longitud);
Coord generarCoordenada(Semicoord,Semicoord,Semicoord,Semicoord);

#endif // COORD_H
