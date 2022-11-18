#include "Random.hpp"


/**
Establece una semilla a partir de la hora en el momento de ejecucion.
 Asi la generacion aleatoria de numeros es distinta
en todas las ejecuciones del programa porque parten de una semilla diferente.
*/
void establecerSemilla(){
    srand(time(NULL));
}
/**
Genera un numero aleatorio entre el minimo y el maximo incluidos.
*/
int generarRandom(int min, int max){
    return (rand()%((max+1)-min)) + min;
}

