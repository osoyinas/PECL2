#ifndef ARBOLBINARIO_HPP
#define ARBOLBINARIO_HPP
#include "NodoBinario.hpp"
class ArbolBinario
{
    private:
        pNodo raiz, actual = NULL;
        int contador, altura;
        void podar(pNodo &nodo);
        void auxContador(pNodo nodo);
        void auxAltura(pNodo nodo, int a);
        void mostrar(int &d);
    public:
        ArbolBinario();
        ~ArbolBinario();
        void buscarNodo (char v);
        void insertarNodo (char v);
        void borrarNodo (char v);
        bool esVacio(pNodo nodo);
        bool esHoja(pNodo nodo);
        int numeroNodos();
        int getAlturaArbol();
        char getValorActual();
        void esRaiz();
        void inOrden(NodoBinario *nodo);
        void preOrden(NodoBinario *nodo);
        void postOrden(NodoBinario *nodo);
};

#endif // ARBOLBINARIO_HPP
