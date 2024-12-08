/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Generador de Correos                                *
 * Autor:                          Kerlly Chiriboga                                    *
 * Fecha de creacion:              18/11/2024                                          *
 * Fecha de modificacion:          20/11/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 **************************************************************************************/

#pragma once
#include "Nodo.h"
#include <iostream>
using namespace std;

template <typename T>
class ListaSimple {
private:
    Nodo<T>* cabeza;

public:
    ListaSimple() : cabeza(nullptr) {}
    void Insertar_cabeza(T _dato);
    void Mostrar() const;
    ~ListaSimple(); 
};
