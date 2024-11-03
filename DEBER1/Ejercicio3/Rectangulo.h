#ifndef RECTANGULO_H
#define RECTANGULO_H

class Rectangulo {
private:
    double ancho;
    double alto;

public:
    Rectangulo(double a, double al);

    double getAncho() const;
    double getAlto() const;

    void setAncho(double a);
    void setAlto(double al);

    double area() const;
    double perimetro() const;
};

#endif
