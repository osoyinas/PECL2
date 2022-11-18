#include "Semicoord.hpp"

Semicoord::Semicoord(){}
/**
Crea una semicoordenada a partir de 3 ints, (grados, minutos, segundos)
*/
Semicoord crearSemicoordenada(int grados, int minutos, int segundos){
    if( grados>360){
        throw invalid_argument("Los grados no pueden ser mayores que 360.");
    }
    if( minutos>59){
        throw invalid_argument("Los minutos no pueden ser mayores que 59.");
    }
    if(segundos > 59){
        throw invalid_argument("Los minutos no pueden ser mayores que 59.");
    }
    Semicoord semicoordenada;
    semicoordenada.grados = grados;
    semicoordenada.minutos = minutos;
    semicoordenada.segundos = segundos;
    return semicoordenada;
}

/**
Genera una semicoordenada aleatoria entre el Min y Max. (min,max)
*/
Semicoord generarSemicoord(Semicoord min, Semicoord max){

    Semicoord semicoord;
    semicoord.grados = generarRandom(min.grados,max.grados);

    if( min.grados == max.grados){
        semicoord.minutos = generarRandom(min.minutos, max.minutos);
    }

    else if( semicoord.grados == min.grados ){
        semicoord.minutos = generarRandom(min.minutos,59);
    }

    else if( semicoord.grados == max.grados ){
        semicoord.minutos = generarRandom(0,max.minutos);
    }

    else{
        semicoord.minutos = generarRandom(0,59);
    }

    if( min.minutos == max.minutos){
        semicoord.segundos = generarRandom(min.segundos, max.segundos);
    }

    else if( semicoord.minutos == min.minutos ){
        semicoord.segundos = generarRandom(min.segundos,59);
    }

    else if( semicoord.minutos == max.minutos ){
        semicoord.segundos = generarRandom(0,max.segundos);
    }

    else{
        semicoord.segundos = generarRandom(0,59);
    }

    return semicoord;
}

/**
Compara la semicoordenada y devuelve True si es menor.
*/
bool Semicoord::esMenor(Semicoord semicoord){

    bool gradosMenor, gradosIgual, minutosMenor, minutosIgual ,segundosMenor;

    gradosMenor = this->grados < semicoord.grados;
    gradosIgual = this->grados == semicoord.grados;
    minutosMenor = this->minutos < semicoord.minutos;
    minutosIgual = this->minutos == semicoord.minutos;
    segundosMenor = this->segundos < semicoord.segundos;

    return ((gradosMenor) || (gradosIgual && minutosMenor) || (gradosIgual && minutosIgual && segundosMenor));

}
/**
Devuelve la coordenada punto medio de a y b.
*/
Semicoord puntoMedio(Semicoord a, Semicoord b){
    Semicoord puntoMedio;
    int pGrados = 0, pMinutos = 0 , pSegundos = 0;

    pGrados = (a.grados + b.grados)/2;
    if((a.grados + b.grados)%2 == 1){

        pMinutos+= 30;
    }
    pMinutos += (a.minutos + b.minutos);
    pMinutos = pMinutos/2;
    if(((a.minutos + b.minutos)%2) == 1){

        pSegundos+= 30;
    }
    pSegundos += (a.segundos + b.segundos);
    pSegundos = pSegundos/2;

    if(((a.segundos + b.segundos )%2) == 1){
        pSegundos+=1;
    }
    puntoMedio.grados = pGrados;
    puntoMedio.minutos = pMinutos;
    puntoMedio.segundos = pSegundos;

    return puntoMedio;
}















