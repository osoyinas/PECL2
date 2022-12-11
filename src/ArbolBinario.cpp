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
            cout<<"No existe la central indicada."<<endl;
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
NodoBinario* ArbolBinario::borrarNodo(NodoBinario* pRaiz, int id) {
    if(pRaiz == NULL) {
        cout << "\n El Nodo que no existe" << endl;
    }
    else if(id < pRaiz->elemento.ID) {
        pRaiz->izquierdo = borrarNodo(pRaiz->izquierdo, id);
    }
    else if(id > pRaiz->elemento.ID) {
        pRaiz->derecho = borrarNodo(pRaiz->derecho, id);
    }
    else {
        if(pRaiz->izquierdo == NULL && pRaiz->derecho == NULL) {
            pRaiz = NULL;
            delete pRaiz;
        }
        else if(raiz->izquierdo == NULL) {
            NodoBinario* tempo = pRaiz;
            pRaiz = pRaiz->derecho;
            delete tempo;
        }
        else if(pRaiz->derecho == NULL)
        {
            NodoBinario* tempo = pRaiz;
            pRaiz = pRaiz->izquierdo;
            delete tempo;
        }
        else
        {
            NodoBinario* tempo = getMin(pRaiz->derecho);
            pRaiz->elemento = tempo->elemento;
            pRaiz->izquierdo = borrarNodo(pRaiz->derecho, tempo->elemento.ID);
        }
    }
    return pRaiz;
    }
    /*
        if(pRaiz == NULL) {
            cout << "\n El Nodo que no existe" << endl;
            return;
        }
        if(esHoja(pRaiz)){
            pRaiz = NULL;
            delete pRaiz;
        }
        if (pRaiz->derecho && pRaiz->izquierdo){
            NodoBinario* aux;
            Nodobinario* padreAux;
            aux = getMin(pRaiz->derecho);
            padreAux = getPadre(raiz, aux);
            padreAux->izquierdo = NULL;
            getPadre(raiz,pRaiz)->derecho

        }
        else if(pRaiz->derecho){

        }
        else if (pRaiz->izquierdo){

        }*/

NodoBinario* ArbolBinario :: getPadre(NodoBinario* raiz, NodoBinario* hijo) {
    if(raiz == NULL) {
        return NULL;
    }
    if(raiz->derecho == hijo || raiz->izquierdo == hijo){
        return raiz;
    }
    else{
        getPadre(raiz->izquierdo, hijo);
        getPadre(raiz->derecho, hijo);
    }
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
void ArbolBinario :: mostrarEstadistica(NodoBinario* raiz, int N2){
    if(raiz == NULL) {
        return;
    }
    mostrarEstadistica(raiz->izquierdo, N2);
    mostrarEstadistica(raiz->derecho, N2);
    float p = (float)(raiz->elemento.listaPaquetes.len)*100/(float)N2;
    float porcentaje = round(p*100)/100;
    cout <<setfill(' ')<< setw(23) << raiz->elemento.localidad << "\t\t"<<getID(raiz->elemento.ID) << "\t\t"<< raiz->elemento.listaPaquetes.len  << "\t\t"<< porcentaje <<"%"<< endl;
}


void ArbolBinario :: mostrarCentrales(NodoBinario* raiz){
    if(raiz == NULL) {
    return;
    }
    mostrarCentrales(raiz->izquierdo);
    mostrarCentrales(raiz->derecho);
    cout<<endl;
    cout <<"-----------------------------------------------------------------"<<endl;
    cout <<getID(raiz->elemento.ID)<<setw(60)<<raiz->elemento.localidad<< endl;
    cout <<"-----------------------------------------------------------------"<<endl;
    raiz->elemento.listaPaquetes.mostrar();
    cout <<"-----------------------------------------------------------------"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;

}
void ArbolBinario :: buscarPaquete(NodoBinario* raiz,string ID){
    if(raiz == NULL){
        return;
    }
    if(getCodigoIdStr(raiz->elemento.listaPaquetes.buscarPaquete(ID).id) == ID){
        cout <<setw(7)<<"ID"<<setw(15)<<"NIF"<<setw(25)<<"Coordenadas" <<setw(15)<<"CP"<< endl;
        cout << setw(7)<<getCodigoIdStr(raiz->elemento.listaPaquetes.buscarPaquete(ID).id)<<setw(15)
        <<getNifStr(raiz->elemento.listaPaquetes.buscarPaquete(ID).nif)<<setw(25)<<getCoordenadaStr(raiz->elemento.listaPaquetes.buscarPaquete(ID).coords)
        <<setw(15)<<getID(raiz->elemento.listaPaquetes.buscarPaquete(ID).CP) <<endl;
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

