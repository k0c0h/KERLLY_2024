#include <iostream>
#include <limits>  // Para numeric_limits

using namespace std;

// Función plantilla para ingresar un valor y validar la entrada
template <typename T>
T ingresarValor(const char *msj) {
    T valor;
    bool entradaValida = false;

    while (!entradaValida) {
        cout << msj;
        cin >> valor;

        // Validar si la entrada es correcta para el tipo T
        if (cin.fail()) {
            // Si la entrada es incorrecta, mostramos un mensaje y limpiamos el buffer
            cin.clear();  // Limpiar el estado de error de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignorar el resto de la línea

            cout << "Entrada inválida. Por favor ingrese un valor válido." << endl;
        } else {
            entradaValida = true;  // Entrada válida, salimos del bucle
        }
    }
    
    return valor;
}

int main() {
    // Usar la plantilla para ingresar diferentes tipos de valores
    int entero = ingresarValor<int>("Ingrese un número entero: ");
    cout << "Número entero ingresado: " << entero << endl;

    float flotante = ingresarValor<float>("Ingrese un número flotante: ");
    cout << "Número flotante ingresado: " << flotante << endl;

    return 0;
}
