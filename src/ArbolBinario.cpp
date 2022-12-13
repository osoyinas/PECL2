#include "ArbolBinario.hpp"

NodoBinario* ArbolBinario :: crearNodo(Central elemEnviado) {
    NodoBinario* nuevoNodo = new NodoBinario();
    nuevoNodo->elemento = elemEnviado;
    nuevoNodo->izquierdo = nuevoNodo->derecho = NULL;
    return nuevoNodo;
}


NodoBinario* ArbolBinario :: buscarNodo(int id) {
    NodoBinario* punteroRaiz = this->RAIZ;
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
int ArbolBinario::getLength(int len, NodoBinario* raiz){
    if(raiz == NULL)
        return 0;
    else
        return 1+ getLength(len, raiz->izquierdo) + getLength(len, raiz->derecho);

}
NodoBinario* ArbolBinario :: insertarNodo(NodoBinario* RAIZ, Central elemEnviado) {
    if(RAIZ == NULL)
    {
        return crearNodo(elemEnviado);
    }
    if(elemEnviado.ID < RAIZ->elemento.ID)
    {
        RAIZ->izquierdo = insertarNodo(RAIZ->izquierdo, elemEnviado);
    }
    if(elemEnviado.ID > RAIZ->elemento.ID)
    {
        RAIZ->derecho = insertarNodo(RAIZ->derecho, elemEnviado);
    }
    if(RAIZ->elemento.ID == elemEnviado.ID){
    }
    return RAIZ;
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
        if (esHoja(raiz)) {
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

void ArbolBinario :: inOrden(NodoBinario* RAIZ) {
    if(RAIZ == NULL) {
        return;
    }

    inOrden(RAIZ->izquierdo);
    cout << RAIZ->elemento.ID << "\n";
    inOrden(RAIZ->derecho);
}

void ArbolBinario :: preOrden(NodoBinario* RAIZ) {
    if(RAIZ == NULL) return;
    cout << RAIZ->elemento.ID << "\n";
    preOrden(RAIZ->izquierdo);
    preOrden(RAIZ->derecho);
}
void ArbolBinario :: postOrden(NodoBinario* RAIZ) {
    if(RAIZ == NULL) {
    return;
    }
    postOrden(RAIZ->izquierdo);
    postOrden(RAIZ->derecho);
    cout << RAIZ->elemento.ID << "  "<<RAIZ->elemento.localidad<< "\n";
}
void ArbolBinario :: mostrarEstadistica(NodoBinario* RAIZ, int N2){
    if(RAIZ == NULL) {
        return;
    }
    mostrarEstadistica(RAIZ->izquierdo, N2);
    mostrarEstadistica(RAIZ->derecho, N2);
    float p = (float)(RAIZ->elemento.listaPaquetes.getLength())*100/(float)N2;
    float porcentaje = round(p*100)/100;
    cout <<setfill(' ')<< setw(23) << RAIZ->elemento.localidad << "\t\t"<<getID(RAIZ->elemento.ID) << "\t\t"<< RAIZ->elemento.listaPaquetes.getLength()  << "\t\t"<< porcentaje <<"%"<< endl;
}


void ArbolBinario :: mostrarCentrales(NodoBinario* RAIZ) {
    if(RAIZ == NULL) {
    return;
    }
    mostrarCentrales(RAIZ->izquierdo);
    mostrarCentrales(RAIZ->derecho);
    cout<<endl;
    cout <<"-----------------------------------------------------------------"<<endl;
    cout <<getID(RAIZ->elemento.ID)<<setw(60)<<RAIZ->elemento.localidad<< endl;
    cout <<"-----------------------------------------------------------------"<<endl;
    RAIZ->elemento.listaPaquetes.mostrar();
    cout <<"-----------------------------------------------------------------"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;

}
void ArbolBinario :: buscarPaquete(NodoBinario* RAIZ,string ID) {
    if(RAIZ == NULL){
        return;
    }
    if(getCodigoIdStr(RAIZ->elemento.listaPaquetes.buscarPaquete(ID).id) == ID) {
        cout <<setw(7)<<"ID"<<setw(15)<<"NIF"<<setw(25)<<"Coordenadas" <<setw(15)<<"CP"<< endl;
        cout << setw(7)<<getCodigoIdStr(RAIZ->elemento.listaPaquetes.buscarPaquete(ID).id)<<setw(15)
        <<getNifStr(RAIZ->elemento.listaPaquetes.buscarPaquete(ID).nif)<<setw(25)<<getCoordenadaStr(RAIZ->elemento.listaPaquetes.buscarPaquete(ID).coords)
        <<setw(15)<<getID(RAIZ->elemento.listaPaquetes.buscarPaquete(ID).CP) <<endl;
    }
    else{
        if(!esHoja(RAIZ)) {
            if(RAIZ->izquierdo) {
                buscarPaquete(RAIZ->izquierdo,ID);
            }
            if(RAIZ->derecho) {
                buscarPaquete(RAIZ->derecho,ID);
            }
        }
    }
}

