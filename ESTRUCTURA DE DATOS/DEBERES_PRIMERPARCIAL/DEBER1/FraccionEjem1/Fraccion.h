/***********************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                  *
 * Proposito:                      TDA                                 *
 * Autor:                          Kerlly Chiriboga                    *
 * Fecha de creacion:              06/11/2024                          *
 * Fecha de modificacion:          07/11/2024                          *
 * Materia:                        Estructura de datos                 *
 * NRC :                           1978                                *
 ***********************************************************************/

#ifndef FRACCION_H
#define FRACCION_H

class Fraccion {
private:
    int numerador;  
    int denominador;  

    void simplificar();
    int mcd(int a, int b) const;

public:
    Fraccion(int n, int d);

    int getNumerador() const; 
    void setNumerador(int n);     
    
    int getDenominador() const;    
    void setDenominador(int d);

    Fraccion sumar(const Fraccion& f) const;
    void mostrar() const;
};

#endif 
