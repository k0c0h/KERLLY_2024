#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <string>

class Estudiante {
private:
    std::string nombre;
    double nota1, nota2, nota3;

public:
    Estudiante(const std::string& n, double n1, double n2, double n3);

    std::string getNombre() const;
    void setNombre(const std::string& n);
    
    double getNota1() const;
    void setNota1(double n1);
    
    double getNota2() const;
    void setNota2(double n2);

    double getNota3() const;
    void setNota3(double n3);

    double promedio() const;
    void mostrar() const;
};

#endif