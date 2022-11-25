//
// Este archivo contiene las definiciones de las funciones que implementan los ejercicios
//

#include <stdio.h>
#include <iostream>

#include "definiciones.h"
#include "ejercicios.h"
#include "auxiliares.h"

using namespace std;

/******++++**************************** EJERCICIO minasAdyacentes ***********+++***********************/
// O(1) tiempo constante: Los ciclos recorren 9 posiciones SIEMPRE y todas las operaciones son O(1)
int minasAdyacentes(const tablero& t, pos p) {
    int cant_minas_adyacentes = 0;

    // Separo la posicion en coordenadas
    int p_i = p.first;
    int p_j = p.second;

    // Itero sobre pocisiones adyacentes: Solo recorre 9 posiciones, complejidad cte O(1)
    for (int k = p_i - 1; k < p_i + 2; k++) {
        for (int l = p_j - 1; l < p_j + 2; l++) {

            // Reviso que la posición actual sea válida en el tablero (O(1))
            bool posicion_valida = posicionValida(t, k, l) && (k != p_i || l != p_j);

            if (posicion_valida  && t[k][l]){// O(1)
                // Entra si es posición válida y hay mina.
                cant_minas_adyacentes++; // O(1)

            }
        }
    }
    return cant_minas_adyacentes;
}

/******++++**************************** EJERCICIO cambiararBanderita ***********+++***********************/
// Complejidad Lineal en b: O(|b|) + O(1) = O(|b|)
void cambiarBanderita(const tablero& t, const jugadas& j, pos p, banderitas& b) {
    // Si la posicion esta jugada no se puede plantar.
    if (posicionJugada(t, j, p)) {// Busqueda lineal en j: O(|j|)
        return;
    }

    // Hace una busqueda lineal sobre banderitas O(|b|)
    int indice_banderitas = estaEnBanderitas(t, b, p);

    if (indice_banderitas != -1){// Remueve banderita O (1)
        b.erase(b.begin() + indice_banderitas);
    }else{// Agrega banderita O(1)
        b.push_back(p);
    }
}

/******++++**************************** EJERCICIO perdio ***********+++***********************/
// Complejidad Lineal en j O(|j|): Tenemos un solo for y dentro todas sentencias O(1)
bool perdio(const tablero& t, const jugadas& j) {
    // Chequeamos que haya minas en jugadas. En el peor caso recorremos todo j: O(|j|)
    for(int i = 0; i < j.size(); i++) {
        // Si esa posicion se jugó, miramos si había una mina
        pos p = j[i].first;
        if (t[p.first][p.second]) {
            return true;
        }
    }
    // Si logramos salir del for es porque no había minas en jugadas
    return false;
}

/******++++**************************** EJERCICIO gano ***********+++***********************/
/* Complejidad O(|t|*|t|*|j|) dado que recorremos todas las filas y columnas de t (tablero cuadrado)
*y para cada una realizamos una busqueda lineal en j */
bool gano(const tablero& t, const jugadas& j) {
    // Recorremos filas, para cada una columnas y buscamos en j: O(|t|*|t|*|j|)
    for (int i = 0; i < t.size(); i++) {
        // Recorremos columnas y para cada una buscamos en j: O(|t|*|j|)
        for (int k = 0; k < t[0].size(); ++k) {

            // Nos indica si hay una mina en el casillero
            bool hayMina = t[i][k];
            bool yaLaJugo = posicionJugada(t, j, pos (i, k)); // O(|j|)

            // Si la posición se jugó y hay una mina, perdió. O(1)
            if (hayMina && yaLaJugo) {
                return false;
            }

            // Si no hay una mina y la posición no se jugó, todavía no terminó el juego. O(1)
            if (!hayMina && !yaLaJugo) {
                return false;
            }
        }
    }
    return true;
}

/******++++**************************** EJERCICIO jugarPlus ***********+++***********************/
/* Complejidad O(|t|*|t|): la llamada recursiva hace que sea posible recorrer
 * todo el tablero en el peor de los casos. */
void jugarPlus(const tablero& t, const banderitas& b, pos p, jugadas& j) {
    // Si hay banderita no se puede jugar: O(|b|)
    if (estaEnBanderitas(t, b, p) != -1) {
        return;
    }

    // Agregamos la jugada al array O(1)
    jugar(t, j, p);

    // Si hay una mina o tiene minas adyacentes no hay nada que hacer O(1)
    if (t[p.first][p.second] || minasAdyacentes(t, p) > 0) {
        return;
    }

    // Iteramos recursivamente sobre todas las posiciones adyacentes no jugadas,
    // como la cantidad de posiciones es constante esta operacion es de igual orden
    // que la suma de sus operaciones internas: O(|t|*|t|) + O(|j|) + O(1) = O(|t|*|t|)
    // ya que la cantidad de jugadas es igual o menor que las posiciones del tablero.
    for (int i = 0; i < 9; ++i) {
        int fila = (i / 3) - 1 + p.first;
        int columna = i % 3 - 1 + p.second;

        if (
            fila == p.first && columna == p.second || // Es la misma posición, continuamos con la que sigue O(1)
            !posicionValida(t, fila, columna) || // Si no es posición válida no la procesamos O(1)
            posicionJugada(t, j , pos(fila, columna)) // Verificamos si ya se jugó, lineal en j O(|j|)
        ) {
            continue;
        }

        // Acá llamamos recursivamente a jugarPlus: en el peor caso se debería descubrir todo
        //el tablero -imaginemos un tablero sin minas-, por lo que esta operación llamada sobre
        // si misma debería ser de orden O(|t|*|t|)
        pos siguiente_posicion(fila, columna);
        jugarPlus(t, b, siguiente_posicion, j);
    }
}

///******++++**************************** EJERCICIO sugerirAutomatico121 ***********+++***********************/

//bool sugerirAutomatico121(const tablero& t, const banderitas& b, const jugadas& j, pos& p) {
//    // Las jugadas en los bordes no nos interesan así que recorremos el cuadrado interior del tablero
//
//    int iMax = t.size() - 1;
//    int kMax = t[0].size() - 1;
//    for (int i = 0; i < t.size(); i++) {
//        for (int k = 0; k < t[0].size(); k++) {
//            // O(1)
//            // Si la posición no se jugó o no tiene 2 minas adyacentes no nos interesa
//            if (!posicionJugada(t, j, pos(i, k)) || minasAdyacentes(t, pos(i, k)) != 2) {
//                continue;
//            }
//
//            // Si estamos en una esquina tampoco nos sirve
//            if (
//                (i == 0 && k == 0) ||       // Esquina superior izquierda
//                (i == 0 && k == kMax) ||    // Esquina superior derecha
//                (i == iMax && k == 0) ||    // Esquina inferior izquierda
//                (i == iMax && k == kMax)    // Esquina inferior derecha
//            ) {
//                continue;
//            }
//
//            // Si la posición se jugó y tiene dos minas adyacentes: chequeamos si forma una columna 121 o  una fila 121
//
//            // Fila 121
//            if (
//                posicionJugada(t, j, pos(i, k - 1)) && // Izquierda
//                minasAdyacentes(t, pos(i, k - 1)) == 1 &&
//                posicionJugada(t, j, pos(i, k + 1)) && // Derecha
//                minasAdyacentes(t, pos(i, k + 1)) == 1
//            ) {
//                // Encontramos una fila 121
//                // Si la posición de arriba está jugada, devolvemos la de abajo y viceversa
//                // Si ninguna de las posiciones de arriba o abajo está jugada, no podemos determinar cuál de las dos es correcta
//                HABRIA QUE DEVOLVER FALSE SI NO ES DETERMINABLE
//                if (!posicionValida(t, i - 1, k) || posicionJugada(t, j, pos(i - 1, k))) {
//                    p = pos(i + 1, k);
//                    return true;
//                } else if (!posicionValida(t, i - 1, k) || posicionJugada(t, j, pos(i + 1, k))) {
//                    p = pos(i - 1, k);
//                    return true;
//                }
//
//                continue;
//            }
//
//            // Columna 121
//            if (
//                posicionJugada(t, j, pos(i - 1, k)) && // Arriba
//                minasAdyacentes(t, pos(i - 1, k)) == 1 &&
//                posicionJugada(t, j, pos(i + 1, k)) && // Abajo
//                minasAdyacentes(t, pos(i + 1, k)) == 1
//            ) {
//                // Encontramos una columna 121
//                // Si la posición de la izquierda está jugada, devolvemos la de la derecha y viceversa
//                // Si ninguna de las posiciones de la izquierda o derecha está jugada, no podemos determinar cuál de las dos es correcta
//                 // LO MISMO, FALTA FALSE SI NO SE PUEDE DETERMINAR
//                if (!posicionValida(t, i, k - 1) || posicionJugada(t, j, pos(i, k - 1))) {
//                    p = pos(i, k + 1);
//                    return true;
//                } else if (!posicionValida(t, i, k + 1) || posicionJugada(t, j, pos(i, k + 1))) {
//                    p = pos(i, k - 1);
//                    return true;
//                }
//
//                continue;
//            }
//        }
//    }
//}
