#include "ArbolBinario.hpp"

NodoBinario* ArbolBinario :: crearNodo(Central elemEnviado) {
    NodoBinario* nuevoNodo = new NodoBinario();
    nuevoNodo->elemento = elemEnviado;
    nuevoNodo->izquierdo = nuevoNodo->derecho = NULL;
    length++;
    return nuevoNodo;
}
NodoBinario* ArbolBinario :: getMin(NodoBinario* punteroRaiz) {
    while(punteroRaiz->izquierdo != NULL)
    {
        punteroRaiz = punteroRaiz->izquierdo;
    }
    return punteroRaiz;
}
NodoBinario* ArbolBinario :: buscarNodo(int id) {
    NodoBinario* punteroRaiz = this->raiz;
    while(punteroRaiz != NULL)
    {
        if(punteroRaiz->elemento.ID == id){
            return punteroRaiz;
        }
        else if (punteroRaiz->elemento.ID < id){
            punteroRaiz = punteroRaiz->derecho;
        }
        else if (punteroRaiz->elemento.ID >= id){
            punteroRaiz = punteroRaiz->izquierdo;
        }
    }
    return punteroRaiz;
}
NodoBinario* ArbolBinario :: insertarNodo(NodoBinario* pRaiz, Central elemEnviado) {
    if(pRaiz == NULL)
    {
        return crearNodo(elemEnviado);
    }
    if(elemEnviado.ID < pRaiz->elemento.ID)
    {
        pRaiz->izquierdo = insertarNodo(pRaiz->izquierdo, elemEnviado);
    }
    if(elemEnviado.ID > pRaiz->elemento.ID)
    {
        pRaiz->derecho = insertarNodo(pRaiz->derecho, elemEnviado);
    }
    if(pRaiz->elemento.ID == elemEnviado.ID){
        length++;
    }
    return pRaiz;
}
NodoBinario* ArbolBinario :: borrarNodo(NodoBinario* pRaiz, Central elemEnviado) {
    if(pRaiz == NULL)
    {
        cout << "\n El Nodo que no existe" << endl;
        return pRaiz;
    }
    else if(elemEnviado.ID < pRaiz->elemento.ID)
    {
        pRaiz->izquierdo = borrarNodo(pRaiz->izquierdo, elemEnviado);
    }
    else if(elemEnviado.ID > pRaiz->elemento.ID)
    {
        pRaiz->derecho = borrarNodo(pRaiz->derecho, elemEnviado);
    }
    else
    {
        if(pRaiz->izquierdo == NULL && pRaiz->derecho == NULL)
        {
            delete pRaiz;
            pRaiz = NULL;
        }
        else if(raiz->izquierdo == NULL)
        {
            struct NodoBinario* tempo = pRaiz;
            pRaiz = pRaiz->derecho;
            delete tempo;
        }
        else if(pRaiz->derecho == NULL)
        {
            struct NodoBinario* tempo = pRaiz;
            pRaiz = pRaiz->izquierdo;
            delete tempo;
        }
        else
        {
            NodoBinario* tempo = getMin(pRaiz->derecho);
            pRaiz->elemento = tempo->elemento;
            pRaiz->izquierdo = borrarNodo(pRaiz->derecho, tempo->elemento);
        }
    }
    return pRaiz;
}

void ArbolBinario :: inOrden(NodoBinario* raiz) {
    if(raiz == NULL) {
        return;
    }
    inOrden(raiz->izquierdo);
    cout << raiz->elemento.ID << "\n";
    raiz->elemento.listaPaquetes.mostrar();
    inOrden(raiz->derecho);
}

void ArbolBinario :: preOrden(NodoBinario* raiz) {
    if(raiz == NULL) return;
    cout << raiz->elemento.ID << "\n";
    preOrden(raiz->izquierdo);
    preOrden(raiz->derecho);
}
void ArbolBinario :: postOrden(NodoBinario* raiz)
{

    if(raiz == NULL) {
    return;
    }
    postOrden(raiz->izquierdo);
    postOrden(raiz->derecho);
    cout << raiz->elemento.ID << "  "<<raiz->elemento.localidad<< "\n";
}


