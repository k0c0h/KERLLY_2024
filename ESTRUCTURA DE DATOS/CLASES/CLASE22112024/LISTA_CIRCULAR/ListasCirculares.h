/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Listas Circulares                                   *
 * Autor:                          Kerlly Chiriboga                                    *
 * Fecha de creacion:              22/11/2024                                          *
 * Fecha de modificacion:          25/11/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 **************************************************************************************/
#pragma once
#include "Nodo.h"

using namespace std;

class ListaCircular {
private:
    Nodo* primero;
    Nodo* ultimo;
public:
    ListaCircular();
    void Insertar(int);
    void Buscar(int);
    void Eliminar(int);
    void Mostrar();
};



