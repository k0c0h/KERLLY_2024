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
