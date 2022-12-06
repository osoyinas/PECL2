#include <iostream>
#include <iomanip>
#include "Random.hpp"

#define sistema 0   //linux/mac = 1, windows = 0.
#define N1 8        //Centrales de paqueteria.
#define N2 100      //Paquetes generados aleatoriamente.
#define N3 12       //Paquetes a enviar en cada ejecucion.
#define N4 6*N3     //Cada cuantos paquetes mostrar el menu.
#include "Central.hpp"
#include "Lista.hpp"
#include "Nif.hpp"
#include "ArbolBinario.hpp"

using namespace std;

int main()
{
    establecerSemilla();
    //Constantes
    Semicoord s = crearSemicoordenada(30,30,30);
    Paquete p1 = generarPaquete(1,s,s,s,s);
    Paquete p2 = generarPaquete(4,s,s,s,s);

    Central central = crearCentral("Albacete");
    Central central2 = crearCentral("Cuenca");
    ArbolBinario arb;
    NodoBinario* raiz = arb.crearNodo(central);
    arb.setRaiz(raiz);
    arb.insertarNodo(arb.getRaiz(), central2);
    arb.postOrden(arb.getRaiz());
    return 0;
}

