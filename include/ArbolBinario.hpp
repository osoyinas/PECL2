#ifndef ARBOLBINARIO_HPP
#define ARBOLBINARIO_HPP
#include "NodoBinario.hpp"
#include "Central.hpp"
#include <iostream>
#include <cmath>
using namespace std;

class ArbolBinario {

public:
    struct NodoBinario* RAIZ;
    ArbolBinario()
    {
        RAIZ = NULL;
    }
    NodoBinario* crearNodo(Central);
    NodoBinario* insertarNodo(NodoBinario*, Central);
    void borrarNodo(NodoBinario* &raiz, int);
    NodoBinario* buscarNodo(int id);
    void inOrden(NodoBinario*);
    void preOrden(NodoBinario*);
    void postOrden(NodoBinario*);
    int getLength(int len, NodoBinario* raiz);
    void mostrarCentrales(NodoBinario* RAIZ);
    void mostrarEstadistica(NodoBinario* RAIZ, int N3);
    bool esHoja(NodoBinario* nodo) { return !nodo->derecho && !nodo->izquierdo; }
    void buscarPaquete(NodoBinario*RAIZ,string ID);
    void setRaiz(NodoBinario* nodo) {
        RAIZ = nodo;
    }
};

#endif // ARBOLBINARIO_HPP
