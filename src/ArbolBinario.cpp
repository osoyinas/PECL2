#include "ArbolBinario.hpp"
using namespace std;
ArbolBinario::ArbolBinario(){}
void ArbolBinario::podar(pNodoBinario &nodo){
    if(nodo){
        podar(nodo->izquierda); // Podar izquierdo
        podar(nodo->derecha);// Podar derecho
        delete nodo;// Eliminar nodo
        nodo = NULL;
    }
}
bool ArbolBinario::buscarNodo(int dato){
    actual = raiz;
    while(!esVacio(actual)){
        if(dato == actual->dato) return true;
        else
        if(dato > actual->dato) actual = actual->derecha;
        else if(dato < actual->dato) actual = actual->izquierda;
    }
    return false;
}
void ArbolBinario::insertarNodo(int dato){
    NodoBinario *padre = NULL;
    actual = raiz;
    while(!esVacio(actual) && dato != actual->dato){
        padre = actual;
        if(dato > actual->dato) actual = actual->derecha;
        else if(dato < actual->dato) actual = actual->izquierda;
    }
    if(!esVacio(actual)) return;
    if(esVacio(padre)) raiz = new NodoBinario(dato);
    else if(dato < padre->dato) padre->izquierda = new NodoBinario(dato);
    else if(dato > padre->dato) padre->derecha = new NodoBinario(dato);
}
void ArbolBinario::borrarNodo(int dato){
    NodoBinario *padre = NULL;
    NodoBinario *nodo;
    char aux;
    actual = raiz;
    while(!esVacio(actual)){
        if(dato == actual->dato){ // Si el valor está en el nodo actual
            if(esHoja(actual)){
            if(padre) // Si tiene padre (no es el nodo raiz)
            if(padre->derecha == actual) padre->derecha = NULL;
            else if(padre->izquierda == actual) padre->izquierda = NULL;
            delete actual; // Borrar el nodo
            actual = NULL;
            return;
            }
            else{
            padre = actual;
            if(actual->derecha){
                nodo = actual->derecha;
                while(nodo->izquierda){
                padre = nodo;
                nodo = nodo->izquierda;
                }
            }
                else{
                    nodo = actual->izquierda;
                    while(nodo->derecha){
                        padre = nodo;
                        nodo = nodo->derecha;
                    }
                }
            aux = actual->dato;
            actual->dato = nodo->dato;
            nodo->dato = aux;
            actual = nodo;
            }
        }
        else{
            padre = actual;
            if(dato > actual->dato) actual = actual->derecha;
            else if(dato < actual->dato) actual = actual->izquierda;
        }
    }
}
void ArbolBinario::preOrden(pNodoBinario nodo){
    if (nodo!= NULL){
        cout << nodo->dato <<" ";
        preOrden(nodo->izquierda);
        preOrden(nodo->derecha);
    }
}
void ArbolBinario::postOrden(pNodoBinario nodo){
    if (nodo!= NULL){
        postOrden(nodo->izquierda);
        postOrden(nodo->derecha);
        cout << nodo->dato <<" ";
    }
}
void ArbolBinario::inOrden(pNodoBinario nodo){
    if (nodo!= NULL){
        inOrden(nodo->izquierda);
        cout << nodo -> dato <<" ";
        inOrden(nodo->derecha);
    }
}
