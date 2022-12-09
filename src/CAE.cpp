#include "CAE.hpp"

CAE::CAE(){
    vector<int> ids; //lista que almacena los IDS que identifican a los paquetes y las centrales.
    Semicoord lmin = crearSemicoordenada(40, 6, 0);
    Semicoord lmax = crearSemicoordenada(40, 34, 0);
    Semicoord lomin = crearSemicoordenada(-3, 5, 30);
    Semicoord lomax= crearSemicoordenada(-3, 34, 30);

    //Generacion de centrales
    for (int i = 0; i < 10; i++){
        int id = generarID(); //Se genera un ID
        ids.push_back(id);
        Central central = crearCentral(localidades[i], id); //Creacion de la central.
        if(i == 0){
            arbolCentrales.setRaiz(arbolCentrales.crearNodo(central)); //se establece la raiz del arbol.
        }
        else{
            arbolCentrales.insertarNodo(arbolCentrales.getRaiz(), central); //se inserta la central en el arbol.
        }
    }
    //Generacion de paquetes
    for (int i = 0; i < 100; i++){

        int random = generarRandom(0, 7);
        cout<<random<<endl;
        Paquete paquete = generarPaquete(i,lmin,lmax,lomin,lomax, ids[random]); //creacion de un paquete.
        listaPaquetes.insertarNodo(paquete,'p');    //Inserccion del paquete al principio de la lista.
    }
}
void CAE::setData(int N1,int N2,int N3){
    this->N1 = N1;
    this->N2 = N2;
    this->N3 = N3;
}
void CAE::insertarPaquetes() {

    for (int i = 0; i<N3; i++){
        Paquete pq = listaPaquetes.getUlt(); // Ultimo paquete
        listaPaquetes.borrarNodo('f'); //Eliminacion del ultimo paquete
        insertarPaquete(pq);
    }
}
void CAE::insertarPaquete(Paquete paquete){
    int idPaquete = paquete.CP;
}
void mostrar();
void insertarCP(string CP, string localidad);
void borrarCP(string CP);
void mostrarPaquetes(Central central);
void buscarPaquete(string id);
void eliminarPaquete(string id);
void transferirPaquete(string id, string origenCP, string destinoCP);
