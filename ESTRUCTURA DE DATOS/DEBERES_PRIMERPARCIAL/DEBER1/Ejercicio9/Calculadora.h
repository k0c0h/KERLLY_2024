/***********************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                  *
 * Proposito:                      TDA                                 *
 * Autor:                          Kerlly Chiriboga                    *
 * Fecha de creacion:              06/11/2024                          *
 * Fecha de modificacion:          07/11/2024                          *
 * Materia:                        Estructura de datos                 *
 * NRC :                           1978                                *
 ***********************************************************************/

#ifndef CALCULADORA_H
#define CALCULADORA_H

class Calculadora {
private:
    double num1;
    double num2;

public:
    Calculadora(double n1, double n2);

    double getNum1() const;    
    void setNum1(double n1);

    double getNum2() const;
    void setNum2(double n2);

    double sumar() const;
    double restar() const;
    double multiplicar() const;
    double dividir() const;
};

#endif
//g++ main.cpp Vector.cpp -o main.exe