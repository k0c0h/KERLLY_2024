/***********************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                  *
 * Proposito:                      TDA                                 *
 * Autor:                          Kerlly Chiriboga                    *
 * Fecha de creacion:              06/11/2024                          *
 * Fecha de modificacion:          07/11/2024                          *
 * Materia:                        Estructura de datos                 *
 * NRC :                           1978                                *
 ***********************************************************************/

#include "Complejo.h"
#include <stdio.h>

Complejo::Complejo(double r, double i) : real(r), imaginario(i) {}

double Complejo::getReal() const {
    return real;
}

void Complejo::setReal(double r) {
    real = r;
}

double Complejo::getImaginario() const {
    return imaginario;
}

void Complejo::setImaginario(double i) {
    imaginario = i;
}

Complejo Complejo::sumar(const Complejo& c) const {
    return Complejo(real + c.real, imaginario + c.imaginario);
}

void Complejo::mostrar() const {
    printf("%.2f + %.2fi\n", real, imaginario);
}
