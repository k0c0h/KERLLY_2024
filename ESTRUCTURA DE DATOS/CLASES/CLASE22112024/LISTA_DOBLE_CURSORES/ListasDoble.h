/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Listas Dobles                                       *
 * Autor:                          Kerlly Chiriboga                                    *
 * Fecha de creacion:              22/11/2024                                          *
 * Fecha de modificacion:          24/11/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 **************************************************************************************/
#pragma once
#include "Nodo.h"

using namespace std;

class ListaDoble {
private:
    Nodo* primero;
    Nodo* ultimo;
public:
    ListaDoble();
    void Insertar(int);
    void Buscar(int);
    void Eliminar(int);
    void Mostrar();
};


