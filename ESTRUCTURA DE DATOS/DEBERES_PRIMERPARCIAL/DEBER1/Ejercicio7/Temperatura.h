/***********************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                  *
 * Proposito:                      TDA                                 *
 * Autor:                          Kerlly Chiriboga                    *
 * Fecha de creacion:              06/11/2024                          *
 * Fecha de modificacion:          07/11/2024                          *
 * Materia:                        Estructura de datos                 *
 * NRC :                           1978                                *
 ***********************************************************************/

#ifndef TEMPERATURA_H
#define TEMPERATURA_H

class Temperatura {
private:
    double celsius;

public:
    Temperatura(double c);

    double getCelsius() const;
    void setCelsius(double c);

    double aFahrenheit() const;
    double aCelsius() const;
};

#endif
