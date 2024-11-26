#ifndef CIRCULO_H
#define CIRCULO_H

class Circulo {
private:
    double radio;

public:
    Circulo(double r);

    double getRadio() const;
    void setRadio(double r);

    double area() const;
    double perimetro() const;
};

#endif
