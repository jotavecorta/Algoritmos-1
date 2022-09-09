/** Segunda guía de ejercicios del Labo de programación de 
Algoritmos y Estructura de Datos 1.
Ejercicios 4 a .*/
#include <iostream>

/*Headers*/
void caracteristicas_circulo(const float &radio);


int main(){
    float r;

    std::cout << "Introduzca el radio del circulo: " << "\n";
    std::cin >> r;

    caracteristicas_circulo(r);

    return 0;
}

/*Funciones Auxiliares*/

/*caracteristicas_circulo: recibe un flotante (radio) correspondiente al radio 
de un circulo y printea en pantalla su diametro, area y circunferencia.*/
void caracteristicas_circulo(const float &radio){
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