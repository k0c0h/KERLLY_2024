#ifndef SUMADIGITOS_H
#define SUMADIGITOS_H

class SumaDigitos {
public:
    int sumar(int numero);  // Método público para iniciar la suma de los dígitos
private:
    int sumarPrimerDigito(int numero);  // Función para obtener el primer dígito y continuar
    int sumarResto(int numero);  // Función para sumar el resto de los dígitos
};

#endif
