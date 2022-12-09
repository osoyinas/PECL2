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



using namespace std;

int main()
{
    //establecerSemilla();
    //Constantes
    CAE cae(N1,N2,N3,N4);
    cout<<cae.arbolCentrales.length<<endl;
    cae.arbolCentrales.postOrden(cae.arbolCentrales.getRaiz());
    NodoBinario* nodo = cae.arbolCentrales.buscarNodo(42);
    cout<<endl<<nodo->elemento.ID<<endl;
    cout<<cae.arbolCentrales.length<<endl;
    return 0;
}
