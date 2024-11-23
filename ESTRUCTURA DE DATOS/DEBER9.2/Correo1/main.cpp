#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <set>

using namespace std;

// Función auxiliar para convertir un string a minúsculas
std::string toLowerString(const std::string& str) {
    std::string result = str;
    for (char& c : result) {
        c = tolower(c);
    }
    return result;
}

// Clase para manejo de generación de correos
template <typename T>
class GeneradorCorreos {
private:
    vector<string> correos;
    unordered_map<string, int> contadorCorreos;

    // Palabras comunes que deben ser ignoradas
    const set<string> palabrasIgnoradas = {"del", "de", "la", "el", "los", "las"};

    // Función para obtener la inicial de una palabra significativa
    char obtenerInicial(const T& palabra) {
        return tolower(palabra[0]);
    }

    // Procesar un apellido o nombre compuesto y obtener la última palabra válida
    T procesarApellido(const T& apellidoCompuesto) {
        stringstream ss(apellidoCompuesto);
        T palabra, ultimaPalabraValida;
        while (ss >> palabra) {
            if (palabrasIgnoradas.find(toLowerString(palabra)) == palabrasIgnoradas.end()) {
                ultimaPalabraValida = palabra;
            }
        }
        return ultimaPalabraValida;
    }

    // Generar el correo basado en los criterios
    string generarCorreo(T primerNombre, T segundoNombre, T apellido) {
        string correo;
        correo += obtenerInicial(primerNombre);                // Primera letra del primer nombre
        correo += obtenerInicial(segundoNombre);               // Inicial del segundo nombre
        correo += toLowerString(procesarApellido(apellido));   // Última palabra válida del apellido

        // Validar si ya existe el correo
        if (contadorCorreos[correo] > 0) {
            correo += to_string(contadorCorreos[correo]); // Agregar índice
        }
        contadorCorreos[correo]++; // Incrementar contador para futuros duplicados

        correo += "@espe.edu.ec"; // Agregar dominio
        return correo;
    }

public:
    // Ingresar los datos y generar el correo
    void ingresarDatos() {
        T primerNombre, segundoNombre, apellidoCompuesto;
        cout << "Ingrese primer nombre: ";
        cin.ignore(); // Ignorar caracteres residuales del buffer
        getline(cin, primerNombre); // Leer nombre compuesto completo

        cout << "Ingrese segundo nombre: ";
        getline(cin, segundoNombre); // Leer segundo nombre compuesto completo

        cout << "Ingrese apellido compuesto: ";
        getline(cin, apellidoCompuesto); // Leer el apellido compuesto completo

        // Generar correo y almacenarlo
        string correo = generarCorreo(primerNombre, segundoNombre, apellidoCompuesto);
        correos.push_back(correo);
        cout << "Correo generado: " << correo << endl;
    }

    // Mostrar todos los correos
    void mostrarCorreos() const {
        cout << "\nCorreos generados:" << endl;
        for (const auto& correo : correos) {
            cout << correo << endl;
        }
    }
};

int main() {
    // Crear instancia de la clase para generar correos
    GeneradorCorreos<string> generador;
    int opcion;

    do {
        cout << "\nMenu de opciones:\n";
        cout << "1. Ingresar datos y generar correo\n";
        cout << "2. Mostrar correos generados\n";
        cout << "3. Salir\n";
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                generador.ingresarDatos();
                break;
            case 2:
                generador.mostrarCorreos();
                break;
            case 3:
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opcion no valida.\n";
                break;
        }
    } while (opcion != 3);

    return 0;
}
