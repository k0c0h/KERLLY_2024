#include <iostream>
#include <string>
#include <functional>

using namespace std;

// Nodo genérico para las listas
template <typename T>
struct Nodo {
    T dato;
    Nodo<T>* siguiente;
    Nodo<T>* anterior; // Para listas dobles

    Nodo(T valor) : dato(valor), siguiente(nullptr), anterior(nullptr) {}
};

// Clase base para listas
template <typename T>
class Lista {
public:
    virtual void insertar(T dato) = 0;
    virtual void mostrar(function<string(T)> transform = nullptr) = 0;
    virtual void encriptar(function<T(T)> encriptarFuncion) = 0;
    virtual ~Lista() {}
};

// Lista simple
template <typename T>
class ListaSimple : public Lista<T> {
    Nodo<T>* cabeza;
public:
    ListaSimple() : cabeza(nullptr) {}

    void insertar(T dato) override {
        Nodo<T>* nuevo = new Nodo<T>(dato);
        nuevo->siguiente = cabeza;
        cabeza = nuevo;
    }

    void mostrar(function<string(T)> transform = nullptr) override {
        Nodo<T>* actual = cabeza;
        while (actual) {
            cout << (transform ? transform(actual->dato) : actual->dato) << " -> ";
            actual = actual->siguiente;
        }
        cout << "null" << endl;
    }

    void encriptar(function<T(T)> encriptarFuncion) override {
        Nodo<T>* actual = cabeza;
        while (actual) {
            actual->dato = encriptarFuncion(actual->dato);
            actual = actual->siguiente;
        }
    }

    ~ListaSimple() {
        while (cabeza) {
            Nodo<T>* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
    }
};

// Lista doble
template <typename T>
class ListaDoble : public Lista<T> {
    Nodo<T>* cabeza;
    Nodo<T>* cola;
public:
    ListaDoble() : cabeza(nullptr), cola(nullptr) {}

    void insertar(T dato) override {
        Nodo<T>* nuevo = new Nodo<T>(dato);
        if (!cabeza) {
            cabeza = cola = nuevo;
        } else {
            cola->siguiente = nuevo;
            nuevo->anterior = cola;
            cola = nuevo;
        }
    }

    void mostrar(function<string(T)> transform = nullptr) override {
        Nodo<T>* actual = cabeza;
        while (actual) {
            cout << (transform ? transform(actual->dato) : actual->dato) << " <-> ";
            actual = actual->siguiente;
        }
        cout << "null" << endl;
    }

    void encriptar(function<T(T)> encriptarFuncion) override {
        Nodo<T>* actual = cabeza;
        while (actual) {
            actual->dato = encriptarFuncion(actual->dato);
            actual = actual->siguiente;
        }
    }

    ~ListaDoble() {
        while (cabeza) {
            Nodo<T>* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
    }
};

// Lista circular
template <typename T>
class ListaCircular : public Lista<T> {
    Nodo<T>* primero;
    Nodo<T>* ultimo;
public:
    ListaCircular() : primero(nullptr), ultimo(nullptr) {}

    void insertar(T dato) override {
        Nodo<T>* nuevo = new Nodo<T>(dato);
        if (!primero) {
            primero = ultimo = nuevo;
            primero->siguiente = primero;
        } else {
            ultimo->siguiente = nuevo;
            nuevo->siguiente = primero;
            ultimo = nuevo;
        }
    }

    void mostrar(function<string(T)> transform = nullptr) override {
        if (!primero) {
            cout << "Lista vacía" << endl;
            return;
        }
        Nodo<T>* actual = primero;
        do {
            cout << (transform ? transform(actual->dato) : actual->dato) << " -> ";
            actual = actual->siguiente;
        } while (actual != primero);
        cout << "(circular al inicio)" << endl;
    }

    void encriptar(function<T(T)> encriptarFuncion) override {
        if (!primero) return;
        Nodo<T>* actual = primero;
        do {
            actual->dato = encriptarFuncion(actual->dato);
            actual = actual->siguiente;
        } while (actual != primero);
    }

    ~ListaCircular() {
        if (!primero) return;
        Nodo<T>* actual = primero;
        do {
            Nodo<T>* temp = actual;
            actual = actual->siguiente;
            delete temp;
        } while (actual != primero);
    }
};

// Función de ejemplo para encriptar usando César
string cesarCipher(const string& text, int shift) {
    string result;
    for (char c : text) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            result += (c - base + shift) % 26 + base;
        } else {
            result += c;
        }
    }
    return result;
}

int main() {
    ListaSimple<string>* listaSimple = new ListaSimple<string>();
    ListaDoble<string>* listaDoble = new ListaDoble<string>();
    ListaCircular<string>* listaCircular = new ListaCircular<string>();

    int opcion;
    string dato;

    do {
        cout << "\nElija una opción:" << endl;
        cout << "1. Insertar en Lista Simple" << endl;
        cout << "2. Insertar en Lista Doble" << endl;
        cout << "3. Insertar en Lista Circular" << endl;
        cout << "4. Mostrar Listas" << endl;
        cout << "5. Encriptar Listas" << endl;
        cout << "6. Salir" << endl;
        cout << "Opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese un dato para la Lista Simple: ";
                cin >> dato;
                listaSimple->insertar(dato);
                break;
            case 2:
                cout << "Ingrese un dato para la Lista Doble: ";
                cin >> dato;
                listaDoble->insertar(dato);
                break;
            case 3:
                cout << "Ingrese un dato para la Lista Circular: ";
                cin >> dato;
                listaCircular->insertar(dato);
                break;
            case 4:
                cout << "\nLista Simple:" << endl;
                listaSimple->mostrar();
                cout << "\nLista Doble:" << endl;
                listaDoble->mostrar();
                cout << "\nLista Circular:" << endl;
                listaCircular->mostrar();
                break;
            case 5:
                listaSimple->encriptar([](const string& dato) { return cesarCipher(dato, 3); });
                listaDoble->encriptar([](const string& dato) { return cesarCipher(dato, 3); });
                listaCircular->encriptar([](const string& dato) { return cesarCipher(dato, 3); });
                cout << "\nListas encriptadas." << endl;
                break;
            case 6:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
        }
    } while (opcion != 6);

    delete listaSimple;
    delete listaDoble;
    delete listaCircular;

    return 0;
}