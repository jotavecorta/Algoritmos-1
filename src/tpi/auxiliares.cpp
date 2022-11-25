//
// Este archivo contiene las definiciones de las funciones auxiliares
// que ustedes necesiten implementar. Tienen que coincidir con las 
// declaraciones de auxiliares.h
//

#include <iostream>

#include "definiciones.h"
#include "ejercicios.h"
#include "auxiliares.h"

using namespace std;

/*Chequea que la posicion (i, j) sea valida en el tablero t. O(1)*/
bool posicionValida(tablero &t, int i, int j) {
    // Operaciones constantes: no hay ningun loop O(1)
    return (i>=0 && i < t.size()) && (j>=0 && j < t[0].size());
}

///*Mapea la posición (i, j) de un tablero de nxn en el indice correspondiente
// *del vector de jugadas.*/
//int mapIndex(int n, int i, int j) {
//    return i*n + j;
//}

///*Modifica los vectores de jugadas y banderitas -j y b- asignando posiciones dentro de
// *los mismos mediante una correspondencia 1 a 1 con las posiciones del tablero t. De esta
// *manera los vectores j y b quedan inicializados para comenzar el juego, y pueden ser
// *modificados a lo largo del mismo de manera estática y no dinámica. Esto reduce la complejidad
// *de algoritmos subsiguientes.*/
//void initJB(tablero& t, jugadas& j, banderitas& b) {
//    // Si j ya está inicializado no hace nada.
//    if (j.size() != 0) {
//        return;
//    }
//
//    /*
//     Jugadas tiene correspondencia 1 a 1 con los casilleros de la matriz
//
//     0  1  2  3
//     4  5  6  7
//     8  9  10 11
//     12 13 14 15
//
//     0           1           2           3
//     0   1  2  3  4  5  6  7  8  9  10 11 12 13 14 15
//     -1 -1  1 -1 -1 -1  2 -1 -1 -1  1  -1 -1 -1 -1 -1
//
//     Es decir la posición t[i][k] corresponde a j[i*m + k]
//     Esto nos permite acceder a la información de la posición en 0[2]
//    */
//
//    // Inicializamos j y b con valores que indican que las posiciones
//    //no fueron jugadas ni se marcó una banderita
//    int nm = t.size() * t[0].size();
//    pos null_pos(-1, -1);
//    jugada ju(null_pos, -1);
//
//    for (int i = 0; i < nm; ++i) {
//        j.push_back(ju);
//        b.push_back(null_pos);
//    }
//}

///*Modifica el vector jugadas, agregando la posicion jugada -p- y sus minas
// *adyacentes en lugar que corresponde segun la correspondencia con t.*/
//void jugar(tablero& t, jugadas& j, pos p) {
//    int index = mapIndex(t.size(), p.first, p.second);
//    jugada ju(p, minasAdyacentes(t, p));
//    j[index] = ju;
//}

/*Chequea si la posición p ya fue jugada para el juego determinado
 *por el tabletro t y el vector de jugadas j, para ello implementa un
 *algoritmo de busqueda lineal. Complejidad lineal en j: O(|j|)*/
bool posicionJugada(tablero& t, jugadas& j, pos p) {
    bool res = false;

    // Si la posicion no es valida retorna false
    if (!posicionValida(t, p.first, p.second)){ // O(1)
        return res;
    }

    // Recorro j en busca de p.
    int idx = 0;
    while(idx < j.size() && !res){ // Recorre todo j en el peor caso: O(|j|)

        // Operacion constante O(1)
        res = res || (j[idx].first == p);
        idx++;
    }

    return res;
}

/*Chequea si la posición p ya fue agregada a banderitas. Si fue agregada
 *devuelve el índice dentro del vector de banderitas, caso contrario devuelve -1.
 *Para ello implementa un algoritmo de busqueda lineal.
 *Complejidad lineal en b: O(|b|)*/
int estaEnBanderitas(tablero &t, banderitas &b, pos p) {
    // Operaciones constantes: O(1)
    int res = -1;

    // Si la posicion no es valida retorna -1
    if (!posicionValida(t, p.first, p.second)){
        return res;
    }

    int idx = 0;
    // Recorre todo b en el peor caso: O(|b|)
    while(idx < b.size() && b[idx] != p){
        // Operacion constante O(1)
        idx++;
    }

    // Si salio del while antes es porque encontro p
    if (idx != b.size()){// O(1)
        res = idx;
    }

    return res;
}

///*Retorna la cantidad de minas adyacentes a la posición p del
// *tablero t, teniendo en cuenta si ese calculo ya se realizó anteriormente.
// *En caso de haberse realizado, toma dicho valor del vector j.*/
//int minasAdyacentesWithCache(tablero& t, jugadas& j, pos p) {
//    int index = mapIndex(t.size(), p.first, p.second);
//    int c = j[index].second;
//    if (c > -1) {
//        return c;
//    }
//    return minasAdyacentes(t, p);
//}

///*Chequea si hay una banderita colocada en la posición p del tablero t,
// *comprobando en el vector de banderitas b.*/
//bool hayBanderita(tablero& t, banderitas& b, pos p) {
//    int index = mapIndex(t.size(), p.first, p.second);
//    return b[index].first != -1;
//}
