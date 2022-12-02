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
};
//Funciones

Paquete crearPaquete(CodigoId, Nif, Coord);
Paquete generarPaquete(int,Semicoord,Semicoord,Semicoord,Semicoord);

#endif // ETIQUETA_H
