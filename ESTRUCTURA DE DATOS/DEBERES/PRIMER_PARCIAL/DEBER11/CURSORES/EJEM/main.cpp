#include <iostream>
#include <conio.h> // Para getch() en Windows

using namespace std;

void mostrarMenu(int opcionSeleccionada, const string opciones[], int numOpciones) {
    system("cls"); // Limpia la pantalla (en Windows)
    cout << "Usa las flechas arriba/abajo para moverte y Enter para seleccionar:\n\n";
    for (int i = 0; i < numOpciones; i++) {
        if (i == opcionSeleccionada) {
            cout << " > " << opciones[i] << " <\n"; // Indicar opción seleccionada
        } else {
            cout << "   " << opciones[i] << '\n';
        }
    }
}

int main() {
    const string opciones[] = {"Opcion 1", "Opcion 2", "Opcion 3", "Salir"};
    const int numOpciones = 4;
    int opcionSeleccionada = 0;

    while (true) {
        mostrarMenu(opcionSeleccionada, opciones, numOpciones);
        int tecla = getch(); // Captura la tecla presionada

        if (tecla == 224) { // Tecla especial (como las flechas)
            tecla = getch(); // Capturar la segunda parte del código de la tecla
            if (tecla == 72) { // Flecha arriba
                opcionSeleccionada = (opcionSeleccionada - 1 + numOpciones) % numOpciones;
            } else if (tecla == 80) { // Flecha abajo
                opcionSeleccionada = (opcionSeleccionada + 1) % numOpciones;
            }
        } else if (tecla == 13) { // Enter
            cout << "Seleccionaste: " << opciones[opcionSeleccionada] << '\n';
            if (opcionSeleccionada == numOpciones - 1) { // Salir
                break;
            }
            system("pause");
        }
    }

    return 0;
}
