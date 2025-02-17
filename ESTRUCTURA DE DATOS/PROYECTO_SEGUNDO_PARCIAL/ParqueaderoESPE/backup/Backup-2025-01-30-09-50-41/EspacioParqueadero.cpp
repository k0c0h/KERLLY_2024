/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Proyecto Primer Parcial                             *
 * Autor:                          Kerlly Chiriboga,Heidy Mera                         *
 * Fecha de creacion:              06/12/2024                                          *
 * Fecha de modificacion:          06/12/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 **************************************************************************************/

#include "EspacioParqueadero.h"
#include "Nodo.h"

Nodo* EspacioParqueadero::crearEspacio(const string& id) {
    return new Nodo(id);
}

void EspacioParqueadero::ocuparEspacio(Nodo* espacio, const string& placa) {
    if (!espacio->ocupado) {
        espacio->ocupado = true;
        espacio->placa = placa;
        espacio->horaIngreso = time(nullptr);
        cout << "Espacio " << espacio->id << " ocupado por el auto con placa " << placa << "." << endl;
    } else {
        cout << "El espacio " << espacio->id << " ya esta ocupado." << endl;
    }
}

void EspacioParqueadero::liberarEspacio(Nodo* espacio) {
    if (espacio->ocupado) {
        espacio->ocupado = false;
        espacio->placa = "";
        espacio->horaIngreso = 0;
        cout << "Espacio " << espacio->id << " liberado." << endl;
    } else {
        cout << "El espacio " << espacio->id << " ya esta libre." << endl;
    }
}

string EspacioParqueadero::obtenerEstado(const Nodo* espacio) const {
    if (espacio->ocupado) {
        return "Ocupado por " + espacio->placa;
    }
    return "Libre";
}
