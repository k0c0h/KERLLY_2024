#include "SumaDigitos.h"

int SumaDigitos::sumar(int numero) {
    return sumarPrimerDigito(numero);  // Inicia la suma de los dígitos
}

int SumaDigitos::sumarPrimerDigito(int numero) {
    if (numero == 0) return 0;  // Caso base: si el número es 0, la suma es 0
    return (numero % 10) + sumarResto(numero / 10);  // Llama a sumarResto con el resto del número
}

int SumaDigitos::sumarResto(int numero) {
    if (numero == 0) return 0;  // Caso base: si el número es 0, no queda nada que sumar
    return sumarPrimerDigito(numero);  // Llama recursivamente a sumarPrimerDigito para procesar el siguiente dígito
}
