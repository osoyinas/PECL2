#include "CAE.hpp"
#include "Central.hpp"

using std::stoi;

CAE::CAE(int N1, int N2, int N3, int N4){
    vector<int> ids; //lista que almacena los IDS que identifican a los paquetes y las centrales.
    Semicoord lmin = crearSemicoordenada(40, 6, 0);
    Semicoord lmax = crearSemicoordenada(40, 34, 0);
    Semicoord lomin = crearSemicoordenada(-3, 5, 30);
    Semicoord lomax= crearSemicoordenada(-3, 34, 30);
    this->N1 = N1;
    this->N2 = N2;
    this->N3 = N3;
    this->N4 = N4;

    //Generacion de centrales
    for (int i = 0; i < N1; i++){
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
    for (int i = 0; i < N2; i++){

        int random = generarRandom(0, ids.size()-1);
        Paquete paquete = generarPaquete(i,lmin,lmax,lomin,lomax, ids[random]); //creacion de un paquete.
        listaPaquetes.insertarNodo(paquete,'p');    //Inserccion del paquete al principio de la lista.
    }
}
void CAE::insertarPaquetes() {
    int iteraciones;
    if (listaPaquetes.len<N3){
        iteraciones = listaPaquetes.len;
    }
    else{
        iteraciones = N3;
    }
    for (int i = 0; i<N3; i++){
        if(tienePaquetes()){
            Paquete pq = listaPaquetes.getUlt(); // Ultimo paquete
            listaPaquetes.borrarNodo('f'); //Eliminacion del ultimo paquete
            insertarPaquete(pq);
        }
    }
}

void CAE::insertarPaquete(Paquete paquete){
    paquetesEnviados++;
    int idPaquete = paquete.CP;
    arbolCentrales.buscarNodo(idPaquete)->elemento.addPaquete(paquete);
}

void CAE::mostrar(){
    arbolCentrales.mostrarCentrales(arbolCentrales.getRaiz());
}


void CAE :: insertarCP(string CP, string localidad){
        Central centralInsertada = crearCentral(localidad, stoi(CP));
        arbolCentrales.insertarNodo(arbolCentrales.getRaiz(), centralInsertada);
}

bool CAE :: tienePaquetes(){
    return listaPaquetes.len > 0;
}

int CAE :: getPaquetesEnviados(){
    return paquetesEnviados;
}

void CAE :: resetPaquetesEnviados(){
    paquetesEnviados = 0;
}

void CAE:: examinarCP(string CP){
    cout << "***********************************************************************"<<endl;
    cout <<"CP ->"<<getID(arbolCentrales.buscarNodo(stoi(CP))->elemento.ID) << "\t"<<"Localidad -> "<<arbolCentrales.buscarNodo(stoi(CP))->elemento.localidad<< "\n";
    cout << "\n";
    arbolCentrales.buscarNodo(stoi(CP))->elemento.listaPaquetes.mostrar();
    cin.get();
}

void CAE:: borrarCP(string CP){

}

void CAE:: buscarPaquete(string ID){
    arbolCentrales.buscarPaquete(arbolCentrales.getRaiz(), ID);
    cin.get();
}
void CAE:: extraer(string ID, string CP){

}
void CAE:: llevar(string ID,string CP){

}
void CAE::estadistica() {
    cout<<"Centrales: "<< arbolCentrales.length<<endl;
    arbolCentrales.mostrarEstadistica(arbolCentrales.getRaiz());
    cin.get();
}
