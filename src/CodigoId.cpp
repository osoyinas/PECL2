#include "CodigoId.hpp"
CodigoId::CodigoId(){}

/**
Devuelve un string con el formato 00X0000,
rellena con 0 hasta completar las 4 posiciones.
Ej: 21B0001, 54V0002, 73A0003...
*/
string getCodigoIdStr(CodigoId cId){
    string str = "";
    string secNStr = "";
    str+= cId.rdigitos;
    str+= cId.letra;

    for(int i = 0; i < 4 - int(to_string(cId.secN).size()) ; i++){
    secNStr+="0";
    }
    secNStr+=to_string(cId.secN);
    str+=secNStr;
    return str;
}
/**
Genera un codigo de identificacion de forma aleatoria e iterativa,
dandole como parametro n (iterativo).
Ej: 0 -> 00X0000, 1-> 00X0001, 10-> 00X0010, 213-> 00X0213.
*/
CodigoId generarCodigoId(int n){

    if(n>9999){
            n= n%9999;
    }
    CodigoId cId;
    for(int i = 0; i < int(strlen(cId.rdigitos)); i++ ){
        char digito = generarRandom(48,57);
        cId.rdigitos[i] = digito;
    }
    char letra = generarRandom(65,90);
    cId.letra = letra;
    cId.secN = n+1;
    return cId;
}
CodigoId crearCodigoId(string str){

    CodigoId cId;
    for(int i = 0; i < int(strlen(cId.rdigitos)); i++ ){
        char digito = generarRandom(48,57);
        cId.rdigitos[i] = str[i];
    }
    char letra = generarRandom(65,90);
    cId.letra = str[2];
    string substr = str.substr(3,6);
    cId.secN = stoi(substr);
    return cId;
}
