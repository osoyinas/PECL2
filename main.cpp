#include <iostream>
#include <iomanip>
#include "Central.hpp"

#define sistema 0   //linux/mac = 1, windows = 0.
#define N1 100      //Paquetes totales.
#define N2 10       //De cuanto en cuanto se van a clasificar.
#define N3 5        //Capacidad de las furgonetas.

using namespace std;

int main()
{
    //Constantes
    establecerSemilla();

    //Coordenadas de Alcala de Henares.
    Semicoord latitudMin = crearSemicoordenada(40,46,5);
    Semicoord latitudMax = crearSemicoordenada(40,51,6);
    Semicoord longitudMin = crearSemicoordenada(-3,32,2);
    Semicoord longitudMax = crearSemicoordenada(-3,41,1);
    Coord minCoords = crearCoordenada(latitudMin, longitudMin);
    Coord maxCoords = crearCoordenada(latitudMax, longitudMax);

    //Variables
    int input;          //Detectar si ha pulsado ENTER
    int contador = 0;

    Central central(N1, N2, N3, minCoords, maxCoords);

    //Ejecucion
    while(contador <= 3){

        cout<<endl<<"Pulsa ENTER para avanzar."<<endl;
        input = cin.get();
        if(sistema == 0)
            system("cls");      //limpiar consola en windows.
        else
            system("clear");   //limpiar consola en linux/mac.

        switch(contador){
            case 0:
                cout<<endl<<"Cola de la Central de Paqueteria:"<<endl<<endl;
                cout <<setw(7)<<"ID"<<setw(15)<<"NIF"<<setw(25)<<"Coordenadas" << endl;
                for(int i = 0; i<int(central.getColaArray().size()); i++){
                    Etiqueta etiqueta = central.getColaArray()[i];
                    cout << setw(7)<<getCodigoIdStr(etiqueta.id)<<setw(15)<<getNifStr(etiqueta.nif)<<setw(25)<<getCoordenadaStr(etiqueta.coords) <<endl;
                }
                contador++;
                break;

            case 1:
                central.clasificar();
                cout<<endl<<"Estado de los muelles:"<<endl;
                //MUELLE NO
                cout <<endl<<"-------------------MUELLE NO-------------------"<<endl;

                for(int i = 0; i < int(central.muelleNO.furgonetas.size()); i++){
                    Pila furgoneta = central.muelleNO.furgonetas[i];
                    cout<<endl<<"Furgoneta "<< i + 1<<":";
                    if(int(furgoneta.getArray().size()) == N3)
                        cout<<" En reparto";

                    cout<<endl;
                    cout <<setw(7)<<"ID"<<setw(15)<<"NIF"<<setw(25)<<"Coordenadas" << endl;
                    for(int j = 0; j < int(furgoneta.getArray().size()); j++){

                        Etiqueta etiqueta = furgoneta.getArray()[j];
                        cout << setw(7)<<getCodigoIdStr(etiqueta.id)<<setw(15)<<getNifStr(etiqueta.nif)<<setw(25)<<getCoordenadaStr(etiqueta.coords) <<endl;
                    }
                }

                //MUELLE NE
                cout <<endl<<"-------------------MUELLE NE-------------------"<<endl;

                for(int i = 0; i < int(central.muelleNE.furgonetas.size()); i++){
                    Pila furgoneta = central.muelleNE.furgonetas[i];
                    cout<<endl<<"Furgoneta "<< i + 1<<":";
                    if(int(furgoneta.getArray().size()) == N3)
                        cout<<" En reparto";

                    cout<<endl;
                    cout <<setw(7)<<"ID"<<setw(15)<<"NIF"<<setw(25)<<"Coordenadas" << endl;
                    for(int j = 0; j < int(furgoneta.getArray().size()); j++){

                        Etiqueta etiqueta = furgoneta.getArray()[j];
                        cout << setw(7)<<getCodigoIdStr(etiqueta.id)<<setw(15)<<getNifStr(etiqueta.nif)<<setw(25)<<getCoordenadaStr(etiqueta.coords) <<endl;
                    }
                }
                //MUELLE SO
                cout <<endl<<"-------------------MUELLE SO-------------------"<<endl;

                for(int i = 0; i < int(central.muelleSO.furgonetas.size()); i++){
                    Pila furgoneta = central.muelleSO.furgonetas[i];
                    cout<<endl<<"Furgoneta "<< i + 1<<":";
                    if(int(furgoneta.getArray().size()) == N3)
                        cout<<" En reparto";

                    cout<<endl;
                    cout <<setw(7)<<"ID"<<setw(15)<<"NIF"<<setw(25)<<"Coordenadas" << endl;
                    for(int j = 0; j < int(furgoneta.getArray().size()); j++){

                        Etiqueta etiqueta = furgoneta.getArray()[j];
                        cout << setw(7)<<getCodigoIdStr(etiqueta.id)<<setw(15)<<getNifStr(etiqueta.nif)<<setw(25)<<getCoordenadaStr(etiqueta.coords) <<endl;
                    }
                }
                //MUELLE SE
                cout <<endl<<"-------------------MUELLE SE-------------------"<<endl;

                for(int i = 0; i < int(central.muelleSE.furgonetas.size()); i++){
                    Pila furgoneta = central.muelleSE.furgonetas[i];
                    cout<<endl<<"Furgoneta "<< i + 1<<":";
                    if(int(furgoneta.getArray().size()) == N3)
                        cout<<" En reparto";

                    cout<<endl;
                    cout <<setw(7)<<"ID"<<setw(15)<<"NIF"<<setw(25)<<"Coordenadas" << endl;
                    for(int j = 0; j < int(furgoneta.getArray().size()); j++){

                        Etiqueta etiqueta = furgoneta.getArray()[j];
                        cout << setw(7)<<getCodigoIdStr(etiqueta.id)<<setw(15)<<getNifStr(etiqueta.nif)<<setw(25)<<getCoordenadaStr(etiqueta.coords) <<endl;
                    }
                }
                if(central.getCola().vacia()){
                    contador++;
                    break;
                }
                contador--;
                break;

            case 2:

                cout<<"Destino de los paquetes:"<<endl;
                //Muelle NO
                cout <<endl<<"-------------------Zona NO-------------------"<<endl<<endl;
                cout <<setw(7)<<"ID"<<setw(15)<<"NIF"<<setw(25)<<"Coordenadas" << endl;

                for(int i = 0; i < int(central.muelleNO.cola.getArray().size()); i++){

                    Etiqueta etiqueta = central.muelleNO.cola.getArray()[i];
                    cout << setw(7)<<getCodigoIdStr(etiqueta.id)<<setw(15)<<getNifStr(etiqueta.nif)<<setw(25)<<getCoordenadaStr(etiqueta.coords) <<endl;

                }
                //Muelle NE
                cout <<endl<<"-------------------Zona NE-------------------"<<endl<<endl;
                cout <<setw(7)<<"ID"<<setw(15)<<"NIF"<<setw(25)<<"Coordenadas" << endl;

                for(int i = 0; i < int(central.muelleNE.cola.getArray().size()); i++){

                    Etiqueta etiqueta = central.muelleNE.cola.getArray()[i];
                    cout << setw(7)<<getCodigoIdStr(etiqueta.id)<<setw(15)<<getNifStr(etiqueta.nif)<<setw(25)<<getCoordenadaStr(etiqueta.coords) <<endl;

                }

                //Muelle SO
                cout <<endl<<"-------------------Zona SO-------------------"<<endl<<endl;
                cout <<setw(7)<<"ID"<<setw(15)<<"NIF"<<setw(25)<<"Coordenadas" << endl;

                for(int i = 0; i < int(central.muelleSO.cola.getArray().size()); i++){

                    Etiqueta etiqueta = central.muelleSO.cola.getArray()[i];
                    cout << setw(7)<<getCodigoIdStr(etiqueta.id)<<setw(15)<<getNifStr(etiqueta.nif)<<setw(25)<<getCoordenadaStr(etiqueta.coords) <<endl;

                }
                //Muelle SE
                cout <<endl<<"-------------------Zona SE-------------------"<<endl<<endl;
                cout <<setw(7)<<"ID"<<setw(15)<<"NIF"<<setw(25)<<"Coordenadas" << endl;

                for(int i = 0; i < int(central.muelleSE.cola.getArray().size()); i++){

                    Etiqueta etiqueta = central.muelleSE.cola.getArray()[i];
                    cout << setw(7)<<getCodigoIdStr(etiqueta.id)<<setw(15)<<getNifStr(etiqueta.nif)<<setw(25)<<getCoordenadaStr(etiqueta.coords) <<endl;

                }

                contador++;
                break;
            case 3:
                cout<<endl<<"Informe estadistico:"<<endl<<endl;
                cout<<setw(30)<<"Numero de paquetes repartidos: "<<endl;
                cout<<setw(15)<<"Zona NO: "<< central.muelleNO.cola.getArray().size() <<endl;
                cout<<setw(15)<<"Zona NE: "<< central.muelleNE.cola.getArray().size() <<endl;
                cout<<setw(15)<<"Zona SO: "<< central.muelleSO.cola.getArray().size() <<endl;
                cout<<setw(15)<<"Zona SE: "<< central.muelleSE.cola.getArray().size() <<endl;
                cout<<setw(15)<<"Total: "<< central.muelleNO.cola.getArray().size() + central.muelleNE.cola.getArray().size()
                 + central.muelleSO.cola.getArray().size() + central.muelleSE.cola.getArray().size()<<endl<<endl;
                cout<<setw(30)<<"Furgonetas usadas en cada zona: " <<endl;
                cout<<setw(15)<<"Zona NO: "<< central.muelleNO.furgonetas.size() <<endl;
                cout<<setw(15)<<"Zona NE: "<< central.muelleNE.furgonetas.size() <<endl;
                cout<<setw(15)<<"Zona SO: "<< central.muelleSO.furgonetas.size() <<endl;
                cout<<setw(15)<<"Zona SE: "<< central.muelleSE.furgonetas.size() <<endl;
                 cout<<setw(15)<<"Total: "<<central.muelleNO.furgonetas.size() + central.muelleNE.furgonetas.size() + central.muelleSO.furgonetas.size() + central.muelleSE.furgonetas.size()<<endl;

                contador++;
                break;
        }
    }
    return 0;
}

