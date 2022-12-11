#ifndef ARBOLBINARIO_HPP
#define ARBOLBINARIO_HPP
#include "NodoBinario.hpp"
#include "Central.hpp"
#include <iostream>
#include <cmath>
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
    NodoBinario* borrarNodo(NodoBinario*, int);
    NodoBinario* buscarNodo(int id);
    void inOrden(NodoBinario*);
    void preOrden(NodoBinario*);
    void postOrden(NodoBinario*);
    void mostrarCentrales(NodoBinario* raiz);
    void mostrarEstadistica(NodoBinario* raiz, int N3);
    bool esHoja(NodoBinario* nodo) { return !nodo->derecho && !nodo->izquierdo; }
    NodoBinario* getPadre(NodoBinario* , NodoBinario*);
    void buscarPaquete(NodoBinario*raiz,string ID);
    NodoBinario* getMin(NodoBinario*);

    NodoBinario* getRaiz() {
        return raiz;
    }
    void setRaiz(NodoBinario* nodo) {
        raiz = nodo;
    }
    int length = 0;
};
#endif // ARBOLBINARIO_HPP
