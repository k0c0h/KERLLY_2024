#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int ingresar (char* msj){
    char cad[10];
    char c;
    int i = 0;
    int valor;
    printf("%s ", msj);
    while((c = getch()) != 13){ 
        if(c >= '0' && c <= '9'){
            printf("%c", c);
            cad[i++] = c;
        }
    }
    cad[i] = '\0';
    valor = atoi(cad); 
    return valor;
}

int main(){
    int valor;
    valor = ingresar("Ingrese un valor entero: "); 
    printf("\nSe ha convertido la cadena anterior en un entero: %d", valor); 
}
