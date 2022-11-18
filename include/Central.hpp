#ifndef CENTRAL_H
#define CENTRAL_H

#include "Coord.hpp"
#include "Muelle.hpp"
#include "Cola.hpp"
#include "Etiqueta.hpp"
#include <iostream>
class Central
{
    public:
        //Constructor
        Central(int N1,int N2, int N3, Coord minCoords, Coord maxCoords);
        //Metodos
        void clasificar();
        vector<Etiqueta> getColaArray();
        Cola getCola();
        bool estaVacia();
        //Atributos
        Muelle muelleNO;
        Muelle muelleNE;
        Muelle muelleSO;
        Muelle muelleSE;

    private:
        //Atributos
        int N1;
        int N2;
        int N3;
        Cola colaInicial;

};

#endif // CENTRAL_H
