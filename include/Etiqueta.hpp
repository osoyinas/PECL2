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
Paquete crearEtiqueta(CodigoId, Nif, Coord);
Paquete generarEtiqueta(int,Semicoord,Semicoord,Semicoord,Semicoord);

#endif // ETIQUETA_H
