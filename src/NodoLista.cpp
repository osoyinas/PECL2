#include "NodoLista.hpp"

NodoLista::NodoLista(Paquete v, NodoLista *sig = NULL, NodoLista *ant = NULL) {
    valor = v;
    siguiente = sig;
    anterior = ant;
}
