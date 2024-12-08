/***********************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                  *
 * Proposito:                      TDA                                 *
 * Autor:                          Kerlly Chiriboga                    *
 * Fecha de creacion:              06/11/2024                          *
 * Fecha de modificacion:          07/11/2024                          *
 * Materia:                        Estructura de datos                 *
 * NRC :                           1978                                *
 ***********************************************************************/

#ifndef PUNTO_H
#define PUNTO_H

class Punto {
private:
    double x;
    double y;

public:
    Punto(double xCoord, double yCoord);

    double getX() const;
    double getY() const;

    void setX(double xCoord);
    void setY(double yCoord);

    double distancia(const Punto& otro) const;
};

#endif
