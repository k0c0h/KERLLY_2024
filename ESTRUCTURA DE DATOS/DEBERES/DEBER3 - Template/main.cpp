#include "Calculo.h"
#include <iostream>
 using namespace std;

int main(){
    float a,b;

    cout<<"Ingresa el valor de a: "<<endl;
    cin>>a;

    cout<<"Ingrese el valor para b: "<<endl;
    cin>>b;

    Calculo<float> intCalculo(a,b);

    cout<<"El valor de a es: "<<intCalculo.getA()<<endl;
    cout<<"El valor de b es: "<<intCalculo.getB()<<endl;

    cout<<"La suma es: "<<intCalculo.sumar()<<endl;
    cout<<"La resta es: "<<intCalculo.restar()<<endl;
    cout<<"La multiplicacion es: "<<intCalculo.multiplicar()<<endl;

    return 0;
}
