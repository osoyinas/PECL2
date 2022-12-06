#ifndef CAE_HPP
#define CAE_HPP

#include "ArbolBinario.hpp"
#include "Lista.hpp"
#include "Central.hpp"
#include <string>
#include <iostream>
#include <vector>

using namespace std;
class CAE
{
public:
    CAE();
    void setData(int,int,int);
    Lista listaPaquetes;
    ArbolBinario arbolCentrales;
    void insertarPaquete(Paquete);
    void insertarPaquetes();
    void mostrar();
    void insertarCP(string CP, string localidad);
    void borrarCP(string CP);
    void mostrarPaquetes(Central central);
    void buscarPaquete(string id);
    void eliminarPaquete(string id);
    void transferirPaquete(string id, string origenCP, string destinoCP);


private:
    int N1;
    int N2;
    int N3;
    const char *localidades[14] = {
                                   "Ajalvir",
                                   "Daganzo",
                                   "Alcalá",
                                   "Mejorada",
                                   "Nuevo Baztán",
                                   "Arganda",
                                   "Carabaña",
                                   "Chinchón",
                                   "Villarejo",
                                   "Camarma de Esteruelas",
                                   "Meco",
                                   "Cobeña",
                                   "Torres de la Alameda",
                                   "Los Santos de la Humosa"
                                   };
};

#endif // CAE_HPP
