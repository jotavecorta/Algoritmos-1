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

    // Separo la posicion en coordenadas. O(1)
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
/* Complejidad Lineal en b y en j: O(|b|) + O(|b|) + O(1). Para dejar todas las complejidades
 en función de un solo parámetro, recordamos que |b| <= |t|*|t|, por lo tanto en
 el peor caso podemos reemplazar O(|b|) por O(|t|*|t|), por lo que la complejidad
 de cambiarBanderita resulta O(|t|*|t|) + O(|t|*|t|) + O(1) = O(|t|*|t|).*/
void cambiarBanderita(const tablero& t, const jugadas& j, pos p, banderitas& b) {

    // Hace una busqueda lineal sobre banderitas b: O(|b|)
    int indice_banderitas = estaEnBanderitas(t, b, p);

    if (indice_banderitas != -1){// Remueve banderita O(|b|) por la operación erase()
        b.erase(b.begin() + indice_banderitas);
    }else{// Agrega banderita: consideramos a la función push_back como O(1) (aunque puede en algunos casos ser orden lineal)
        b.push_back(p);
    }
}

/******++++**************************** EJERCICIO perdio ***********+++***********************/
// Complejidad Lineal en j: O(|j|) = O(|t|*|t|): Tenemos un solo for en j y dentro todas sentencias O(1)
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
/* Complejidad O(|t|*|t|*|j|) = O(|t|*|t|*|t|*|t|) = O(|t|^4), dado que recorremos todas las filas
 y columnas de t (tablero cuadrado), y para cada una realizamos una busqueda lineal en j.*/
bool gano(const tablero& t, const jugadas& j) {
    // Recorremos filas de t, para cada una columnas y buscamos en j: O(|t|*|t|*|j|) = O(|t|^4).
    for (int i = 0; i < t.size(); i++) {
        // Recorremos columnas de t y para cada una buscamos en j: O(|t|*|j|)
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
/* Complejidad O(|t|*|t|*|j|) + O(|j|) + O(|b|) + O(1) = O(|t|^4): la llamada recursiva hace que sea
 * posible recorrer todo el tablero en el peor de los , y para cada punto se realiza una búsqueda
 * lineal en el vector de jugadas j. */
void jugarPlus(const tablero& t, const banderitas& b, pos p, jugadas& j) {
    // Si hay banderita no se puede jugar: O(|b|) (se agrega por el llamado recursivo)
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
    // que la suma de sus operaciones internas: O(|t|*|t|*|j|) + O(|j|) + O(1) = O(|t|^4)
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
// La complejidad total es O(|t|*|t|*|j|) = O(|t|^4), ya que recorremos filas y columnas de t y para cada elemento buscamos en j.
bool sugerirAutomatico121(const tablero& t, const banderitas& b, const jugadas& j, pos& p) {
    // Operaiciones O(1)
    int iMax = t.size() - 1;
    int kMax = t[0].size() - 1;

    // Recorremos filas de t, para cada una columnas y buscamos en j: O(|t|*|t|*|j|)
    for (int i = 0; i < t.size(); i++) { // Cada loop en t agrega un |t|
        for (int k = 0; k < t[0].size(); k++) {

            // Si la posición no se jugó o no tiene 2 minas adyacentes no nos interesa.
            if (!posicionJugada(t, j, pos(i, k)) || minasAdyacentes(t, pos(i, k)) != 2) {// Buscamos en j: O(|j|)
                continue;
            }

            // Si estamos en una esquina tampoco nos sirve. Operaciones O(1)
            if (
                (i == 0 && k == 0) ||       // Esquina superior izquierda
                (i == 0 && k == kMax) ||    // Esquina superior derecha
                (i == iMax && k == 0) ||    // Esquina inferior izquierda
                (i == iMax && k == kMax)    // Esquina inferior derecha
            ) {
                continue;
            }

            // Si la posición se jugó y tiene dos minas adyacentes: chequeamos si forma una columna 121 o  una fila 121

            // Fila 121. Complejidad: O(2|j|) + O(2|j|) + O(2|b|) + O(1) = O(|j|)
            //                   (if exterior) + (if interior)
            if (// O(|j|) + O(1)
                posicionJugada(t, j, pos(i, k - 1)) && // Izquierda
                minasAdyacentes(t, pos(i, k - 1)) == 1 &&
                posicionJugada(t, j, pos(i, k + 1)) && // Derecha
                minasAdyacentes(t, pos(i, k + 1)) == 1
            ) {
                // Encontramos una fila 121
                // Si la posición de arriba está jugada, devolvemos la de abajo y viceversa
                // Si ninguna de las posiciones de arriba o abajo está jugada, no podemos determinar cuál de las dos es correcta
                if ((!posicionValida(t, i - 1, k) || posicionJugada(t, j, pos(i - 1, k))) && estaEnBanderitas(t, b , pos(i + 1, k)) == -1) {// O(|j|) + O(1)
                    p = pos(i + 1, k);
                    return true;
                } else if (!posicionValida(t, i + 1, k) || posicionJugada(t, j, pos(i + 1, k)) && estaEnBanderitas(t, b , pos(i - 1, k)) == -1) {// O(|j|) + O(1)
                    p = pos(i - 1, k);
                    return true;
                }

                continue;
            }

            // Columna 121. Complejidad O(2|j|) + O(2|j|) + O(2|b|) + O(1) = O(|j|)
            if (// O(|j|) + O(1)
                posicionJugada(t, j, pos(i - 1, k)) && // Arriba
                minasAdyacentes(t, pos(i - 1, k)) == 1 &&
                posicionJugada(t, j, pos(i + 1, k)) && // Abajo
                minasAdyacentes(t, pos(i + 1, k)) == 1
            ) {
                // Encontramos una columna 121
                // Si la posición de la izquierda está jugada, devolvemos la de la derecha y viceversa
                // Si ninguna de las posiciones de la izquierda o derecha está jugada, no podemos determinar cuál de las dos es correcta
                if ((!posicionValida(t, i, k - 1) || posicionJugada(t, j, pos(i, k - 1))) && estaEnBanderitas(t, b , pos(i, k + 1)) == -1) {// O(|j|) + O(1)
                    p = pos(i, k + 1);
                    return true;
                } else if ((!posicionValida(t, i, k + 1) || posicionJugada(t, j, pos(i, k + 1))) && estaEnBanderitas(t, b , pos(i, k - 1)) == -1) {// O(|j|) + O(1)
                    p = pos(i, k - 1);
                    return true;
                }

                continue;
            }
        }
    }

    return false;
}
