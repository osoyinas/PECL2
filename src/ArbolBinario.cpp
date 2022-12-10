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
        else if (punteroRaiz->elemento.ID < id && punteroRaiz->derecho != NULL){
            punteroRaiz = punteroRaiz->derecho;
        }
        else if (punteroRaiz->elemento.ID >= id && punteroRaiz->izquierdo!= NULL){
            punteroRaiz = punteroRaiz->izquierdo;
        }
        else {
            cout<<"No esta"<<endl;
            return punteroRaiz;
        }
    }
    if(punteroRaiz != NULL){
        return punteroRaiz;
    }
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
NodoBinario* ArbolBinario::borrarNodo(NodoBinario* pRaiz, Central elemEnviado) {
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
    inOrden(raiz->derecho);
}

void ArbolBinario :: preOrden(NodoBinario* raiz) {
    if(raiz == NULL) return;
    cout << raiz->elemento.ID << "\n";
    preOrden(raiz->izquierdo);
    preOrden(raiz->derecho);
}
void ArbolBinario :: postOrden(NodoBinario* raiz) {
    if(raiz == NULL) {
    return;
    }
    postOrden(raiz->izquierdo);
    postOrden(raiz->derecho);
    cout << raiz->elemento.ID << "  "<<raiz->elemento.localidad<< "\n";
}
void ArbolBinario :: mostrarEstadistica(NodoBinario* raiz){
    if(raiz == NULL) {
        return;
    }
    mostrarEstadistica(raiz->izquierdo);
    mostrarEstadistica(raiz->derecho);
    cout << "ID: "<<raiz->elemento.ID<<"  Localidad: "<<raiz->elemento.localidad<< "  Paquetes: "<< raiz->elemento.listaPaquetes.len <<endl;
}
void ArbolBinario :: mostrarCentrales(NodoBinario* raiz){
    if(raiz == NULL) {
    return;
    }
    mostrarCentrales(raiz->izquierdo);
    mostrarCentrales(raiz->derecho);
    cout << "***********************************************************************"<<endl;
    cout <<"CP ->"<<getID(raiz->elemento.ID) << "\t"<<"Localidad -> "<<raiz->elemento.localidad<< "\n";
    cout << "\n";
    raiz->elemento.listaPaquetes.mostrar();
}
void ArbolBinario :: buscarPaquete(NodoBinario* raiz,string ID){
    if(raiz == NULL){
        return;
    }
    if(getCodigoIdStr(raiz->elemento.listaPaquetes.buscarNodo(ID).id) == ID){
        cout <<setw(7)<<"ID"<<setw(15)<<"NIF"<<setw(25)<<"Coordenadas" <<setw(15)<<"CP"<< endl;
        cout << setw(7)<<getCodigoIdStr(raiz->elemento.listaPaquetes.buscarNodo(ID).id)<<setw(15)
        <<getNifStr(raiz->elemento.listaPaquetes.buscarNodo(ID).nif)<<setw(25)<<getCoordenadaStr(raiz->elemento.listaPaquetes.buscarNodo(ID).coords)
        <<setw(15)<<getID(raiz->elemento.listaPaquetes.buscarNodo(ID).CP) <<endl;
    }
    else{
        if(!esHoja(raiz)){
            if(raiz->izquierdo){
                buscarPaquete(raiz->izquierdo,ID);
            }
            if(raiz->derecho){
                buscarPaquete(raiz->derecho,ID);
            }

        }

    }
}

