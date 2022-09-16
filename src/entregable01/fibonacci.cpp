#include <iostream>

using namespace std;

/** fibonacciIterativa: Recibe un entero (n) y devuelve otro entero (f_n) 
 correspondiente al n-esimo término de la serie de Fibonacci, de modo iterativo.*/
int fibonacci(int n){
    // Inicializo los dos primeros términos
    int f_n_menos_2 = 0;
    int f_n_menos_1 = 1;

    // Declaro un contador y el n-esimo término
    int count = 1;
    int f_n;

    // Separo los casos n=1 y n=0
    if (n == 0 || n == 1){
        return n;
    }

    // Para n mayores que uno
    while (count < n){
        // Actualizo el n-esimo término
        f_n = f_n_menos_1 + f_n_menos_2;

        // Actualizo los dos términos anteriores
        f_n_menos_2 = f_n_menos_1;
        f_n_menos_1 = f_n;

        count++;
    }

    return f_n;
}

int main() 
{
    int n;
    cin >> n;
    cout << fibonacci(n) << endl;    
    return 0;
}