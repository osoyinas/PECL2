#ifndef ETIQUETA_H
#define ETIQUETA_H

#include "CodigoId.hpp"
#include "Coord.hpp"
#include "Nif.hpp"

struct Etiqueta
{
    //Constructor
    Etiqueta();

    //Atributos
    CodigoId id;
    Nif nif;
    Coord coords;
};
//Funciones
Etiqueta crearEtiqueta(CodigoId, Nif, Coord);
Etiqueta generarEtiqueta(int,Semicoord,Semicoord,Semicoord,Semicoord);

#endif // ETIQUETA_H
