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
bool posicionValida(const tablero &t, int i, int j) {
    // Operaciones constantes: no hay ningun loop O(1)
    return (i>=0 && i < t.size()) && (j>=0 && j < t[0].size());
}

/*Modifica el vector jugadas, agregando la posicion jugada -p- y sus minas
 *adyacentes al final del vector de jugadas j. Está compuesta de operaciones
 * O(1) -tanto minasAdyacentes como agregar un elemento al final de un vector-.*/
void jugar(const tablero& t, jugadas& j, pos p) {
    // Armo la jugada y la agrego a j
    jugada jugada_actual(p, minasAdyacentes(t, p));
    j.push_back(jugada_actual);
}

/*Chequea si la posición p ya fue jugada para el juego determinado
 *por el tabletro t y el vector de jugadas j, para ello implementa un
 *algoritmo de busqueda lineal. Complejidad lineal en j: O(|j|)*/
bool posicionJugada(const tablero& t, const jugadas& j, pos p) {
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
int estaEnBanderitas(const tablero &t, const banderitas &b, pos p) {
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