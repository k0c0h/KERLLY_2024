/***********************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                  *
 * Proposito:                      TDA                                 *
 * Autor:                          Kerlly Chiriboga                    *
 * Fecha de creacion:              06/11/2024                          *
 * Fecha de modificacion:          07/11/2024                          *
 * Materia:                        Estructura de datos                 *
 * NRC :                           1978                                *
 ***********************************************************************/

#ifndef CUENTA_BANCARIA_H
#define CUENTA_BANCARIA_H

class CuentaBancaria {
private:
    double saldo;

public:
    CuentaBancaria(double s);

    double getSaldo() const;
    void setSaldo(double s);

    void depositar(double cantidad);
    void retirar(double cantidad);
};

#endif
