#include "CuentaBancaria.h"
#include <stdexcept>

CuentaBancaria::CuentaBancaria(double s) : saldo(s) {}

double CuentaBancaria::getSaldo() const {
    return saldo;
}

void CuentaBancaria::setSaldo(double s) {
    saldo = s;
}

void CuentaBancaria::depositar(double cantidad) {
    if (cantidad < 0) {
        throw std::invalid_argument("La cantidad a depositar no puede ser negativa");
    }
    saldo += cantidad;
}

void CuentaBancaria::retirar(double cantidad) {
    if (cantidad < 0) {
        throw std::invalid_argument("La cantidad a retirar no puede ser negativa");
    }
    if (cantidad > saldo) {
        throw std::invalid_argument("Fondos insuficientes");
    }
    saldo -= cantidad;
}
