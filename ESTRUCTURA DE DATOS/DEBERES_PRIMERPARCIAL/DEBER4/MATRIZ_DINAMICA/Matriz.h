/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Matriz con Memoria Dinamica                         *
 * Autor:                          Kerlly Chiriboga                                    *
 * Fecha de creacion:              18/11/2024                                          *
 * Fecha de modificacion:          21/11/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 **************************************************************************************/

#pragma once
#include <iostream>
class Matriz {
    private:
        int **matriz;
        int dim;
    public:
        Matriz();
        Matriz(int**, int);
        int getDim();
        void setDim(int);
        int **getMatriz();
        void setMatriz(int **);
};

