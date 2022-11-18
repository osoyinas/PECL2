#ifndef PILA_H
#define PILA_H

#include <vector>
#include "Etiqueta.hpp"

using namespace std;
class Pila
{
    public:
        //Constructor
        Pila();
        //Metodos
        void apilar(Etiqueta etiqueta);
        void desapilar();
        Etiqueta cima();
        bool vacia();
        vector<Etiqueta> getArray();
    private:
        //Atributos
        vector<Etiqueta> lista;
};

#endif // PILA_H
