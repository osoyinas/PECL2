#ifndef ARBOLBINARIO_HPP
#define ARBOLBINARIO_HPP
#include "NodoBinario.hpp"
#include "Central.hpp"
#include <iostream>
using namespace std;

class ArbolBinario
{
private:
    struct NodoBinario* raiz;
public:
    ArbolBinario()
    {
        raiz = NULL;
    }
    NodoBinario* crearNodo(Central);
    NodoBinario* insertarNodo(NodoBinario*, Central);
    NodoBinario* borrarNodo(NodoBinario*, Central);
    void inOrden(NodoBinario*);
    void preOrden(NodoBinario*);
    void postOrden(NodoBinario*);
    NodoBinario* getMin(NodoBinario*);
    NodoBinario* getRaiz() {
        return raiz;
    }
    void setRaiz(NodoBinario* nodo) {
        raiz = nodo;
    }
};

#endif // ARBOLBINARIO_HPP
