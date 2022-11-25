#ifndef NODOLISTA_H
#define NODOLISTA_H

#define NULL NULL
class NodoLista
{
    private:
        int valor;
        NodoLista *siguiente;
        NodoLista *anterior;
        friend class Lista;
    public:
        NodoLista(int v, NodoLista *sig = NULL, NodoLista *ant = NULL)
        {
            valor = v;
            siguiente = sig;
            anterior = ant;
        }
};
typedef NodoLista *pnodo;
#endif // NODOLISTA_H
