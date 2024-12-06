#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <cctype>
#include <cmath>

using namespace std;

// Función para realizar operaciones
double applyOperation(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return pow(a, b); // Exponentiation
        default: return 0;
    }
}

// Función para evaluar una expresión RPN
double evaluateRPN(const string& expression) {
    stack<double> stack;
    stringstream ss(expression);
    string token;

    while (ss >> token) {
        if (isdigit(token[0])) {  // Si el token es un número
            stack.push(stod(token));
        } else {  // Si el token es un operador
            double b = stack.top(); stack.pop();
            double a = stack.top(); stack.pop();
            double result = applyOperation(a, b, token[0]);
            stack.push(result);
        }
    }

    return stack.top();  // El resultado final estará en la cima de la pila
}

int main() {
    string expression;
    cout << "Ingrese una expresión RPN (por ejemplo, 3 4 5 * +): ";
    getline(cin, expression);

    double result = evaluateRPN(expression);

    cout << "Resultado: " << result << endl;

    return 0;
}
