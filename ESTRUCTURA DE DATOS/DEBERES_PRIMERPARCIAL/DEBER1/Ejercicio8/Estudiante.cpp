/***********************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                  *
 * Proposito:                      TDA                                 *
 * Autor:                          Kerlly Chiriboga                    *
 * Fecha de creacion:              06/11/2024                          *
 * Fecha de modificacion:          07/11/2024                          *
 * Materia:                        Estructura de datos                 *
 * NRC :                           1978                                *
 ***********************************************************************/

#include "Estudiante.h"
#include <stdio.h>

Estudiante::Estudiante(const std::string& n, double n1, double n2, double n3)
     : nombre(n), nota1(n1), nota2(n2), nota3(n3) {}

std::string Estudiante::getNombre() const {
    return nombre;
}

void Estudiante::setNombre(const std::string& n) {
    nombre = n;
}

double Estudiante::getNota1() const {
    return nota1;
}

void Estudiante::setNota1(double n1) {
    nota1 = n1;
}

double Estudiante::getNota2() const {
    return nota2;
}

void Estudiante::setNota2(double n2) {
    nota2 = n2;
}

double Estudiante::getNota3() const {
    return nota3;
}

void Estudiante::setNota3(double n3) {
    nota3 = n3;
}

double Estudiante::promedio() const {
    return (nota1 + nota2 + nota3) / 3.0;
}

void Estudiante::mostrar() const {
    printf("Nombre: %s, Promedio: %.2lf\n", nombre.c_str(), promedio());
}
