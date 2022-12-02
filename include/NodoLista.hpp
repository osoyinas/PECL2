#ifndef NODOLISTA_H
#define NODOLISTA_H
#include <iostream>
#include "Paquete.hpp";
class NodoLista
{
    private:
        Paquete valor;
        NodoLista *siguiente;
        NodoLista *anterior;
        friend class Lista;
    public:
        NodoLista(Paquete v, NodoLista *sig, NodoLista *ant);
};
typedef NodoLista *pnodo;
#endif // NODOLISTA_H
