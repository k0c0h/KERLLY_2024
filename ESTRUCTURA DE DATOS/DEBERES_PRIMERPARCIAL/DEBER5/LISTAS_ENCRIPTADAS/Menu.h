/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Listas Encriptadas(Metodo de Cesar)                 *
 * Autor:                          Kerlly Chiriboga                                    *
 * Fecha de creacion:              25/11/2024                                          *
 * Fecha de modificacion:          27/11/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 **************************************************************************************/

#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <vector>
#include <string>

class Menu {
public:
    /**
     * @brief 
     * @param titulo 
     * @param opciones 
     * @return 
     */
    int mostrarMenu(const std::string& titulo, const std::vector<std::string>& opciones);
};

#endif 
