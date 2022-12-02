#ifndef ARBOLBINARIO_HPP
#define ARBOLBINARIO_HPP
#include "NodoBinario.hpp"
class ArbolBinario
{
    private:
        pNodoBinario raiz, actual = NULL;
        int contador, altura;
        void podar(pNodoBinario &nodo);
        void auxContador(pNodoBinario nodo);
        void auxAltura(pNodoBinario nodo, int a);
        void mostrar(int &d);
    public:
        ArbolBinario();
        ~ArbolBinario(){podar(raiz);}
        bool buscarNodo (int v);
        void insertarNodo (int v);
        void borrarNodo (int v);
        bool esVacio(pNodoBinario nodo) {return raiz==NULL;}
        bool esHoja(pNodoBinario nodo) {return !nodo->derecha && !nodo->izquierda;}
        int numeroNodos();
        int getAlturaArbol();
        char getValorActual() {return actual->dato;}
        void esRaiz() {actual = raiz;}
        void inOrden(NodoBinario *nodo);
        void preOrden(NodoBinario *nodo);
        void postOrden(NodoBinario *nodo);
};

#endif // ARBOLBINARIO_HPP
