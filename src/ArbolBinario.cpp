#include "ArbolBinario.hpp"

NodoBinario* ArbolBinario :: crearNodo(Central elemEnviado)   // Crea un nuevo nodo y devuelve la referencia a ese nodo. Esto pasa en cada llamada de la función insertarNodo
{
    NodoBinario* nuevoNodo = new  struct NodoBinario(); // poner struct es redundante, pero es seguro
    nuevoNodo->elemento = elemEnviado; // Asignando el elemento enviado a la parte elemento del nodo nuevo
    nuevoNodo->hijoIzquierdo = nuevoNodo->hijoDerecho = NULL;; // Asignando NULL a hijo izquierdo y derecho del nuevo nodo
    return nuevoNodo;
}
NodoBinario* ArbolBinario :: getMin(NodoBinario* punteroRaiz)   // Para obtener el predecesor En-Orden para borrar el nodo del árbol
{
    while(punteroRaiz->hijoIzquierdo != NULL)
    {
        punteroRaiz = punteroRaiz->hijoIzquierdo;
    }
    return punteroRaiz;
}

NodoBinario* ArbolBinario :: insertarNodo(NodoBinario* punteroRaiz, Central elemEnviado)   // Insertando el Nodo
{
    if(punteroRaiz == NULL)
    {
        return crearNodo(elemEnviado);
    }
    if(elemEnviado.CP < punteroRaiz->elemento.CP)
    {
        punteroRaiz->hijoIzquierdo = insertarNodo(punteroRaiz->hijoIzquierdo, elemEnviado);
    }
    if(elemEnviado.CP > punteroRaiz->elemento.CP)
    {
        punteroRaiz->hijoDerecho = insertarNodo(punteroRaiz->hijoDerecho, elemEnviado);
    }
    return punteroRaiz;
}
NodoBinario* ArbolBinario :: borrarNodo(NodoBinario* punteroRaiz, Central elemEnviado)   // Borrando el Nodo
{
    if(punteroRaiz == NULL)
    {
        cout << "\n El Nodo que se quiere borrar no existe !!!" << endl;
        return punteroRaiz;
    }
    else if(elemEnviado.CP < punteroRaiz->elemento.CP)
    {
        punteroRaiz->hijoIzquierdo = borrarNodo(punteroRaiz->hijoIzquierdo, elemEnviado);
    }
    else if(elemEnviado.CP > punteroRaiz->elemento.CP)
    {
        punteroRaiz->hijoDerecho = borrarNodo(punteroRaiz->hijoDerecho, elemEnviado);
    }
    else
    {
        if(punteroRaiz->hijoIzquierdo == NULL && punteroRaiz->hijoDerecho == NULL)
        {
            // Si los hijos son NULL
            delete punteroRaiz;
            punteroRaiz = NULL;
        }
        else if(raiz->hijoIzquierdo == NULL)
        {
            struct NodoBinario* tempo = punteroRaiz;
            punteroRaiz = punteroRaiz->hijoDerecho;
            delete tempo;
        }
        else if(punteroRaiz->hijoDerecho == NULL)
        {
            struct NodoBinario* tempo = punteroRaiz;
            punteroRaiz = punteroRaiz->hijoIzquierdo;
            delete tempo;
        }
        else
        {
            NodoBinario* tempo = getMin(punteroRaiz->hijoDerecho);
            punteroRaiz->elemento = tempo->elemento;
            punteroRaiz->hijoIzquierdo = borrarNodo(punteroRaiz->hijoDerecho, tempo->elemento);
        }
    }
// cout << "\n Elemento borrado: " << elemEnviado << endl;
    return punteroRaiz;
}

void ArbolBinario :: inOrden(NodoBinario* raiz)   // Recorriendo el árbol en en-Orden
{
    if(raiz == NULL)
    {
        return;
    }
    inOrden(raiz->hijoIzquierdo);
    cout << raiz->elemento.CP << "\t";
    inOrden(raiz->hijoDerecho);
}
void ArbolBinario :: preOrden(NodoBinario* raiz)   // Recorriendo el árbol en pre-Orden
{
    if(raiz == NULL) return;
    cout << raiz->elemento.CP << "\t";
    preOrden(raiz->hijoIzquierdo);
    preOrden(raiz->hijoDerecho);
}
void ArbolBinario :: postOrden(NodoBinario* raiz)   // Recorriendo el árbol en post-Orden
{
    if(raiz == NULL) return;
    postOrden(raiz->hijoIzquierdo);
    postOrden(raiz->hijoDerecho);
    cout << raiz->elemento.CP << "\t";
}
