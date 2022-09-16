#include <iostream>

using namespace std;

/*Recibe dos enteros (a y b) y los intercambia inplace*/
void swap(int& a, int& b){
    a = a + b;
    b = a - b;
    a = a - b;
}

int main() {
    /* No hace falta modificar el main */
    int a,b;
    //Leo a
    cin >> a >> b;
    
    swap(a,b);
    
    //Devuelvo despues del swap
    cout << a << " " << b;
    return 0;
}
