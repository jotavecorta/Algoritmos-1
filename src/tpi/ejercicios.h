//
// Este archivo contiene las declaraciones de las funciones (no el código).
// Tienen que coincidir exactamente con el código que se encuentra en ejercicios.cpp
//

#pragma once   // esta línea es para que el archivo se incluya una sola vez

#include "definiciones.h"

int minasAdyacentes(const tablero& t, pos p);
void cambiarBanderita(const tablero& t, const jugadas& j, pos p, banderitas& b);
bool perdio(const tablero& t, const jugadas& j);
bool gano(const tablero& t, const jugadas& j);
void jugarPlus(const tablero& t, const banderitas& b, pos p, jugadas& j);
bool sugerirAutomatico121(const tablero& t, const banderitas& b, const jugadas& j, pos& p);
