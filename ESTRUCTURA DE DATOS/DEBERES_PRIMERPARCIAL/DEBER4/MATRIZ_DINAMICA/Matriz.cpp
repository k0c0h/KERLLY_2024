/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Matriz con Memoria Dinamica                         *
 * Autor:                          Kerlly Chiriboga                                    *
 * Fecha de creacion:              18/11/2024                                          *
 * Fecha de modificacion:          21/11/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 **************************************************************************************/

#include <iostream>
#include "Matriz.h"

Matriz::Matriz() {
}

Matriz::Matriz(int **matriz, int dim) {
    this->matriz = matriz;
    this->dim = dim;
}

int Matriz::getDim() {
    return dim;
}

void Matriz::setDim(int dim) {
    this->dim = dim;
}

int** Matriz::getMatriz() {
    return matriz;
}

void Matriz::setMatriz(int **matriz) {
    this->matriz = matriz;
}

