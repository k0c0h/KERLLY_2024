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

class Nodo {
private:
    int dato;
    Nodo* siguiente;
    Nodo* anterior;
public:
    Nodo(int);
    void setDato(int);
    void setSiguiente(Nodo*);
    void setAnterior(Nodo*);
    int getDato();
    Nodo* getSiguiente();
    Nodo* getAnterior();
};

