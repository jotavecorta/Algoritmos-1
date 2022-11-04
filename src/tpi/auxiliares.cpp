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

/*Chequea que la posicion (i, j) sea valida en el tablero t.*/
bool posicionValida(tablero& t, int i, int j) {
    return (i>=0 && i < t.size()) && (j>=0 && j < t[0].size());
}

/*Mapea la posición (i, j) de un tablero de nxn en el indice correspondiente
 *del vector de jugadas.*/
int mapIndex(int n, int i, int j) {
    return i*n + j;
}

/*Modifica los vectores de jugadas y banderitas -j y b- asignando posiciones dentro de
 *los mismos mediante una correspondencia 1 a 1 con las posiciones del tablero t. De esta
 *manera los vectores j y b quedan inicializados para comenzar el juego, y pueden ser
 *modificados a lo largo del mismo de manera estática y no dinámica. Esto reduce la complejidad
 *de algoritmos subsiguientes.*/
void initJB(tablero& t, jugadas& j, banderitas& b) {
    // Si j ya está inicializado no hace nada.
    if (j.size() != 0) {
        return;
    }

    /*
     Jugadas tiene correspondencia 1 a 1 con los casilleros de la matriz

     0  1  2  3
     4  5  6  7
     8  9  10 11
     12 13 14 15

     0           1           2           3
     0   1  2  3  4  5  6  7  8  9  10 11 12 13 14 15
     -1 -1  1 -1 -1 -1  2 -1 -1 -1  1  -1 -1 -1 -1 -1

     Es decir la posición t[i][k] corresponde a j[i*m + k]
     Esto nos permite acceder a la información de la posición en 0[2]
    */

    // Inicializamos j y b con valores que indican que las posiciones
    //no fueron jugadas ni se marcó una banderita
    int nm = t.size() * t[0].size();
    pos null_pos(-1, -1);
    jugada ju(null_pos, -1);

    for (int i = 0; i < nm; ++i) {
        j.push_back(ju);
        b.push_back(null_pos);
    }
}

/*Modifica el vector jugadas, agregando la posicion jugada -p- y sus minas
 *adyacentes en lugar que corresponde segun la correspondencia con t.*/
void jugar(tablero& t, jugadas& j, pos p) {
    int index = mapIndex(t.size(), p.first, p.second);
    jugada ju(p, minasAdyacentes(t, p));
    j[index] = ju;
}

/*Chequea si la posición (i, k) ya fue jugada para el juego determinado
 *por el tabletro t y el vector de jugadas j.*/
bool posicionJugada(tablero& t, jugadas& j, int i, int k) {
    int index = mapIndex(t.size(), i, k);
    return j[index].second != -1;
}

/*Retorna la cantidad de minas adyacentes a la posición p del
 *tablero t, teniendo en cuenta si ese calculo ya se realizó anteriormente.
 *En caso de haberse realizado, toma dicho valor del vector j.*/
int minasAdyacentesWithCache(tablero& t, jugadas& j, pos p) {
    int index = mapIndex(t.size(), p.first, p.second);
    int c = j[index].second;
    if (c > -1) {
        return c;
    }
    return minasAdyacentes(t, p);
}

/*Chequea si hay una banderita colocada en la posición p del tablero t,
 *comprobando en el vector de banderitas b.*/
bool hayBanderita(tablero& t, banderitas& b, pos p) {
    int index = mapIndex(t.size(), p.first, p.second);
    return b[index].first != -1;
}
