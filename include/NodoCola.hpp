#ifndef NODOCOLA_H
#define NODOCOLA_H

#include "Etiqueta.hpp"

using namespace std;

class NodoCola
{
    public:
        //Constructor
        NodoCola(Etiqueta v, NodoCola* sig);
        //Destructor
        ~NodoCola();
    private:
        //Atributos
        Etiqueta valor;
        NodoCola* siguiente;
        friend class Cola;
};
typedef NodoCola *pnodoCola;

#endif // NODOCOLA_H
