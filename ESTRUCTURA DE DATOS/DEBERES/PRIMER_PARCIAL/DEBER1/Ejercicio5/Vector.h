#ifndef VECTOR_H
#define VECTOR_H

class Vector {
private:
    double x; 
    double y; 

public:
    Vector(double x = 0, double y = 0);

    double getX() const;
    double getY() const;

    void setX(double x);
    void setY(double y);

    void mostrar() const;
};

#endif
