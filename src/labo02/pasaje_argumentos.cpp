/** Segunda guía de ejercicios del Labo de programación de 
Algoritmos y Estructura de Datos 1.
Ejercicios 4 a .*/
#include <iostream>

/*Headers*/
void atributos_circulo(const float &radio);

void triplicar_por_referencia(int &n);
int triplicar_por_valor(int n);

void swap(int &a, int &b);

void collatz_iterativo(int n, int &cantPasos);

void division(int dividendo, int divisor, int &cociente, int &resto);

int main(){
    // - Ejercicio 5
    float r;

    std::cout << "Ejercicio 5: atributos del círculo" << "\n";
    std::cout << "Introduzca el radio del circulo: " << "\n";
    std::cin >> r;

    atributos_circulo(r);

    // - Ejercicio 6
    int cuenta;

    std::cout << "\n";
    std::cout << "Ejercicio 6: Triplicar cuenta" << "\n";
    std::cout << "Introduzca el valor de cuenta: " << "\n";
    std::cin >> cuenta;

    // Si invierto el orden, modifico cuenta antes de triplicar por valor
    std::cout << "El triple de cuenta es (por valor): " << triplicar_por_valor(cuenta) << "\n";

    triplicar_por_referencia(cuenta);
    std::cout << "El triple de cuenta es (por referencia): " << cuenta << "\n";


    // - Ejercicio 7
    int a;
    int b;

    std::cout << "\n";
    std::cout << "Ejercicio 7: Intercambio de enteros" << "\n";
    std::cout << "Introduzca el primer entero: " << "\n";
    std::cin >> a;

    std::cout << "Introduzca el segundo entero: " << "\n";
    std::cin >> b;

    swap(a, b);
    std::cout << "Nuevo valor del primer entero: " << a << "\n";
    std::cout << "Nuevo valor del segundo entero: " << b << "\n";


    // - Ejercicio 8
    int cantidadPasos=0;
    int n;

    std::cout << "\n";
    std::cout << "Ejercicio 8: Conjetura de Collatz" << "\n";
    std::cout << "Introduzca el primer elemento de la sucesión: " << "\n";
    std::cin >> n;  

    collatz_iterativo(n, cantidadPasos);
    std::cout << "La cantidad de pasos realizados fue: " << cantidadPasos << "\n";    

    return 0;

}

/*---Funciones Auxiliares---*/

/*caracteristicas_circulo: recibe un flotante (radio) correspondiente al radio 
de un circulo y printea en pantalla su diametro, area y circunferencia.*/
void atributos_circulo(const float &radio){
    // Inicializo las constantes del problema
    const float pi = 3.14159;

    // Inicializo los valores a printear
    float diametro;
    float circunferencia;
    float area;

    // Calculo las magnitudes de interes
    diametro = 2 * radio;
    circunferencia = 2 * pi * radio;
    area = pi * radio * radio;

    // Printeo en pantalla
    std::cout << "El diametro del circulo es : " << diametro << "\n";
    std::cout << "La circunferencia del circulo es : " << circunferencia << "\n";
    std::cout << "El area del circulo es : " << area << "\n";

}

/*triplicar_por_referencia: modifica un entero (n) multiplicandolo
por tres.*/
void triplicar_por_referencia(int &n){
    // Multiplico el valor de entrada por tres
    n *= 3;
}

/*triplicar_por_valor: Recibe un entero (n) y retorna su triple.*/
int triplicar_por_valor(int n){
    // Multiplico el valor de entrada por tres
    return n * 3;
}

/*Recibe dos enteros (a y b) y los intercambia inplace*/
void swap(int &a, int &b){
    a = a + b;
    b = a - b;
    a = a - b;
}

/*collatz_iterativo: Recibe un natural n, y un entero por referencia (cantPasos) y retorna
la secuencia correspodiente de la conjetura de Collatz, modificando 
cantPasos con la cantidad de elementos de la serie.*/
void collatz_iterativo(int n, int &cantPasos){
    
    while (n > 1){
        // Printeo los elementos de la serie
        std::cout << n << " ";
        
        // Cuento la cantidad de pasos antes de llegar a 1
        cantPasos++;
        
        if (n % 2 == 0){
            n /= 2;
        }else{
            n *= 3;
            n++;
        }

    }
    // Agrego un paso por el 1 y lo printeo
    cantPasos++;
    std::cout << n << " ";
    
    // Printeo una nueva linea para finalizar
    std::cout << "\n";
}