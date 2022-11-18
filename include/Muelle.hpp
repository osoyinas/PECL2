#ifndef MUELLE_H
#define MUELLE_H

#include <vector>
#include "Etiqueta.hpp"
#include "Cola.hpp"
#include "Pila.hpp"
struct Muelle
{
    //Constructor
    Muelle();

    //Atributos
    Coord maxCoords;
    Coord minCoords;
    Cola cola;
    int furgonetaActual;
    vector<Pila> furgonetas;

    //metodos
    bool recibe(Etiqueta etiqueta);
    void insertar(Etiqueta etiqueta, int N3);
    void addFurgoneta();
};
//Funciones
Muelle crearMuelle(Coord,Coord);



#endif // MUELLE_H
