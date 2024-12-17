#include<iostream>
#include "Factorial.h"

using namespace std;

int main(){
    int num;

    cout<<"Ingrese un numero para calcular su factorial: ";
    cin>>num;

    Factorial factorial;

    int result = factorial.value(num);

    cout<<"El factorial de "<<num<<" es "<<result<<endl;

    return 0;
}