#include "Lista.hpp"
const int ASCENDENTE=0;
const int DESCENDENTE=1;

Lista::Lista() {
    cabeza = NULL;
    actual = NULL;
    final = NULL;
}
string getID(int cp){

    string str = "";
    for(int i = 0; i < 4 - int(to_string(cp).size()) ; i++){
        str+="0";
    }
    str+=to_string(cp);
    return str;
}

void Lista::insertarNodo(Paquete v, char c) {
    pnodo aux;
    char tipoInsercion;
    tipoInsercion=c;
    if(listaVacia()) { // Si la lista está vacía
        aux = new NodoLista(v,NULL,NULL);
        final=cabeza=aux;
    }
    else if (tipoInsercion=='f') {//Inserción por el final
        aux= new NodoLista(v,NULL,NULL);
        aux->anterior=final;
        final->siguiente=aux;
        final=aux;
    }
    else if (tipoInsercion=='p') {//Inserción por el principio
        aux= new NodoLista(v,NULL,NULL);
        aux->siguiente=cabeza;
        cabeza->anterior=aux;
        cabeza=aux;
    }
}

void Lista::borrarNodo(char c) {
    char tipoBorrado;
    tipoBorrado=c;
    if(tipoBorrado=='f') {//Eliminación por el final
        pnodo aux=NULL;
        if((cabeza==final)) { //Sólo hay elemento
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
    else if(tipoBorrado=='p') {//Eliminación por el Principio
        pnodo aux=NULL;
        if((cabeza==final)) {//Sólo hay elemento
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
int Lista::getLength(){
    int len = 0;
    esPrimero();
    pnodo aux = cabeza;
    while(aux){
        len++;
        aux = aux->siguiente;
    }
    return len;
}
pnodo Lista::buscarNodo(string ID){
    pnodo aux=NULL;
    esPrimero();
    aux = cabeza;
    while(aux) {
        if(getCodigoIdStr(aux->valor.id) == ID){
            return aux;
        }
        aux = aux->siguiente;
    }
}
Paquete Lista::buscarPaquete(string ID){

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

void Lista::borrarPaquete(string ID){
    if(!buscarNodo(ID)){
        cout<<"No existe el paquete paquete indicado"<<endl;
        return;
    }
    if(getCodigoIdStr(cabeza->valor.id) == ID){
        borrarNodo('p');
        return;
    }
    else if(getCodigoIdStr(final->valor.id) == ID){
        borrarNodo('f');
        return;
    }

    pnodo aux = buscarNodo(ID);
    pnodo auxSiguiente = aux->siguiente;
    pnodo auxAnterior = aux->anterior;
    auxAnterior->siguiente = auxAnterior->siguiente->siguiente;
    auxSiguiente->anterior = auxSiguiente->anterior->anterior;
    aux->siguiente = NULL;
    aux->anterior = NULL;
    aux = auxSiguiente = auxAnterior = NULL;
    delete aux;
    delete auxSiguiente;
    delete auxAnterior;
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


