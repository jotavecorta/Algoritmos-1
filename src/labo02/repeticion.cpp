/** Segunda guía de ejercicios del Labo de programación de 
Algoritmos y Estructura de Datos 1.
Ejercicios 1 a 3.*/
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    // Inicializo un entero para usar de entrada del sistema
    int n;

    // Inicializo la suma y el promedio del curso
    int suma = 0;
    float promedio = 0.0;

    // Inicializo un centinela para cortar la iteracion y un contador
    int sentinel = 0;
    int counter = 0;

    // Alumnos aprobados y desaprobados
    int approved = 0;
    int disapproved = 0;

    while (sentinel >= 0){
        // Pido la nota de cada alumno por linea de comandos

        cout << "Ingrese la nota del alumno número " << counter + 1 << ": \n";
        cin >> n;

        // Agrego las notas validas a la suma y modifico el contador
        if (n>=0 && n<=10){
            suma += n;            
            counter++;

            // Agrego los aprobados
            if (n > 6){approved++;}
        }
            
        // Guardo la nota en el centinela para evaluar en la siguiente iteración
        sentinel = n;
    }

    // Calculo el promedio
    if (counter + 1 < 6){ 
        // Caso inválido
        cout << "El número de notas no puede ser menor que 6" << "\n";
        return 0;
    } else if (counter!=0){
        promedio = (float)suma / counter;
        disapproved = counter - approved;
    }
    

    // Muestro en pantalla la suma de las notas y el promedio
    cout << "La suma de las notas del curso es: " << suma << "\n";
    cout << "El promedio de las notas del curso es: "; 
    cout << fixed << setprecision(2) <<promedio << "\n";

    // Muestro en pantalla la cantidad de aprobados
    if (approved > (2 * (float)counter / 3)){
        cout << "Se pueden incrementar el número de plazas del curso." << "\n";;
    }
    
    return 0;

}

