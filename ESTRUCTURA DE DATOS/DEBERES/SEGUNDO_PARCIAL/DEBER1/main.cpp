#include <iostream>
#include "Calculadora.h"

using namespace std;

int main() {
    Calculadora<string> calculadora;

    string expresionInfija;
    cout << "Introduce la expresion infija: ";
    getline(cin, expresionInfija);

    string postfija = calculadora.infijaAPostfija(expresionInfija);
    string prefija = calculadora.infijaAPrefija(expresionInfija);

    cout << "Notacion Polaca Inversa (Postfija): " << postfija << endl;
    cout << "Notacion Polaca (Prefija): " << prefija << endl;

    cout << "\nPresiona Enter para salir...";
    cin.ignore();
    return 0;
}
//g++ Calculadora.cpp main.cpp -o main.exe