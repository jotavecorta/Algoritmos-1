#include "ejercicios.h"
#include "time.h"
#include <cmath>
#include <ctime>
#include "stdlib.h"
#include <string>
#include<iostream>

using namespace std;

int busquedaBinaria(vector<int> &v, int x){
    bool encontro_x = false;

    // Casos Triviales
    if (v.empty()) {// Vector vacío
        ;// No hago nada
    }else if (x >= v[v.size() - 1]) {// x fuera de rango por arriba
        encontro_x = (x == v[v.size() - 1]);
    }else {
        // Inicializo los bordes de búsqueda
        int low = 0;
        int high = v.size() -1;

        while (high > low + 1 && v[low] != x){
            // Tomo el elemento central del vector
            int middle = (high + low)/2;

            // Corro los bordes
            if (v[middle] > x){
                high = middle;
            }else{
                low = middle;
            }
        }
        encontro_x = (v[low] == x);
    }
    if (!encontro_x){
        return -1;
    }else if (v[v.size()-1]==x){
        return v.size() - 1;
    }else{
        return low;
    }
}

int busquedaJumpSearch(vector<int> &v, int x){
	// Saltos para tener complejidad O(n^1/2)
    int i = 0;
    int m = sqrt(v.size());

    // Hago saltos hasta pasarme de x
    while (i < v.size() && v[i] < x){
        i += m;
    }

    // Busqueda lineal
    int k = i - m;
    while (k < v.size() && v[k] < x){
       k++;
    }

    if (k < v.size() && v[k] == x){//Encontre x
        return k;
    } // No encontre x
    return -1;
}

int buscar(vector<int> v, int x){
    return busquedaBinaria(v, x);
    //return busquedaJumpSearch(v, x);
}


double ejemplo_como_calcular_tiempos() {
    clock_t begin = clock();

    for(int i=0 ; i < 100000; i++){
        // nada
    }

    clock_t end = clock();
    double elapsed_msecs = double(end - begin) / CLOCKS_PER_SEC  * 1000; // mide el tiempo en milisegundos
    return elapsed_msecs;
}

vector<int> construir_vector(int size, string mode){
    vector<int> res {};
    time_t t;
    srand((unsigned) time(&t));
    int base = rand() % 100;
    int step;
    for(int i = 0; i < size; i++){
        step = rand() % 100;
        if(mode == "asc") {
            res.push_back(base+step);
            base += step;
        }
        if(mode == "desc"){
            res.push_back(base-step);
            base -= step;
        }
        if(mode == "azar"){
            res.push_back(step);
        }
        if(mode == "iguales"){
            res.push_back(base);
        }
    }
    return res;
}



int indicePico(vector<int> &v){
	// Primero chequeo condiciones triviales
    if (v.empty()){
        return -1;
    }else if (v.size()==1){
        return 0;
    }else{// Casos no triviales: recorro todo el vector
        for (int i = 0; i < v.size(); ++i) {
            if (i == 0 && (v[i] >= v[i+1])){//Borde izqiuerdo: si no entro en los anteriores v.size>1
                return 0;
            }else if (i == v.size()-1 && (v[i] >= v[i-1])){// Borde derecho
                return v[i];
            }else{// Interior del vector
                if ((v[i] >= v[i-1]) && (v[i] >= v[i+1])){
                    return i;
                }else{
                    return -1;
                }
            }
        }
    }
}

int puntoFijo(vector<int> &v){
	if (v.size() == 0){// Caso trivial
        return -1;
    }else{// Resto de los casos: hago busqueda binaria
        // Defino bordes de busqueda
        int low = 0;
        int high = v.size() - 1;

        while (high > low + 1){
            // Posicion media
            int mid = (high + low) / 2;

            // Si la posicion media cumple, listo
            if (v[mid]==mid){
                return mid;
            }

            // Sino, actualizo los bordes
            if (v[mid] > mid){
                low = mid;
            }else{
                high = mid;
            }
        }
    }
    // En caso de salir del loop sin encontrar
    return -1;
}

int encontrarRotado(vector<int> &v, int x){
//	vector<int> vector_ordenado = desrotar(v);
//    return busquedaBinaria(vector_ordenado, x);

}

//vector<int> desrotar(vector<int> &v){
//
//}

int menorMasGrande(vector<int> &v, int x) {
    if (v.size() == 0) {// Caso trivial
        return -1;
    } else {
        int indice_x = busquedaBinaria(v, x);
        if (indice_x == v.size() || indice_x == -1){
            return -1;
        }else{
            return indice_x + 1;
        }
    }
}

vector<int> masCercanoK(vector<int> &v, int k,  int x){
	return {};
}
