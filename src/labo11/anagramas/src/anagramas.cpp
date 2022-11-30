#include <string>

#include "anagramas.h"
#include "auxiliares.h"

using namespace std;

bool esAnagrama(string p1, string p2){
    // CAMBIAR AQUI QUE IMPLEMENTACION USAR
    return esAnagrama1(p1,p2);
}

bool esAnagrama1(string p1, string p2){
    //devuelve true sii p1 es anagrama de p2
    //esta versión usa ordenar
    ordenarString(p1);
    ordenarString(p2);
    return p1 == p2;
}

bool esAnagrama2(string p1, string p2){
    //COMPLETAR
    //devuelve true sii p1 es anagrama de p2
    //esta versión usa el mapeo de letras a números primos. Utilizar charToPrimo()

    return true;
}

void ordenarString(string &palabra){
    //insertionSort(palabra);
    selectionSort(palabra);

}

int charToPrimo(char c){
    //COMPLETAR
    //Dado una letra minuscula de a-z (sin enie) devolver el numero primo correspondiente.

    return 0;
}

