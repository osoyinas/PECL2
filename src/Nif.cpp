#include "Nif.hpp"

Nif::Nif(){}
/**
Crea un NIF a partir de un str.
*/
Nif crearNif(char nifStr[]){
    if(strlen(nifStr)>9)
        throw invalid_argument("El nif no puede contener mas de 8 caracteres");
    Nif nif;
    for(int i = 0; i < int(strlen(nif.digitos)); i++ ){
        nif.digitos[i] = nifStr[i];
    }
    nif.letra = nifStr[strlen(nifStr)-1];
    return nif;
}
/**
Devuelve un string con los digitos y la letra concatenados.
*/
string getNifStr(Nif nif){
    string str = "";
    str+= nif.digitos;
    str+= nif.letra;
    return str;
}
/**
Genera un NIF completamente aleatorio,
Los numeros introducidos en la funcion generarRandom son el codigo ASCII
de los numeros de 1-10 y las letras en MAYUS.
*/
Nif generarNif(){
    Nif nif;
    for(int i = 0; i < int(strlen(nif.digitos)); i++ ){
        char digito = generarRandom(48,57);
        nif.digitos[i] = digito;
    }
    char letra = generarRandom(65,90);
    nif.letra = letra;
    return nif;
}
