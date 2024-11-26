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
#include <iostream>
#include <string>

using namespace std;

class Nodo {
private:
    int dato;
    Nodo* siguiente;
public:
    Nodo(int);
    void setDato(int);
    int getDato();
    void setSiguiente(Nodo*);
    Nodo* getSiguiente();
};


