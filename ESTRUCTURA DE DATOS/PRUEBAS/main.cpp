#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

const std::vector<std::string> validKeys = {
    "12345-ABCDE",
    "54321-ZYXWV",
    "67890-PQRST",
    "11111-22222",
    "ABCDE-12345"
};

bool validateKey(const std::string& key) {
    return std::find(validKeys.begin(), validKeys.end(), key) != validKeys.end();
}

int main() {
    std::string userKey;
    bool isValid = false;

    std::cout << "Bienvenido al instalador de Mi Programa.\n";

    while (!isValid) {
        std::cout << "Por favor, ingresa tu clave de activacion (5 bloques de 5 digitos): ";
        std::getline(std::cin, userKey);

        if (validateKey(userKey)) {
            isValid = true;
            std::cout << "Clave valida. Procediendo con la instalacion...\n";
        } else {
            std::cout << "Clave no valida. Intenta de nuevo.\n";
        }
    }
    std::cout << "Instalando archivos...\n";
    std::cout << "Instalacion completada con exito! Gracias por usar Mi Programa.\n";
    return 0;
}
