#include <iostream>

using namespace std;

int main(){
    int a = 2;

    cout << a++ << endl;             
    cout << a++ + 1 + ++a << endl;   
    cout << ++a + 1 << endl;         
    cout << a++ + ++a << endl;       

    return 0;
}
