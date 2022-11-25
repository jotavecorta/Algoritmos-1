
//
// Este archivo contiene las declaraciones de las funciones auxiliares
// que ustedes necesiten implementar. Tienen que coincidir con el código
// de esas mismas funciones, que estará en auxiliares.cpp
//

#pragma once   // esta línea es para que el archivo se incluya una sola vez

#include "definiciones.h"

int mapIndex(int n, int i, int j);
bool posicionValida(const tablero &t, int i, int j);
void initJB(tablero& t, jugadas& j, banderitas& b);
void jugar(const tablero& t, jugadas& j, pos p);
bool posicionJugada(const tablero& t, const jugadas& j, pos p);
int estaEnBanderitas(const tablero &t, const banderitas &b, pos p);
int minasAdyacentesWithCache(tablero& t, jugadas& j, pos p);
bool hayBanderita(tablero& t, banderitas& b, pos p);