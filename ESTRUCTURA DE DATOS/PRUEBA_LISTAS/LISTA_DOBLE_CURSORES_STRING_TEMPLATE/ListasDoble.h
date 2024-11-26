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

template<typename T>
class ListaDoble {
private:
    Nodo<T>* primero;
    Nodo<T>* ultimo;
public:
    ListaDoble();
    void Insertar(T);
    void Buscar(T);
    void Eliminar(T);
    void Mostrar();
};


