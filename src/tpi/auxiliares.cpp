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
bool pertenece(vector<pos> b, pos p){
  int i=0;
  while(i<b.size() and b[i]!= p){
    i=i+1;
  }
  return i < b.size();
}

bool perteneceEnJugadas(jugada k, jugadas j){
  bool pertenece = false;
  for(int i = 0;i < j.size();i++){
    if(j[i]==k){
      pertenece = true;
    }
  }
  return pertenece;
}

bool es121Horizontal(pos p, jugadas j){
  return perteneceEnJugadas(((p[0],p[1] - 1),1),j) and perteneceEnJugadas(((p[0],p[1]),2),j) and perteneceEnJugadas(((p[0],p[1] + 1),1),j);
}

bool es121Vertical(pos p, jugadas j){
  return perteneceEnJugadas(((p[0] - 1,p[1]),1),j) and perteneceEnJugadas(((p[0],p[1]),2),j) and perteneceEnJugadas(((p[0] + 1,p[1]),1),j);
}

bool esAdyacenteA121(pos p, jugadas j){
  return es121Horizontal((p[0] - 1,p[1]),j) or es121Horizontal((p[0] + 1,p[1]),j) or es121Vertical((p[0],p[1] - 1),j) or es121Vertical((p[0],p[1] + 1),j);
}

bool hayPosicionSugerible(jugadas j, banderitas b, tablero t){
  bool posicionSugerida;
  for(int i = 0;i < j.size();i++){
    if(esPosicionSinJugarYSinBanderita((j[i])[0],j,b,t) and esAdyacenteA121((j[i])[0],j)){
      posicionSugerida = true;
    }
  }
  return posicionSugerida;
}
