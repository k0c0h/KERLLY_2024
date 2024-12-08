/***********************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                  *
 * Proposito:                      TDA                                 *
 * Autor:                          Kerlly Chiriboga                    *
 * Fecha de creacion:              06/11/2024                          *
 * Fecha de modificacion:          07/11/2024                          *
 * Materia:                        Estructura de datos                 *
 * NRC :                           1978                                *
 ***********************************************************************/

#ifndef LIBRO_H
#define LIBRO_H

#include <string>

class Libro {
private:
    std::string titulo;
    std::string autor;

public:
    Libro(const std::string& t, const std::string& a);

    std::string getTitulo() const;
    std::string getAutor() const;

    void setTitulo(const std::string& t);
    void setAutor(const std::string& a);

    void mostrar() const;
};

#endif
