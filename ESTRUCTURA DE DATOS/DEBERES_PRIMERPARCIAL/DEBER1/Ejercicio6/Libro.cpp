/***********************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                  *
 * Proposito:                      TDA                                 *
 * Autor:                          Kerlly Chiriboga                    *
 * Fecha de creacion:              06/11/2024                          *
 * Fecha de modificacion:          07/11/2024                          *
 * Materia:                        Estructura de datos                 *
 * NRC :                           1978                                *
 ***********************************************************************/

#include "Libro.h"
#include <stdio.h>

Libro::Libro(const std::string& t, const std::string& a) : titulo(t), autor(a) {}

std::string Libro::getTitulo() const {
    return titulo;
}

void Libro::setTitulo(const std::string& t) {
    titulo = t;
}

std::string Libro::getAutor() const {
    return autor;
}

void Libro::setAutor(const std::string& a) {
    autor = a;
}

void Libro::mostrar() const {
    printf("Titulo: %s, Autor: %s\n", titulo.c_str(), autor.c_str());
}
