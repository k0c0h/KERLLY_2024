/***********************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                  *
 * Proposito:                      TDA                                 *
 * Autor:                          Kerlly Chiriboga                    *
 * Fecha de creacion:              06/11/2024                          *
 * Fecha de modificacion:          07/11/2024                          *
 * Materia:                        Estructura de datos                 *
 * NRC :                           1978                                *
 ***********************************************************************/

#ifndef VECTOR_H
#define VECTOR_H

class Vector {
private:
    double x; 
    double y; 

public:
    Vector(double x = 0, double y = 0);

    double getX() const;
    double getY() const;

    void setX(double x);
    void setY(double y);

    void mostrar() const;
};

#endif
