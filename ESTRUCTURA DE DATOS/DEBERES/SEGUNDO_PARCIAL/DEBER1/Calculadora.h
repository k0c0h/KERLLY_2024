#ifndef CALCULADORA_H
#define CALCULADORA_H

#include <stack>
#include <string>
using namespace std;

template<typename T>
class Calculadora {
public:
    T infijaAPostfija(const T& expresion);  
    T infijaAPrefija(const T& expresion);  

private:
    bool esOperador(char c);   
    int prioridad(char op);              
    T invertir(const T& expresion);       
};

#endif // CALCULADORA_H
