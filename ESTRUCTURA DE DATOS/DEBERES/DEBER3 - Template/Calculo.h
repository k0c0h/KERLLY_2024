#ifndef CALCULO_H
#define CALCULO_H

template<typename T>
class Calculo{
    private:
         T a,b;

    public: 
        Calculo(T a, T b): a(a), b(b){}

    T getA() {
        return a; 
    }
    void setA();
    
    T getB() {
        return b;
    }
    void setB();

    T sumar(){
        return a +b;
    }

    T restar(){
        return a -b;
    }

    T multiplicar(){
        return a * b;
    }

};
 #endif
