#ifndef COLA_H
#define COLA_H

#include <vector>
#include "NodoCola.hpp"
#include "Etiqueta.hpp"
#include <iostream>
using namespace std;

class Cola
{
    public:
        //Constructor
        Cola();
        //Metodos
        void insertar (Etiqueta v);
        void eliminar();
        bool vacia();
        vector<Etiqueta> getArray();
        Etiqueta verPrimero();
    private:
        //Atributos
        pnodoCola primero, ultimo;
};

#endif // COLA_H
