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
     0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15

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

bool pertenece(vector<pos> b, pos p) {
  int i=0;
  while(i<b.size() and b[i]!= p){
    i=i+1;
  }
  return i < b.size();
}

bool perteneceEnJugadas(jugada k, jugadas j) {
  bool pertenece = false;
  for(int i = 0;i < j.size();i++){
    if(j[i]==k){
      pertenece = true;
    }
  }
  return pertenece;
}

bool es121Horizontal(pos p, jugadas j){
    // indiceJugadas % m != 0 && indiceJugadas % m != (m - 1)
    // return perteneceEnJugadas(((p.first,p.second - 1),1),j) and perteneceEnJugadas(((p[0],p[1]),2),j) and perteneceEnJugadas(((p[0],p[1] + 1),1),j);
    return true;
}

bool es121Vertical(pos p, jugadas j){
  // return perteneceEnJugadas(((p[0] - 1,p[1]),1),j) and perteneceEnJugadas(((p[0],p[1]),2),j) and perteneceEnJugadas(((p[0] + 1,p[1]),1),j);
    return true;
}

bool esAdyacenteA121(pos p, jugadas j){
  // return es121Horizontal((p[0] - 1,p[1]),j) or es121Horizontal((p[0] + 1,p[1]),j) or es121Vertical((p[0],p[1] - 1),j) or es121Vertical((p[0],p[1] + 1),j);
    return true;
}

bool hayPosicionSugerible(jugadas j, banderitas b, tablero t){
  /*bool posicionSugerida;
  for(int i = 0;i < j.size();i++){
    if(esPosicionSinJugarYSinBanderita((j[i])[0],j,b,t) and esAdyacenteA121((j[i])[0],j)){
      posicionSugerida = true;
    }
  }
  return posicionSugerida;*/
    return true;
}

