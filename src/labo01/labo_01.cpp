/** Primera guía de ejercicios del Labo de programación de 
Algoritmos y Estructura de Datos 1*/
#include <iostream>

/** f: Recibe dos enteros (x e y) y retorna un entero igual la suma,
en caso de que x > y. En caso contrario retorna un entero igual a la 
multiplicación.*/
int f(int x, int y){
    if (x > y){
        return x + y;
    } else{
        return x*y;
    }
    
}

/** esPrimo: recibe un entero (n) y retorna True en caso de que el mismo
sea un número primo. Caso contrario retorna False.*/
bool esPrimo(int n){
    // Inicializamos una variable de control y un contador
    int i = 2;
    int count = 0;
    
    // Recorremos de 2 a n
    while (i < n){
        if (n % i == 0){
            // Entra si n es divisible por i
            count++;
        } else {
            // Si no es divisible no modificamos nada
        }
        i++;
    }

    return (count==0);
}

/** fibonacciRecursiva: Recibe un entero (n) y devuelve otro entero correspondiente
 al n-esimo término de la serie de Fibonacci, de modo recursivo.*/
int fibonacciRecursiva(int n){
    if (n==0){

        return 0;

    } else if (n==1){

        return 1;
        
    } else{  // Para n>2 se calcula de forma recursiva

        return fibonacciRecursiva(n-1) + fibonacciRecursiva(n-2);
    
    }    
}

/*sumaImparesRecursiva: recibe un entero (n) y devuelve la suma
de todos los enteros menores que n, que sean impares.*/
int sumaImparesRecursiva(int n){
    if (n==1){
        return 0;
    } else if (n % 2 == 0){
        return n - 1 + sumaImparesRecursiva(n - 1);
    } else{
        return n - 2 + sumaImparesRecursiva(n - 2);
    }
}

/*sumaImpares: recibe un entero (n) y devuelve la suma (sum)
de todos los enteros menores, que sean impares.*/
int sumaImpares(int n){
    // Inicializo una variables de control y acumulador
    int i = 0;
    int sum = 0;
    
    // Recorro los enteros menores que n
    while (i < n){
        if (i % 2 != 0){
            // Si i es impar se agrega a la suma
            sum += i;
        }
        i++;
    }
    return sum;
}

/*sumaImpares: recibe un entero (n) y devuelve la suma (sum)
de todos sus divisores.*/
int sumaDivisores(int n){
    // Inicializo una variables de control y acumulador
    int i = 1;
    int sum = 0;
    
    // Recorro los enteros menores que n
    while (i < n){
        if (n % i == 0){
            // Si i es divisor se agrega a la suma
            sum += i;
        }
        i++;
    }
    return sum;    
}

/*combinatoria: recibe dos enteros (n y k) y devuelve la 
combinatoria (n-k).*/
int combinatoria(int n, int k){
    if (k==0 || n==k){
        return 1;
    } else{
        return combinatoria(n, k-1) + combinatoria(n-1, k-1);
    }    
}


int main() {
    int n;

    // Pedimos al usuario un numero entero
    std::cout << "Inserte un número natural: " << std::endl;
    std::cin >> n;

    // Numeros Primos
    std::cout << "- El numero " << n;

    // Printeamos segun el caso
    if (esPrimo(n)){
        std::cout << " es primo." << std::endl;
    } else {
        std::cout << " no es primo" << std::endl;
    }

    // Fibonacci Recursivo
    std::cout << "- El término número " << n << " de la serie de Fibonacci es: ";
    std::cout << fibonacciRecursiva(n) << std::endl;

    // Suma de impares menores a n
    std::cout << "- La suma de los enteros impares menores a " << n << " es: ";
    std::cout << sumaImpares(n) << std::endl;

    // Suma de impares menores a n, recursiva
    std::cout << "- La suma recursiva de los enteros impares menores a " << n << " es: ";
    std::cout << sumaImpares(n) << std::endl;

    // Suma de divisores de n
    std::cout << "- La suma de los divisores de " << n << " es: ";
    std::cout << sumaDivisores(n) << std::endl;

    return 0;
}