#include "Lista.hpp"
const int ASCENDENTE=0;
const int DESCENDENTE=1;

string getID(int cp){

    string str = "";
    for(int i = 0; i < 4 - int(to_string(cp).size()) ; i++){
        str+="0";
    }
    str+=to_string(cp);
    return str;
}

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
    len++;
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
            len--;
            delete aux;
        }
        else {
            aux=final;
            final=final->anterior;
            aux->anterior=NULL;
            final->siguiente=NULL;
            len--;
            delete aux;
        }
    }
    else if(tipoBorrado=='p') {//Eliminaci�n por el Principio
        pnodo aux=NULL;
        if((cabeza==final)) {//S�lo hay elemento
            aux=cabeza;
                cabeza = final = NULL;
                aux=NULL;
                len--;
                delete aux;
            }
        else {
            aux=cabeza;
            cabeza=cabeza->siguiente;
            aux->siguiente=NULL;
            cabeza->anterior=NULL;
            len--;
            delete aux;
        }
    }
}
void Lista::recorrerLista (int orden) {
    pnodo aux;
    cout <<setw(7)<<"ID"<<setw(15)<<"NIF"<<setw(25)<<"Coordenadas" <<setw(15)<<"CP"<< endl;
    if (orden == ASCENDENTE) {
        esPrimero();
        aux = cabeza;
        while(aux) {
            cout << setw(7)<<getCodigoIdStr(aux->valor.id)<<setw(15)<<getNifStr(aux->valor.nif)<<setw(25)<<getCoordenadaStr(aux->valor.coords)<<setw(15)<<getID(aux->valor.CP) <<endl;
            aux = aux->siguiente;
        }
    }
    else {
        esUltimo();
        aux = final;
        while(aux) {
            cout << setw(7)<<getCodigoIdStr(aux->valor.id)<<setw(15)<<getNifStr(aux->valor.nif)<<setw(25)<<getCoordenadaStr(aux->valor.coords)<<setw(15)<<getID(aux->valor.CP)<<endl;
            aux = aux->anterior;
        }
    }
    cout << endl;
}
Paquete Lista::buscarNodo(string ID){
    pnodo aux=NULL;
    esPrimero();
    aux = cabeza;
    while(aux) {
        if(getCodigoIdStr(aux->valor.id) == ID){
            return aux->valor;
        }
        aux = aux->siguiente;
    }
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
void Lista::mostrar(){
    recorrerLista(0);
}

Paquete Lista::valorActual() {
    if (!listaVacia()) return actual->valor;
}


