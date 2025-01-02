#include "ListaPropietarios.h"
#include <fstream>
#include <sstream>
#include "Lista.h"

ListaPropietarios::ListaPropietarios() {
    primero = nullptr;
    ultimo = nullptr;
}

ListaPropietarios::~ListaPropietarios() {
    Nodo<Propietario>* aux;
    while (primero != nullptr) {
        aux = primero;
        primero = primero->getSiguiente();
        delete aux;
    }
}

void ListaPropietarios::agregarPropietario(const Propietario &propietario) {
    Nodo<Propietario>* nuevoNodo = new Nodo<Propietario>(propietario);

    if (primero == nullptr) {
        primero = nuevoNodo;
        ultimo = nuevoNodo;
    } else {
        ultimo->setSiguiente(nuevoNodo);
        nuevoNodo->setAnterior(ultimo);
        ultimo = nuevoNodo;
    }
}

Propietario* ListaPropietarios::buscarPropietarioPorCedula(const string &cedula) {
    Nodo<Propietario>* aux = primero;
    while (aux != nullptr) {
        if (aux->getDato().getCedula() == cedula) {
            return &aux->getDato();
        }
        aux = aux->getSiguiente();
    }
    return nullptr;
}

void ListaPropietarios::mostrarPropietarios() const {
    Nodo<Propietario>* aux = primero;
    if (aux == nullptr) {
        cout << "La lista de propietarios está vacía." << endl;
        return;
    }
    while (aux != nullptr) {
        cout << aux->getDato().toString() << endl;
        aux = aux->getSiguiente();
    }
}

bool ListaPropietarios::estaVacia() const {
    return primero == nullptr;
}

void ListaPropietarios::cargarArchivo(const string &archivo) {
    ifstream file(archivo);
    if (file.is_open()) {
        string linea;
        while (getline(file, linea)) {
            stringstream ss(linea);
            string nombre, apellido, cedula, correo, placa;
            getline(ss, nombre, ',');
            getline(ss, apellido, ',');
            getline(ss, cedula, ',');
            getline(ss, correo, ',');
            Propietario propietario(nombre, apellido, cedula, correo);
            while (getline(ss, placa, ',')) {
                propietario.agregarPlaca(ListaDoble<Propietario>::descifrarTexto(placa));
            }
            agregarPropietario(propietario);
        }
        file.close();
    } else {
        cerr << "Error al abrir el archivo para cargar propietarios." << endl;
    }
}

void ListaPropietarios::guardarArchivo(const string &archivo) const {
    ofstream file(archivo);
    if (file.is_open()) {
        Nodo<Propietario>* aux = primero;
        while (aux != nullptr) {
            const Propietario& propietario = aux->getDato();
            file << propietario.getNombre() << ","
                 << propietario.getApellido() << ","
                 << propietario.getCedula() << ","
                 << propietario.getCorreo();
            for (const auto &placa : propietario.getPlacas()) {
                file << "," << ListaDoble<Propietario>::cifrarTexto(placa);
            }
            file << endl;
            aux = aux->getSiguiente();
        }
        file.close();
    } else {
        cerr << "Error al abrir el archivo para guardar propietarios." << endl;
    }
}
