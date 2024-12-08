/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Matriz con Memoria Dinamica                         *
 * Autor:                          Kerlly Chiriboga                                    *
 * Fecha de creacion:              18/11/2024                                          *
 * Fecha de modificacion:          21/11/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 **************************************************************************************/

#ifndef OPERACIONES_H
#define OPERACIONES_H

#include "Matriz.h"

class Operaciones {
private:
    Matriz _matriz;

public:
    Operaciones(); 
    Operaciones(Matriz m);
    ~Operaciones(); 

    void segmentar();
    void encerar();
    void generar();
    void procesarPot(int exp);
    void procesarMulti();
    void imprimir();
};

#endif 

