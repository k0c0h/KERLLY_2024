/***********************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                  *
 * Proposito:                      TDA                                 *
 * Autor:                          Kerlly Chiriboga                    *
 * Fecha de creacion:              06/11/2024                          *
 * Fecha de modificacion:          07/11/2024                          *
 * Materia:                        Estructura de datos                 *
 * NRC :                           1978                                *
 ***********************************************************************/

#include "Fraccion.h"
#include <stdio.h>
#include <stdexcept> 

int Fraccion::mcd(int a, int b) const {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a < 0 ? -a : a;
}

Fraccion::Fraccion(int n, int d) : numerador(n), denominador(d) {
    if (d == 0) {
        throw std::invalid_argument("El denominador no puede ser cero");
    }
    simplificar();
}

void Fraccion::simplificar() {
    int gcd = mcd(numerador, denominador);
    numerador /= gcd;
    denominador /= gcd;

    if (denominador < 0) {
        numerador = -numerador;
        denominador = -denominador;
    }
}

int Fraccion::getNumerador() const {
    return numerador;
}

int Fraccion::getDenominador() const {
    return denominador;
}

void Fraccion::setNumerador(int n) {
    numerador = n;
    simplificar(); 
}

void Fraccion::setDenominador(int d) {
    if (d == 0) {
        throw std::invalid_argument("El denominador no puede ser cero");
    }
    denominador = d;
    simplificar();
}

Fraccion Fraccion::sumar(const Fraccion& f) const {
    int nuevoNumerador = numerador * f.denominador + f.numerador * denominador;
    int nuevoDenominador = denominador * f.denominador;
    Fraccion resultado(nuevoNumerador, nuevoDenominador);
    return resultado;
}

void Fraccion::mostrar() const {
    printf("%d/%d\n", numerador, denominador);
}



//g++ main.cpp Fraccion.cpp -o main.exe
//./main.exe