#include <iostream>
#include <iomanip>
#include "Random.hpp"

#define sistema 0   //linux/mac = 1, windows = 0.
#define N1 8      //Paquetes totales.
#define N2 100       //De cuanto en cuanto se van a clasificar.
#define N3 12        //Capacidad de las furgonetas.
#define N4 6*N3        //Capacidad de las furgonetas.
using namespace std;

int main()
{
    //Constantes
    establecerSemilla();
    return 0;
}

