/***********************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                  *
 * Proposito:                      TDA                                 *
 * Autor:                          Kerlly Chiriboga                    *
 * Fecha de creacion:              06/11/2024                          *
 * Fecha de modificacion:          07/11/2024                          *
 * Materia:                        Estructura de datos                 *
 * NRC :                           1978                                *
 ***********************************************************************/

#ifndef CIRCULO_H
#define CIRCULO_H

class Circulo {
private:
    double radio;

public:
    Circulo(double r);

    double getRadio() const;
    void setRadio(double r);

    double area() const;
    double perimetro() const;
};

#endif
