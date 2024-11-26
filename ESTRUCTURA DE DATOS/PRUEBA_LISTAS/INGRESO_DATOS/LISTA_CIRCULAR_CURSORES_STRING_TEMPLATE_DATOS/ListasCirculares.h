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
#include <iostream>

using namespace std;

template<typename T>
class ListaCircular {
private:
    Nodo<T>* primero;
    Nodo<T>* ultimo;
public:
    ListaCircular();
    void Insertar(T);
    void Buscar(T);
    void Eliminar(T);
    void Mostrar();
};




