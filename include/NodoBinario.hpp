#ifndef NODOBINARIO_H
#define NODOBINARIO_H

#include <iostream>

class NodoBinario{
    private:
        int dato;
        NodoBinario *izquierda;
        NodoBinario *derecha;
        friend class ArbolBinario;
    public:
        NodoBinario (int dat, NodoBinario *izq = NULL, NodoBinario * der=NULL);
};
typedef NodoBinario *pNodo;

#endif // NODOBINARIO_H
