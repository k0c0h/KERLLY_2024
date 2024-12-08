/***********************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                  *
 * Proposito:                      TDA                                 *
 * Autor:                          Kerlly Chiriboga                    *
 * Fecha de creacion:              06/11/2024                          *
 * Fecha de modificacion:          07/11/2024                          *
 * Materia:                        Estructura de datos                 *
 * NRC :                           1978                                *
 ***********************************************************************/

#ifndef COMPLEJO_H
#define COMPLEJO_H

class Complejo {
private:
    double real;
    double imaginario;

public:
    Complejo(double r, double i);

    double getReal() const;
    void setReal(double r);

    double getImaginario() const;
    void setImaginario(double i);

    Complejo sumar(const Complejo& c) const;
    void mostrar() const;
};

#endif 
