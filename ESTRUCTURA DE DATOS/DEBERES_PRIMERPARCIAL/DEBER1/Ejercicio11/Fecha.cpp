/***********************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                  *
 * Proposito:                      TDA                                 *
 * Autor:                          Kerlly Chiriboga                    *
 * Fecha de creacion:              06/11/2024                          *
 * Fecha de modificacion:          07/11/2024                          *
 * Materia:                        Estructura de datos                 *
 * NRC :                           1978                                *
 ***********************************************************************/

#include "Fecha.h"
#include <stdexcept>
#include <stdio.h>

void Fecha::validarFecha(int d, int m, int a) {
    if (m < 1 || m > 12) {
        throw std::invalid_argument("Mes no valido");
    }
    if (d < 1 || d > 31) {
        throw std::invalid_argument("Dia no valido");
    }
    // Simplificación: no se considera el número de días por mes ni años bisiestos
}

Fecha::Fecha(int d, int m, int a) : dia(d), mes(m), anio(a) {
    validarFecha(dia, mes, anio);
}

int Fecha::getDia() const {
    return dia;
}

void Fecha::setDia(int d) {
    validarFecha(d, mes, anio);
    dia = d;
}

int Fecha::getMes() const {
    return mes;
}

void Fecha::setMes(int m) {
    validarFecha(dia, m, anio);
    mes = m;
}

int Fecha::getAnio() const {
    return anio;
}

void Fecha::setAnio(int a) {
    anio = a; // No se valida el año
}

void Fecha::mostrar() const {
    printf("%02d/%02d/%04d\n", dia, mes, anio);
}
