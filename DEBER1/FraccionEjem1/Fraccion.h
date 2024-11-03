#ifndef FRACCION_H
#define FRACCION_H

class Fraccion {
private:
    int numerador;  
    int denominador;  

    void simplificar();
    int mcd(int a, int b) const;

public:
    Fraccion(int n, int d);

    int getNumerador() const; 
    void setNumerador(int n);     
    
    int getDenominador() const;    
    void setDenominador(int d);

    Fraccion sumar(const Fraccion& f) const;
    void mostrar() const;
};

#endif 
