#include "Cola.hpp"

Cola::Cola()
{
    primero = NULL;
    ultimo = NULL;
}

/**
Inserta el elemento introducido en la cola.
*/
void Cola::insertar(Etiqueta v)
{
    pnodoCola nuevo;
    nuevo = new NodoCola(v, NULL);
    if (ultimo)
        ultimo->siguiente = nuevo;
    ultimo = nuevo;
    if(!primero){
        primero = nuevo;
}
}

/**
Devuelve una lista (vector) con los elementos actuales de la cola.
*/
vector<Etiqueta> Cola::getArray()
{
    vector<Etiqueta> lista;
    pnodoCola aux = primero;
    while(aux) {
        lista.push_back(aux->valor);
        aux = aux->siguiente;
    }
    return lista;
}

/**
Elimina el primer elemento para salir(el primero que ha entrado).
*/
void Cola::eliminar()
{
    pnodoCola aux;
    aux = primero;

    if(aux){
        primero = aux->siguiente;
        delete aux;
        if(!primero){
            ultimo = NULL;
        }
    }
}
/**
Devuelve el valor del primer elemento que ha entrado.
*/
Etiqueta Cola::verPrimero(){
    return primero->valor;
}

/**
Devuelve un booleano dependiendo de si la lista esta vacia o no.
*/
bool Cola::vacia(){
    return primero == NULL && ultimo == NULL;
}


