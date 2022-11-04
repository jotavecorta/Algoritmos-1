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
pos inversaMapIndex(int i, int t){
    return pos(i/t,i%t);
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
     0   1  2  3  4  5  6  7  8  9  10 11 12 13 14 15
     -1 -1  1 -1 -1 -1  2 -1 -1 -1  1  -1 -1 -1 -1 -1

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


bool es121HorizontalArriba(int u,jugadas &j, tablero &t){
    bool esHor121 = false;
    for(int i = t.size()+1;i < t.size()*t.size()-1;i++){
        bool enRango = false;
        int a = 1;
        while(a<t.size()){
            enRango = a*t.size()+1<i and i<(a+1)*t.size()-1;
            a = a+1;
            if(enRango){
                break;
            }
        }
        if(enRango){
            bool esPosicionNoJugada = (j[i].second == -1);
            bool condicion1 = j[i - t.size() - 1].second == 1;
            bool condicion2 = (i - t.size()) % t.size() != 0 and j[i - t.size()].second == 2;
            bool condicion3 = (i - t.size() + 1) % t.size() != 0 and j[i - t.size() + 1].second == 1;
            if( esPosicionNoJugada and condicion1  and condicion2 and condicion3 and i==u){
                esHor121 = true;
            }
        }
    }
    return esHor121;
}
bool es121HorizontalAbajo(int u,jugadas &j, tablero &t){
    bool esHor121 = false;
    for(int i = 1;i <t.size()*t.size() - t.size() - 1;i++){
        bool enRango = false;
        int a = 0;
        while(a<t.size()-1){
            enRango = a*t.size()+1<i and i<(a+1)*t.size()-1;
            a = a+1;
            if(enRango){
                break;
            }
        }
        if(enRango){
            bool esPosicionNoJugada = (j[i].second == -1);
            bool condicion1 = j[i + t.size() - 1].second == 1;
            bool condicion2 = (i) % t.size() != 0 and j[i + t.size()].second == 2;
            bool condicion3 = (i + 1) % t.size() != 0 and j[i + t.size() + 1].second == 1;
            if( esPosicionNoJugada and condicion1  and condicion2 and condicion3 and i==u){
                esHor121 = true;
            }
        }
    }
    return esHor121;
}

bool es121VerticalDerecha(int u,jugadas &j,tablero &t){
    bool esVer121 = false;
    for(int i = t.size() +1;i<t.size()*t.size() - t.size() - 1;i++){
        bool enRango = false;
        int a = 1;
        while(a<t.size()-1){
            enRango = a*t.size()-1<i and i<(a+1)*t.size()-1;
            a = a+1;
            if(enRango){
                break;
            }
        }
        if(enRango){
            bool esPosicionNoJugada = (j[i].second == -1);
            bool condicion1 = j[i - t.size()+1].second == 1;
            bool condicion2 = j[i+1].second == 2;
            bool condicion3 = j[i + t.size()+1].second == 1;
            if(esPosicionNoJugada and condicion1 and condicion2  and condicion3 and i==u){
                esVer121 = true;
            }
        }
    }
    return esVer121;
}

bool es121VerticalIzquierda(int u,jugadas &j,tablero &t){
    bool esVer121 = false;
    for(int i = t.size()+1;i<t.size()*t.size() - t.size();i++){
        bool enRango = false;
        int a = 1;
        while(a<t.size()-1){
            enRango = a*t.size()+1<i and i<(a+1)*t.size();
            a = a+1;
            if(enRango){
                break;
            }
        }
        if(enRango){
            bool esPosicionNoJugada = (j[i].second == -1);
            bool condicion1 = j[i - t.size()-1].second == 1;
            bool condicion2 = j[i-1].second == 2;
            bool condicion3 = j[i + t.size()-1].second == 1;
            if(esPosicionNoJugada and condicion1 and condicion2  and condicion3 and i==u){
                esVer121 = true;
            }
        }
    }
    return esVer121;
}

bool esAdyacenteA121(int i,jugadas &j,tablero &t){
    return es121HorizontalArriba(i,j,t) or es121HorizontalAbajo(i,j,t) or es121VerticalDerecha(i, j,t) or es121VerticalIzquierda(i, j,t);
}

bool hayPosicionSugerible(jugadas &j, banderitas &b, tablero &t, pos &p){
    for(int i = 0; i < j.size(); i++){
        if(j[i].second == -1 && !hayBanderita(t, b, b[i]) && esAdyacenteA121(i,j,t)){
            p = inversaMapIndex(i,t.size());
            return true;
        }
    }
    return false;
}

