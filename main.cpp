#include <iostream>
#include <iomanip>
#include "Random.hpp"
#include "Central.hpp"
#include "Lista.hpp"
#include "Nif.hpp"
#include "ArbolBinario.hpp"
#include "CAE.hpp"

#define sistema 0   //linux/mac = 1, windows = 0.
#define N1 14       //Centrales de paqueteria.
#define N2 100      //Paquetes generados aleatoriamente.
#define N3 12       //Paquetes a enviar en cada ejecucion.
#define N4 6*N3     //Cada cuantos paquetes mostrar el menu.

int menu();

using namespace std;

int main()
{
    //establecerSemilla();
    //Constantes
    int input;
    CAE cae(N1,N2,N3,N4);

    //int opcion = menu();
    while(cae.tienePaquetes()){
        cout<<"------------------------------------------------------------------------------------"<<endl;
        cae.mostrar();
        cout<<endl<<"Pulsa ENTER para avanzar."<<endl;
        cae.insertarPaquetes();
        input = cin.get();
        if(cae.getPaquetesEnviados()== N4){
            cae.resetPaquetesEnviados();

            switch (menu()){
                case 1: {
                    string CP;
                    string localidad;
                    cout<<"Inserte la CP: ";
                    cin>> CP;
                    cout<<"Inserte la localidad: ";
                    cin>>localidad;
                    cae.insertarCP(CP,localidad);
                    cout<<endl;
                } break;
                case 2: {
                    string CP;
                    cout<<"Inserte la CP que quiere eliminar: ";
                    cin>> CP;
                    cae.borrarCP(CP);
                } break;
                case 3: {
                    string CP;
                    cout<<"Inserte la CP que desea examinar: ";
                    cin>> CP;
                    cae.examinarCP(CP);
                    } break;
                case 4: {
                    cae.estadistica();
                } break;
                case 5: {
                    string id;
                    cout<<"Inserte el codigo ID del paquete: ";
                    cin>> id;
                    cae.buscarPaquete();
                } break;
                case 6: {
                    string CP;
                    string ID;
                    cout<<"Inserte la CP: ";
                    cin>> CP;
                    cout <<"Inserte el ID del paquete: ";
                    cin >> ID:
                    cae.extraer(ID,CP);
                } break;
                case 7: {
                    string CP;
                    string ID;
                    cout<<"Inserte la CP: ";
                    cin>> CP;
                    cout <<"Inserte el ID del paquete: ";
                    cin >> ID:
                    cae.llevar(ID,CP);
                } break;
                case 8: {
                    string CPOrigen;
                    string CPDestino;
                    cout<<"Inserte la CP origen: ";
                    cin>> CPOrigen;
                    cout <<"Inserte la CP destino: ";
                    cin >> CPDestino:
                    cae.llevar(CPOrigen,CPDestino);
                } break;
                case 9: {
                } break;
                case 0: {
                    return 0;
                } break;
            }
        }
    }
}

int menu(){
    cout<<"----------------------------------------MENU----------------------------------------"<<endl;
    cout<<"1. Insertar una CP de forma manual."<<endl;
    cout<<"2. Borrar una CP."<<endl;
    cout<<"3. Mostrar los datos de los paquetes que se distribuirán en una CP dada."<<endl;
    cout<<"4. Mostrar una estadística."<<endl;
    cout<<"5. Buscar un paquete concreto por su ID."<<endl;
    cout<<"6. Extraer algún paquete concreto de una CP dada."<<endl;
    cout<<"7. Llevar un paquete concreto del CAE a una CP concreta."<<endl;
    cout<<"8. Llevar un paquete concreto de una CP a otra."<<endl;
    cout<<"9. Continuar con la distribución de paquetes."<<endl;
    cout<<"0. Salir del programa."<<endl;
    cout<<"------------------------------------------------------------------------------------"<<endl;
    int opcion;
    cout<<"Seleccione una opcion: ";
    cin >> opcion;
    return opcion;
}

