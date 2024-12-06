#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Función simple para encriptar una letra con el método de César
char cesarEncrypt(char ch, int shift) {
    return (ch - 'a' + shift) % 26 + 'a';
}

int main() {
    std::vector<std::string> palabras = {"ana", "carlos", "beatriz", "daniel", "cecilia"};
    
    std::cout << "Ingresa una letra a encriptar (minúscula): ";
    char letra;
    std::cin >> letra;
    
    std::cout << "Ingresa el valor del desplazamiento para la encriptación (César): ";
    int shift;
    std::cin >> shift;

    // Convertimos la letra usando la función de encriptación
    char letraEncriptada = cesarEncrypt(letra, shift);

    // Lambda para transformar las palabras
    auto transformarPalabra = [letra, letraEncriptada](std::string& palabra) {
        std::transform(palabra.begin(), palabra.end(), palabra.begin(), 
            [letra, letraEncriptada](char ch) {
                return ch == letra ? letraEncriptada : ch;
            });
    };

    // Aplicamos la transformación a todas las palabras
    for (auto& palabra : palabras) {
        transformarPalabra(palabra);
    }

    // Mostramos el resultado
    std::cout << "Letra encriptada: " << letraEncriptada << std::endl;
    std::cout << "Palabras modificadas:\n";
    for (const auto& palabra : palabras) {
        std::cout << palabra << std::endl;
    }

    return 0;
}
