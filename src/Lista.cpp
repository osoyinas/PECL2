#include "Lista.hpp"
const int ASCENDENTE=0;
const int DESCENDENTE=1;

Lista::Lista() {
    cabeza = NULL;
    actual = NULL;
    final = NULL;
}
Lista::~Lista() {
    pnodo aux;
    esPrimero();
    while(cabeza){
        aux = cabeza;
        cabeza = cabeza->siguiente;
        delete aux;
    }
    cabeza=NULL;
    actual=NULL;
    final=NULL;
}
void Lista::insertarNodo(Paquete v, char c) {
    pnodo aux;
    char tipoInsercion;
    tipoInsercion=c;
    if(listaVacia()) { // Si la lista est� vac�a
        aux = new NodoLista(v,NULL,NULL);
        final=cabeza=aux;
    }
    else if (tipoInsercion=='f') {//Inserci�n por el final
        aux= new NodoLista(v,NULL,NULL);
        aux->anterior=final;
        final->siguiente=aux;
        final=aux;
    }
    else if (tipoInsercion=='p') {//Inserci�n por el principio
        aux= new NodoLista(v,NULL,NULL);
        aux->siguiente=cabeza;
        cabeza->anterior=aux;
        cabeza=aux;
    }
}

void Lista::borrarNodo(char c) {
    char tipoBorrado;
    tipoBorrado=c;
    if(tipoBorrado=='f') {//Eliminaci�n por el final
        pnodo aux=NULL;
        if((cabeza==final)) { //S�lo hay elemento
            aux=final;
            cabeza = final = NULL;
            aux=NULL;
            delete aux;
        }
        else {
            aux=final;
            final=final->anterior;
            aux->anterior=NULL;
            final->siguiente=NULL;
            delete aux;
        }
    }
    else if(tipoBorrado=='p') {//Eliminaci�n por el Principio
        pnodo aux=NULL;
        if((cabeza==final)) {//S�lo hay elemento
            aux=cabeza;
                cabeza = final = NULL;
                aux=NULL;
                delete aux;
            }
        else {
            aux=cabeza;
            cabeza=cabeza->siguiente;
            aux->siguiente=NULL;
            cabeza->anterior=NULL;
            delete aux;
        }
    }
}
void Lista::recorrerLista (int orden) {
    pnodo aux;
    if (orden == ASCENDENTE) {
        esPrimero();
        aux = cabeza;
        while(aux) {
            cout << getCodigoIdStr(aux->valor.id)<< "-> ";
            aux = aux->siguiente;
        }
    }
    else {
        esUltimo();
        aux = final;
        while(aux) {
            cout << getCodigoIdStr(aux->valor.id) << "-> "; aux = aux->anterior;
        }
    }
    cout << endl;
}
Paquete Lista::getUlt(){

    return final->valor;

}
bool Lista::listaVacia(){
    return cabeza == NULL;
}

void Lista::esSiguiente(){
    if(actual) actual = actual->siguiente;
}

void Lista::esAnterior() {
    if(actual) actual = actual->anterior;
}

void Lista::esPrimero() {
    actual=cabeza;
}

void Lista::esUltimo() {
    actual=final;
}

bool Lista::esActual() {
    return actual != NULL;
}

Paquete Lista::valorActual() {
    if (!listaVacia()) return actual->valor;
}
