/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Programa sobre lista simple                         *
 * Autor:                          Kerlly Chiriboga                                    *
 * Fecha de creacion:              18/11/2024                                          *
 * Fecha de modificacion:          20/11/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 **************************************************************************************/

#pragma once
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

template<typename T>
class Nodo {
private:
    T dato;
    Nodo* siguiente;
public:
    Nodo(T);
    void setDato(T);
    T getDato();
    void setSiguiente(Nodo*);
    Nodo* getSiguiente();
    friend class ListaSimples;
};

