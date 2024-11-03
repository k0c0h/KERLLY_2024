#ifndef PUNTO_H
#define PUNTO_H

class Punto {
private:
    double x;
    double y;

public:
    Punto(double xCoord, double yCoord);

    double getX() const;
    double getY() const;

    void setX(double xCoord);
    void setY(double yCoord);

    double distancia(const Punto& otro) const;
};

#endif
