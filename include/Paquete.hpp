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
<<<<<<<< HEAD:include/Paquete.hpp
Paquete crearPaquete(CodigoId, Nif, Coord);
Paquete generarPaquete(int,Semicoord,Semicoord,Semicoord,Semicoord);
========
Paquete crearEtiqueta(CodigoId, Nif, Coord);
Paquete generarEtiqueta(int,Semicoord,Semicoord,Semicoord,Semicoord);
>>>>>>>> main:include/Etiqueta.hpp

#endif // ETIQUETA_H
