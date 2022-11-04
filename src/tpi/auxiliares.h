
//
// Este archivo contiene las declaraciones de las funciones auxiliares
// que ustedes necesiten implementar. Tienen que coincidir con el código
// de esas mismas funciones, que estará en auxiliares.cpp
//

#pragma once   // esta línea es para que el archivo se incluya una sola vez

#include "definiciones.h"

int mapIndex(int n, int i, int j);
bool posicionValida(tablero& t, int i, int j);
void initJB(tablero& t, jugadas& j, banderitas& b);
void jugar(tablero& t, jugadas& j, pos p);
bool posicionJugada(tablero& t, jugadas& j, int i, int k);
int minasAdyacentesWithCache(tablero& t, jugadas& j, pos p);
bool hayBanderita(tablero& t, banderitas& b, pos p);

bool es121HorizontalArriba(int i,jugadas &j,tablero &t);
bool es121HorizontalAbajo(int i,jugadas &j,tablero &t);
bool es121VerticalDerecha(int i,jugadas &j, tablero &t);
bool es121VerticalIzquierda(int i,jugadas &j, tablero &t);
bool esAdyacenteA121(int i, jugadas &j, tablero &t);
bool hayPosicionSugerible(jugadas &j, banderitas &b, tablero &t,pos &p);