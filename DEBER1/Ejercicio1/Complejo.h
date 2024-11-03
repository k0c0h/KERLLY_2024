#ifndef COMPLEJO_H
#define COMPLEJO_H

class Complejo {
private:
    double real;
    double imaginario;

public:
    Complejo(double r, double i);

    double getReal() const;
    void setReal(double r);

    double getImaginario() const;
    void setImaginario(double i);

    Complejo sumar(const Complejo& c) const;
    void mostrar() const;
};

#endif 
