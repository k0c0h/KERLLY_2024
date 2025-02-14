// Menu.cpp
#include "HashTable.h"
#include "Menu.h"
#include "Validaciones.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace std;

void pausar() {
    cout << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();
}

void manejarEnteros() {
    int tamanio, clave, metodo;
    Validaciones<int> validador;
    tamanio = validador.ingresar("Ingrese el tamanio de la tabla hash: ", "entero");
    
    // Crear la tabla hash con el tamaño ingresado y pasar la ventana
    HashTable<int> ht(tamanio);  // Aquí pasamos la ventana
    ht.drawTable();

    cout << "\n==== Metodos de resolucion de colisiones ====\n";
    cout << "1. Sondeo Lineal\n2. Sondeo Cuadratico\n3. Doble Hashing\n";
    metodo = validador.ingresar("\nIngrese el metodo de resolucion de colisiones: ", "entero");
    
    Menu menu;
    vector<string> opciones = {"Insertar", "Eliminar", "Buscar", "Mostrar", "Salir"};
    while (true) {
        int opcion = menu.mostrarMenu("==== Menu Hash Cerrado con Enteros ====", opciones);
        switch (opcion) {
            case 0:
                clave = validador.ingresar("Ingrese el valor a insertar: ", "entero");
                ht.insert(clave, metodo);
                break;
            case 1:
                clave = validador.ingresar("Ingrese el valor a eliminar: ", "entero");
                ht.remove(clave, metodo);
                pausar();
                break;
            case 2:
                clave = validador.ingresar("Ingrese el valor a buscar: ", "entero");
                cout << (ht.search(clave) ? "\nValor encontrado!" : "\nValor no encontrado.") << endl;
                pausar();
                break;
            case 3:
                ht.display();
                pausar();
                break;
            case 4:
                return;
            default:
                cout << "Opción no valida." << endl;
        }
        ht.drawTable();
    }
}

void manejarCadenas() {
    int tamanio, metodo;
    string clave;
    Validaciones<int> validadorInt;
    Validaciones<string> validador;
    tamanio = validadorInt.ingresar("Ingrese el tamanio de la tabla hash: ", "entero");
        
    // Crear la tabla hash con el tamaño ingresado y pasar la ventana
    HashTable<string> ht(tamanio);  // Aquí pasamos la ventana
    ht.drawTable();

    cout << "\n=== Metodos de resolucion de colisiones ===\n";
    cout << "1. Sondeo Lineal\n2. Sondeo Cuadratico\n3. Doble Hashing\n";
    metodo = validadorInt.ingresar("\nIngrese el metodo de resolucion de colisiones ", "entero");
    
    Menu menu;
    vector<string> opciones = {"Insertar", "Eliminar", "Buscar", "Mostrar", "Salir"};
    while (true) {
        int opcion = menu.mostrarMenu(" ==== Menu Hash Cerrado con Cadenas ====", opciones);
        switch (opcion) {
            case 0:
                clave = validador.ingresar("Ingrese la cadena a insertar: ", "string");
                ht.insert(clave, metodo);
                break;
            case 1:
                clave = validador.ingresar("Ingrese la cadena a eliminar: ", "string");
                ht.remove(clave, metodo);
                pausar();
                break;
            case 2:
                clave = validador.ingresar("Ingrese la cadena a buscar: ", "string");
                cout << (ht.search(clave) ? "\nCadena encontrada!" : "\nCadena no encontrada.") << endl;
                pausar();
                break;
            case 3:
                ht.display();
                pausar();
                break;
            case 4:
                return;
            default:
                cout << "Opcion no valida." << endl;
        }
        ht.drawTable();
    }
}


int main() {
    Menu menu;
    vector<string> opciones = {"Trabajar con Enteros", "Trabajar con Cadenas", "Salir"};

    while (true) {
        int opcion = menu.mostrarMenu("====== Menu Principal =======", opciones);

        switch (opcion) {
            case 0:
                manejarEnteros();  // Llama al submenú de enteros
                break;
            case 1:
                manejarCadenas();  // Llama al submenú de cadenas
                break;
            case 2:
                cout << "Saliendo del programa..." << endl;
                return 0;
            default:
                cout << "Opcion no valida." << endl;
        }
    }

    return 0;
}