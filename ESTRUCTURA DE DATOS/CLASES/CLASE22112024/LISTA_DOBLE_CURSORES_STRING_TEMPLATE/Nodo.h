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
#include <iostream>
#include <string>

using namespace std;

template<typename T>
class Nodo {
private:
    T dato;
    Nodo<T>* siguiente;
    Nodo<T>* anterior;
public:
    Nodo(T);
    void setDato(T);
    void setSiguiente(Nodo<T>*);
    void setAnterior(Nodo<T>*);
    T getDato();
    Nodo<T>* getSiguiente();
    Nodo<T>* getAnterior();
};

