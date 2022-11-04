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
bool posicionValida(tablero& t, int i, int j) {
    return (i>=0 && i < t.size()) && (j>=0 && j < t[0].size());
}

int mapIndex(int n, int i, int j) {
    return i*n + j;
}

void initJB(tablero& t, jugadas& j, banderitas& b) {
    // Ya está inicializado
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

    // Inicializamos el vector
    int nm = t.size() * t[0].size();
    pos null_pos(-1, -1);
    jugada ju(null_pos, -1);

    for (int i = 0; i < nm; ++i) {
        j.push_back(ju);
        b.push_back(null_pos);
    }
}

void jugar(tablero& t, jugadas& j, pos p) {
    int index = mapIndex(t.size(), p.first, p.second);
    jugada ju(p, minasAdyacentes(t, p));
    j[index] = ju;
}

bool posicionJugada(tablero& t, jugadas& j, int i, int k) {
    int index = mapIndex(t.size(), i, k);
    return j[index].second != -1;
}

int minasAdyacentesWithCache(tablero& t, jugadas& j, pos p) {
    int index = mapIndex(t.size(), p.first, p.second);
    int c = j[index].second;
    if (c > -1) {
        return c;
    }
    return minasAdyacentes(t, p);
}

bool hayBanderita(tablero& t, banderitas& b, pos p) {
    int index = mapIndex(t.size(), p.first, p.second);
    return b[index].first != -1;
}
