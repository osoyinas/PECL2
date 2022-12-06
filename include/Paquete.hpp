#ifndef ETIQUETA_H
#define ETIQUETA_H

#include "CodigoId.hpp"
#include "Coord.hpp"
#include "Nif.hpp"

struct Paquete
{
    //Constructor
    Paquete();

    //Atributos
    CodigoId id;
    Nif nif;
    Coord coords;
    int CP;
};
//Funciones

Paquete crearPaquete(CodigoId, Nif, Coord, int);
Paquete generarPaquete(int,Semicoord,Semicoord,Semicoord,Semicoord, int);

#endif // ETIQUETA_H
