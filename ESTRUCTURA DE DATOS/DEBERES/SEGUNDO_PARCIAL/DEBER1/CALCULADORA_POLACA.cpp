#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

// Clase template para la calculadora
template<typename T>
class Calculadora {
public:
    // Función para convertir infija a polaca inversa (postfija)
    T infijaAPostfija(const T& expresion) {
        stack<char> operadores;
        T resultado;
        
        for (char c : expresion) {
            if (isdigit(c) || isalpha(c)) {  // Operando
                resultado += c;
            } else if (c == '(') {  // Paréntesis izquierdo
                operadores.push(c);
            } else if (c == ')') {  // Paréntesis derecho
                while (!operadores.empty() && operadores.top() != '(') {
                    resultado += operadores.top();
                    operadores.pop();
                }
                operadores.pop();  // Eliminar '('
            } else if (esOperador(c)) {  // Operador
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

    // Función para convertir infija a polaca (prefija)
    T infijaAPrefija(const T& expresion) {
        T expresionInvertida = invertir(expresion);
        T postfijaInvertida = infijaAPostfija(expresionInvertida);
        return invertir(postfijaInvertida);
    }

private:
    // Verificar si un carácter es un operador
    bool esOperador(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/';
    }

    // Obtener la prioridad del operador
    int prioridad(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }

    // Invertir una expresión y manejar paréntesis
    T invertir(const T& expresion) {
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
};

int main() {
    Calculadora<string> calculadora;

    string expresionInfija;

    cout << "Introduce la expresion infija: ";
    getline(cin, expresionInfija); // Espera a que el usuario presione Enter

    string postfija = calculadora.infijaAPostfija(expresionInfija);
    string prefija = calculadora.infijaAPrefija(expresionInfija);

    cout << "Notacion Polaca Inversa (Postfija): " << postfija << endl;
    cout << "Notacion Polaca (Prefija): " << prefija << endl;

    cout << "\nPresiona Enter para salir...";
    cin.ignore();  // Espera otro Enter antes de salir
    return 0;
}
//g++ CALCULADORA_POLACA.cpp -o main.exe
