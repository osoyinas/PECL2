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

NodoBinario* ArbolBinario :: getMax(NodoBinario* punteroRaiz) {
    while(punteroRaiz->derecho != NULL)
    {
        punteroRaiz = punteroRaiz->derecho;
    }
    return punteroRaiz;
}
NodoBinario* ArbolBinario :: buscarNodo(int id) {
    NodoBinario* punteroRaiz = this->pRaiz;
    while(punteroRaiz != NULL){
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

void ArbolBinario::borrarNodo(NodoBinario* &raiz, int ID)
{
    if (raiz == NULL)
        return;

    if (ID < raiz->elemento.ID)
        borrarNodo(raiz->izquierdo, ID);
    else if (ID > raiz->elemento.ID)
        borrarNodo(raiz->derecho, ID);
    // encontramos el nodo a borrar
    else {
        // caso 1: el nodo es una hoja (no tiene hijos)
        if (raiz->izquierdo == NULL && raiz->derecho == NULL) {
            delete raiz;
            raiz = NULL;
        }
        // caso 2: el nodo tiene solo un hijo
        else if (raiz->izquierdo == NULL) {
            NodoBinario* tmp = raiz;
            raiz = raiz->derecho;
            delete tmp;
        }
        else if (raiz->derecho == NULL) {
            NodoBinario* tmp = raiz;
            raiz = raiz->izquierdo;
            delete tmp;
        }
        // caso 3: el nodo tiene dos hijos
        else {
            NodoBinario* tmp = raiz->izquierdo;
            while (tmp->derecho != NULL) //Obtiene el minimo
                tmp = tmp->derecho;
            raiz->elemento = tmp->elemento;
            borrarNodo(raiz->izquierdo, tmp->elemento.ID);
        }
    }
}

void ArbolBinario :: inOrden(NodoBinario* pRaiz) {
    if(pRaiz == NULL) {
        return;
    }

    inOrden(pRaiz->izquierdo);
    cout << pRaiz->elemento.ID << "\n";
    inOrden(pRaiz->derecho);
}

void ArbolBinario :: preOrden(NodoBinario* pRaiz) {
    if(pRaiz == NULL) return;
    cout << pRaiz->elemento.ID << "\n";
    preOrden(pRaiz->izquierdo);
    preOrden(pRaiz->derecho);
}
void ArbolBinario :: postOrden(NodoBinario* pRaiz) {
    if(pRaiz == NULL) {
    return;
    }
    postOrden(pRaiz->izquierdo);
    postOrden(pRaiz->derecho);
    cout << pRaiz->elemento.ID << "  "<<pRaiz->elemento.localidad<< "\n";
}
void ArbolBinario :: mostrarEstadistica(NodoBinario* pRaiz, int N2){
    if(pRaiz == NULL) {
        return;
    }
    mostrarEstadistica(pRaiz->izquierdo, N2);
    mostrarEstadistica(pRaiz->derecho, N2);
    float p = (float)(pRaiz->elemento.listaPaquetes.len)*100/(float)N2;
    float porcentaje = round(p*100)/100;
    cout <<setfill(' ')<< setw(23) << pRaiz->elemento.localidad << "\t\t"<<getID(pRaiz->elemento.ID) << "\t\t"<< pRaiz->elemento.listaPaquetes.len  << "\t\t"<< porcentaje <<"%"<< endl;
}


void ArbolBinario :: mostrarCentrales(NodoBinario* pRaiz) {
    if(pRaiz == NULL) {
    return;
    }
    mostrarCentrales(pRaiz->izquierdo);
    mostrarCentrales(pRaiz->derecho);
    cout<<endl;
    cout <<"-----------------------------------------------------------------"<<endl;
    cout <<getID(pRaiz->elemento.ID)<<setw(60)<<pRaiz->elemento.localidad<< endl;
    cout <<"-----------------------------------------------------------------"<<endl;
    pRaiz->elemento.listaPaquetes.mostrar();
    cout <<"-----------------------------------------------------------------"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;

}
void ArbolBinario :: buscarPaquete(NodoBinario* pRaiz,string ID) {
    if(pRaiz == NULL){
        return;
    }
    if(getCodigoIdStr(pRaiz->elemento.listaPaquetes.buscarPaquete(ID).id) == ID) {
        cout <<setw(7)<<"ID"<<setw(15)<<"NIF"<<setw(25)<<"Coordenadas" <<setw(15)<<"CP"<< endl;
        cout << setw(7)<<getCodigoIdStr(pRaiz->elemento.listaPaquetes.buscarPaquete(ID).id)<<setw(15)
        <<getNifStr(pRaiz->elemento.listaPaquetes.buscarPaquete(ID).nif)<<setw(25)<<getCoordenadaStr(pRaiz->elemento.listaPaquetes.buscarPaquete(ID).coords)
        <<setw(15)<<getID(pRaiz->elemento.listaPaquetes.buscarPaquete(ID).CP) <<endl;
    }
    else{
        if(!esHoja(pRaiz)) {
            if(pRaiz->izquierdo) {
                buscarPaquete(pRaiz->izquierdo,ID);
            }
            if(pRaiz->derecho) {
                buscarPaquete(pRaiz->derecho,ID);
            }
        }
    }
}

