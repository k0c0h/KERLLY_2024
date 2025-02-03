/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Proyecto Primer Parcial                             *
 * Autor:                          Kerlly Chiriboga,Heidy Mera                         *
 * Fecha de creacion:              06/12/2024                                          *
 * Fecha de modificacion:          06/12/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 **************************************************************************************/

#include "Menu.h"

int main() {
    HistorialEstacionamiento historial;
    AutosPermitidos autosPermitidos;
    Parqueadero parqueadero(&historial);
    Menu menu(&parqueadero, &historial, &autosPermitidos);
    menu.iniciar();

    return 0;
}
