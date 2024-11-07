#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstring> 


int ingresarEntero(char* msj) {
    char cad[10];
    char c;
    int i = 0;
    int valor;
    printf("%s ", msj);
    while ((c = getch()) != 13) { 
        if (c >= '0' && c <= '9') {
            printf("%c", c);
            cad[i++] = c;
        }
    }
    cad[i] = '\0';
    valor = atoi(cad); 
    return valor;
}

float ingresarFlotante(char* msj) {
    char cad[20];
    char c;
    int i = 0;
    float valor;
    printf("%s ", msj);
    while ((c = getch()) != 13) {
        if ((c >= '0' && c <= '9') || c == '.') { 
            printf("%c", c);
            cad[i++] = c;
        }
    }
    cad[i] = '\0'; 
    valor = atof(cad); 
    return valor;
}

char ingresarCaracter(char* msj) {
    char c;
    printf("%s ", msj);
    c = getch(); 
    printf("%c", c); 
    return c; 
}

void ingresarCadena(char* msj, char* cad, int maxLength) {
    char c;
    int i = 0;
    printf("%s ", msj);
    while ((c = getch()) != 13) { 
        if (c == 8 && i > 0) { 
            i--;
            printf("\b \b"); 
        }
        else if (i < maxLength - 1 && c != 8) {  
            printf("%c", c); 
            cad[i++] = c; 
        }
    }
    cad[i] = '\0'; 
}

int main() {
    int valorInt;
    float valorFloat;
    char valorChar;
    char valorString[20]; 

    valorInt = ingresarEntero("Ingrese un valor entero:");
    printf("\nValor entero ingresado: %d\n", valorInt);

    valorFloat = ingresarFlotante("Ingrese un valor flotante: ");
    printf("\nValor flotante ingresado: %.2f\n", valorFloat);

    valorChar = ingresarCaracter("Ingrese un carácter: ");
    printf("\nCarácter ingresado: %c\n", valorChar);

    ingresarCadena("Ingrese una cadena de texto:", valorString, 20);
    printf("\nCadena de texto ingresada: %s\n", valorString);

    return 0;
}
