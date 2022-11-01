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
