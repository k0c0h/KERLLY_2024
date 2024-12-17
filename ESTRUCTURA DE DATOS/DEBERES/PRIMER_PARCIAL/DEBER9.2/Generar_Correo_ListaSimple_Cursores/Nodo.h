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
#include <iostream>

using namespace std;

template <typename T>
class Nodo {
private:
    T dato;
    Nodo* siguiente;

public:
    Nodo(T _dato) : dato(_dato), siguiente(nullptr) {}
    T getDato() const { return dato; }
    void setDato(T _dato) { dato = _dato; }
    Nodo* getSiguiente() const { return siguiente; }
    void setSiguiente(Nodo* _siguiente) { siguiente = _siguiente; }

    template <typename U>
    friend class ListaSimple;
};

