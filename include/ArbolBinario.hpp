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

public:
    struct NodoBinario* pRaiz;
    ArbolBinario()
    {
        pRaiz = NULL;
    }
    NodoBinario* crearNodo(Central);
    NodoBinario* insertarNodo(NodoBinario*, Central);
    void borrarNodo(NodoBinario* &raiz, int);
    NodoBinario* buscarNodo(int id);
    void inOrden(NodoBinario*);
    void preOrden(NodoBinario*);
    void postOrden(NodoBinario*);
    void mostrarCentrales(NodoBinario* pRaiz);
    void mostrarEstadistica(NodoBinario* pRaiz, int N3);
    bool esHoja(NodoBinario* nodo) { return !nodo->derecho && !nodo->izquierdo; }
    void buscarPaquete(NodoBinario*pRaiz,string ID);
    NodoBinario* getMin(NodoBinario*);

    NodoBinario* getRaiz() {
        return pRaiz;
    }
    void setRaiz(NodoBinario* nodo) {
        pRaiz = nodo;
    }
    int length = 0;
};
#endif // ARBOLBINARIO_HPP
