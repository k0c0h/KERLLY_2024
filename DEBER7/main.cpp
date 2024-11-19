#include <iostream>

// Prototipos de las funciones de la DLL
extern "C" {
    int ingresarEntero(const char* mensaje);
    float ingresarFlotante(const char* mensaje);
    char ingresarLetra(const char* mensaje);
    std::string ingresarString(const char* mensaje);
    double ingresarDouble(const char* mensaje);
}

int main() {
    int entero = ingresarEntero("Introduce un número entero: ");
    std::cout << "Número entero: " << entero << std::endl;

    return 0;
}
