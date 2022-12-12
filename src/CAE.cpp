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
    for (int i = 0; i<iteraciones; i++){
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
    if(arbolCentrales.buscarNodo(idPaquete)->elemento.ID == paquete.CP){
        arbolCentrales.buscarNodo(idPaquete)->elemento.addPaquete(paquete);
    }
}
void CAE::mostrar(){
    cout <<endl;
    cout <<"                              *CAE*                              "<< endl;
    cout <<"-----------------------------------------------------------------"<<endl;
    cout <<endl;
    listaPaquetes.mostrar();
    cout <<"-----------------------------------------------------------------"<<endl;
    cout<<endl<<endl;
    cout <<"                           *CENTRALES*                           "<< endl;


    arbolCentrales.mostrarCentrales(arbolCentrales.getRaiz());
}

bool cp_valida(string CP){
  bool valida = true;
  for (char c : CP) {
    if (!isdigit(c)) {
      valida = false;
      break;
    }
  }
  return valida && CP.size()==4;
}
void CAE :: insertarCP(string CP, string localidad){

  // Comprobamos si cada carácter de str es un dígito
    if(cp_valida(CP)){
        Central centralInsertada = crearCentral(localidad, stoi(CP));
        arbolCentrales.insertarNodo(arbolCentrales.getRaiz(), centralInsertada);
        examinarCP(CP);
    }
    else{
        cout<<"Tiene que insertar un codigo de CP valido, 4 digitos"<<endl;

    }
    cin.get();
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
    if(!cp_valida(CP)){
        return;
    }
    if(arbolCentrales.buscarNodo(stoi(CP))->elemento.ID == stoi(CP)){
        cout<<"No existe la central indicada"<<endl;
        return;
    }
    cout <<"-----------------------------------------------------------------"<<endl;
    cout <<getID(arbolCentrales.buscarNodo(stoi(CP))->elemento.ID)<<setw(60)<<arbolCentrales.buscarNodo(stoi(CP))->elemento.localidad<< endl;
    cout <<"-----------------------------------------------------------------"<<endl;
    arbolCentrales.buscarNodo(stoi(CP))->elemento.listaPaquetes.mostrar();
    cout <<"-----------------------------------------------------------------"<<endl;
}

void CAE:: borrarCP(string CP){
    if(!cp_valida(CP)){
        cout<<"Inserte un formato valido."<<endl;
        cin.get();
        return;
    }
    if(arbolCentrales.buscarNodo(stoi(CP))->elemento.ID == stoi(CP)){
        arbolCentrales.borrarNodo(arbolCentrales.pRaiz, stoi(CP));
        cout<<"Central eliminada correctamente"<<endl;
    }
    else cout<<"No existe la central."<<endl;
    cin.get();

}

void CAE:: buscarPaquete(string ID){
    arbolCentrales.buscarPaquete(arbolCentrales.getRaiz(), ID);
    cin.get();
}
void CAE:: extraer(string ID, string CP){
    if(!cp_valida(CP)){
        cout<<"Inserte un formato valido."<<endl;
        cin.get();
        return;
    }
    arbolCentrales.buscarNodo(stoi(CP))->elemento.listaPaquetes.borrarPaquete(ID);
    cin.get();
}
void CAE:: llevar(string ID,string CP){
    if(!cp_valida(CP)){
        cout<<"Inserte un formato valido."<<endl;
        cin.get();
        return;
    }
    if(listaPaquetes.buscarNodo(ID)){
        Paquete paquete = listaPaquetes.buscarPaquete(ID);
        listaPaquetes.borrarPaquete(ID);
        arbolCentrales.buscarNodo(stoi(CP))->elemento.addPaquete(paquete);
        cout<<"Paquete con ID " <<ID<<" insertado en "<< CP<<"."<<endl;

    }
    else{
        cout<<"El paquete no se encuentra en el CAE."<<endl;
    }
    cin.get();
}
void CAE:: llevar(string CPOrigen,string CPDestino, string ID){
    if(!cp_valida(CPOrigen) || !cp_valida(CPDestino)){
        cout<<"Inserte un formato valido."<<endl;
        cin.get();
        return;
    }
    if(arbolCentrales.buscarNodo(stoi(CPOrigen))->elemento.listaPaquetes.buscarNodo(ID)){ //comprueba si existe el paquete
        Paquete paquete = arbolCentrales.buscarNodo(stoi(CPOrigen))->elemento.listaPaquetes.buscarPaquete(ID); //seleccion del paquete de la central de origen
        arbolCentrales.buscarNodo(stoi(CPOrigen))->elemento.listaPaquetes.borrarPaquete(ID); //se borra el paquete de la central origen
        arbolCentrales.buscarNodo(stoi(CPDestino))->elemento.addPaquete(paquete); //se inserta el paquete en la central destino
        cout<<"Paquete con ID " <<ID<<" insertado en "<< CPDestino<<endl;
    }
    else{
        cout<<"El paquete no se encuentra en la CP "<<CPOrigen<<"."<<endl;
    }
    cin.get();
}
void CAE::estadistica() {
    cout <<endl<<"                                  ESTADISTICA"<<endl<<endl;
    float p = (float)(N2 - listaPaquetes.len)*100/(float)N2;
    float porcentaje = round(p*100)/100;
    cout <<setfill(' ')<< setw(23) << "Localidad" << "\t\t"<<"CP" << "\t\t"<< "Paquetes" << "\t"<<"Paquetes(%)"<< endl;
    cout<<"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
    arbolCentrales.mostrarEstadistica(arbolCentrales.getRaiz(), N2);
    cout<<"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
    cout <<setfill(' ')<< setw(23) << "Total" << "\t\t"<< arbolCentrales.length <<"\t\t"<< N2 - listaPaquetes.len<<"/"<<N2 << "\t\t"<< porcentaje <<"%"<< endl;
    cin.get();
}
