/***********************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                  *
 * Proposito:                      TDA                                 *
 * Autor:                          Kerlly Chiriboga                    *
 * Fecha de creacion:              06/11/2024                          *
 * Fecha de modificacion:          07/11/2024                          *
 * Materia:                        Estructura de datos                 *
 * NRC :                           1978                                *
 ***********************************************************************/

#include "Calculadora.h"
#include <stdexcept>

Calculadora::Calculadora(double n1, double n2) : num1(n1), num2(n2) {}

double Calculadora::getNum1() const {
    return num1;
}

void Calculadora::setNum1(double n1) {
    num1 = n1;
}

double Calculadora::getNum2() const {
    return num2;
}

void Calculadora::setNum2(double n2) {
    num2 = n2;
}

double Calculadora::sumar() const {
    return num1 + num2;
}

double Calculadora::restar() const {
    return num1 - num2;
}

double Calculadora::multiplicar() const {
    return num1 * num2;
}

double Calculadora::dividir() const {
    if (num2 == 0) {
        throw std::invalid_argument("Division por cero no permitida");
    }
    return num1 / num2;
}
