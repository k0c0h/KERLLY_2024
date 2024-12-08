/***********************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                  *
 * Proposito:                      TDA                                 *
 * Autor:                          Kerlly Chiriboga                    *
 * Fecha de creacion:              06/11/2024                          *
 * Fecha de modificacion:          07/11/2024                          *
 * Materia:                        Estructura de datos                 *
 * NRC :                           1978                                *
 ***********************************************************************/

#ifndef FECHA_H
#define FECHA_H

class Fecha {
private:
    int dia;
    int mes;
    int anio;

    void validarFecha(int d, int m, int a);

public:
    Fecha(int d, int m, int a);

    int getDia() const;
    void setDia(int d);

    int getMes() const;
    void setMes(int m);

    int getAnio() const;
    void setAnio(int a);

    void mostrar() const;
};

#endif 
