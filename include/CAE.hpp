#ifndef CAE_HPP
#define CAE_HPP

#include "ArbolBinario.hpp"
#include "Lista.hpp"
#include "Central.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <cctype>

using namespace std;
class CAE
{
public:
    //Constructor
    CAE(int N1, int N2, int N3, int N4);
    //Metodos
    void insertarPaquetes();
    void mostrar();
    void insertarCP(string CP, string localidad);
    void borrarCP(string CP);
    void buscarPaquete(string id);
    void transferirPaquete(string id, string origenCP, string destinoCP);
    void resetPaquetesEnviados();
    int getPaquetesEnviados();
    bool tienePaquetes();
    void examinarCP(string CP);
    void extraer(string ID, string CP);
    void llevar(string, string);
    void llevar(string, string, string);
    void estadistica();

private:
    Lista listaPaquetes;
    ArbolBinario arbolCentrales;
    void insertarPaquete(Paquete);
    int paquetesEnviados = 0;
    int N1;
    int N2;
    int N3;
    int N4;
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
bool cp_valida(string CP);
#endif // CAE_HPP
