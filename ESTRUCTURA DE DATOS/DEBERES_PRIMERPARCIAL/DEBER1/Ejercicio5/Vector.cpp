/***********************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                  *
 * Proposito:                      TDA                                 *
 * Autor:                          Kerlly Chiriboga                    *
 * Fecha de creacion:              06/11/2024                          *
 * Fecha de modificacion:          07/11/2024                          *
 * Materia:                        Estructura de datos                 *
 * NRC :                           1978                                *
 ***********************************************************************/

#include "Vector.h"
#include <stdio.h>

Vector::Vector(double x, double y) : x(x), y(y) {}

double Vector::getX() const {
    return x;
}

void Vector::setX(double x) {
    this->x = x;
}

double Vector::getY() const {
    return y;
}

void Vector::setY(double y) {
    this->y = y;
}

void Vector::mostrar() const {
    printf(" (%.2f, %.2f)\n", x, y);
}
