/***********************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                  *
 * Proposito:                      TDA                                 *
 * Autor:                          Kerlly Chiriboga                    *
 * Fecha de creacion:              06/11/2024                          *
 * Fecha de modificacion:          07/11/2024                          *
 * Materia:                        Estructura de datos                 *
 * NRC :                           1978                                *
 ***********************************************************************/

#ifndef RECTANGULO_H
#define RECTANGULO_H

class Rectangulo {
private:
    double ancho;
    double alto;

public:
    Rectangulo(double a, double al);

    double getAncho() const;
    double getAlto() const;

    void setAncho(double a);
    void setAlto(double al);

    double area() const;
    double perimetro() const;
};

#endif
