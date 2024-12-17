#include "Calculadora.h"

// Convertir una expresión infija a notación postfija (Polaca Inversa)
template<typename T>
T Calculadora<T>::infijaAPostfija(const T& expresion) {
    stack<char> operadores;
    T resultado;

    for (char c : expresion) {
        if (isdigit(c) || isalpha(c)) {  // Operando
            resultado += c;
        } else if (c == '(') {          // Paréntesis izquierdo
            operadores.push(c);
        } else if (c == ')') {          // Paréntesis derecho
            while (!operadores.empty() && operadores.top() != '(') {
                resultado += operadores.top();
                operadores.pop();
            }
            operadores.pop();  // Eliminar '('
        } else if (esOperador(c)) {     // Operador
            while (!operadores.empty() && prioridad(operadores.top()) >= prioridad(c)) {
                resultado += operadores.top();
                operadores.pop();
            }
            operadores.push(c);
        }
    }

    // Vaciar la pila
    while (!operadores.empty()) {
        resultado += operadores.top();
        operadores.pop();
    }

    return resultado;
}

// Convertir una expresión infija a notación prefija (Polaca)
template<typename T>
T Calculadora<T>::infijaAPrefija(const T& expresion) {
    T expresionInvertida = invertir(expresion);
    T postfijaInvertida = infijaAPostfija(expresionInvertida);
    return invertir(postfijaInvertida);
}

// Verificar si un carácter es un operador
template<typename T>
bool Calculadora<T>::esOperador(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Obtener la prioridad del operador
template<typename T>
int Calculadora<T>::prioridad(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Invertir una expresión y manejar paréntesis
template<typename T>
T Calculadora<T>::invertir(const T& expresion) {
    T invertida;
    for (auto it = expresion.rbegin(); it != expresion.rend(); ++it) {
        if (*it == '(') {
            invertida += ')';
        } else if (*it == ')') {
            invertida += '(';
        } else {
            invertida += *it;
        }
    }
    return invertida;
}

// Necesario para compilación de plantillas
template class Calculadora<string>;
