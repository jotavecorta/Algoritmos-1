//
// Este archivo contiene las definiciones de las funciones que implementan los ejercicios
//

#include <stdio.h>
#include <iostream>
#include <algorithm>


#include "definiciones.h"
#include "ejercicios.h"
#include "auxiliares.h"

using namespace std;

/******++++**************************** EJERCICIO minasAdyacentes ***********+++***********************/

int minasAdyacentes(const tablero& t, pos p) {
    int cant_minas_adyacentes = 0;

    // Guardo el tamaño del tablero para verificar validez
    int filas = t.size();
    int columnas = t[0].size();

    // Separo la posicion en coordenadas
    int p_i = p.first;
    int p_j = p.second;

    // Itero sobre pocisiones adyacentes
    for (int k = p_i - 1; k < p_i + 2; k++) {
        for (int l = p_j - 1; l < p_j + 2; l++) {

            // Reviso que la posición sea válida en el tablero
            bool posicion_valida = (k>=0 && k < filas) && (l>=0 && l < columnas) && (k != p_i || l != p_j);

            if (posicion_valida  && t[k][l]){
                // Entra si es posición válida y hay mina en (k, l)
                cant_minas_adyacentes++;

            }
        }
    }
    return cant_minas_adyacentes;
}

/******++++**************************** EJERCICIO plantarBanderita ***********+++***********************/

void cambiarBanderita(tablero& t, jugadas& j, pos p, banderitas& b) {
    // Primera version: No chequea absolutamente nada... MEJORAR
    // Además dudo que nos dejen usar find, remove y erase. IMPLEMENTAR FUNCION AUXILIAR DE BUSQUEDA
    if (find(b.begin(), b.end(), p) == b.end()){
        b.push_back(p);
    }else{
        b.erase(remove(b.begin(), b.end(), p), b.end());
    }
}

/******++++**************************** EJERCICIO perdio ***********+++***********************/
bool perdio(tablero& t, jugadas& j) {
    bool res = false;
    for (int i = 0; i < j.size(); i++) {
        pos p = j[i].first;
        res = res || t[p.first][p.second];
    }
    return res;
}

/******++++**************************** EJERCICIO gano ***********+++***********************/
bool gano(tablero& t, jugadas& j) {
    // ...
}

/******++++**************************** EJERCICIO jugarPlus ***********+++***********************/
void jugarPlus(tablero& t, banderitas& b, pos p, jugadas& j) {
    // ...
}

/******++++**************************** EJERCICIO sugerirAutomatico121 ***********+++***********************/
bool sugerirAutomatico121(tablero& t, banderitas& b, jugadas& j, pos& p) {
    // ...
}
