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
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "Operaciones.h"

Operaciones::Operaciones() {}

Operaciones::Operaciones(Matriz m) {
    this->_matriz = m;
}

Operaciones::~Operaciones() {
    int dim = _matriz.getDim();
    for (int i = 0; i < dim; i++) {
        free(_matriz.getMatriz()[i]);
    }
    free(_matriz.getMatriz());
}

void Operaciones::segmentar() {
    int **matriz = (int**)malloc(_matriz.getDim() * sizeof(int*));
    for (int j = 0; j < _matriz.getDim(); j++) {
        matriz[j] = (int*)malloc(_matriz.getDim() * sizeof(int));
    }
    _matriz.setMatriz(matriz);
}

void Operaciones::encerar() {
    for (int i = 0; i < _matriz.getDim(); i++) {
        for (int j = 0; j < _matriz.getDim(); j++) {
            _matriz.getMatriz()[i][j] = 0;
        }
    }
}

void Operaciones::generar() {
    srand(time(NULL));
    for (int i = 0; i < _matriz.getDim(); i++) {
        for (int j = 0; j < _matriz.getDim(); j++) {
            _matriz.getMatriz()[i][j] = rand() % 3;
        }
    }
}

void Operaciones::procesarPot(int exp) {
    int dim = _matriz.getDim();
    int **base = (int**)malloc(dim * sizeof(int*));

    for (int i = 0; i < dim; i++) {
        base[i] = (int*)malloc(dim * sizeof(int));
        for (int j = 0; j < dim; j++) {
            base[i][j] = _matriz.getMatriz()[i][j];
        }
    }

    int **result = (int**)malloc(dim * sizeof(int*));

    for (int i = 0; i < dim; i++) {
        result[i] = (int*)malloc(dim * sizeof(int));
        for (int j = 0; j < dim; j++) {
            result[i][j] = (i == j) ? 1 : 0; 
        }
    }

    for (int e = 0; e < exp; e++) {
        int **temp = (int**)malloc(dim * sizeof(int*));

        for (int i = 0; i < dim; i++) {
            temp[i] = (int*)malloc(dim * sizeof(int));
            for (int j = 0; j < dim; j++) {
                temp[i][j] = 0;
                for (int k = 0; k < dim; k++) {
                    temp[i][j] += result[i][k] * base[k][j]; 
                }
            }
        }
        for (int i = 0; i < dim; i++) {
            for (int j = 0; j < dim; j++) {
                result[i][j] = temp[i][j];
            }
        }

        for (int i = 0; i < dim; i++) {
            free(temp[i]);
        }
        free(temp);
    }

    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            _matriz.getMatriz()[i][j] = result[i][j];
        }
    }

    for (int i = 0; i < dim; i++) {
        free(base[i]);
        free(result[i]);
    }
    free(base);
    free(result);
}

void Operaciones::procesarMulti() {
    int dim = _matriz.getDim();
    int **result = (int**)malloc(dim * sizeof(int*));
    for (int i = 0; i < dim; i++) {
        result[i] = (int*)malloc(dim * sizeof(int));
        for (int j = 0; j < dim; j++) {
            result[i][j] = 0;
            for (int k = 0; k < dim; k++) {
                result[i][j] += _matriz.getMatriz()[i][k] * _matriz.getMatriz()[k][j];
            }
        }
    }

    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            _matriz.getMatriz()[i][j] = result[i][j];
        }
        free(result[i]);
    }
    free(result);
}

void Operaciones::imprimir() {
    for (int i = 0; i < _matriz.getDim(); i++) {
        for (int j = 0; j < _matriz.getDim(); j++) {
            std::cout << _matriz.getMatriz()[i][j] << " ";
        }
        std::cout << "\n";
    }
}

