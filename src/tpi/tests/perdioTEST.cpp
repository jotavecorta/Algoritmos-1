// Tests para la función perdio.
// Ver el archovo README.md para ayuda

#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

TEST(perdioTest, ConMinaDescubierta){
    // Setup
    tablero T (3, vector<bool>(4, false));
    T[0][3] = T[1][3] = T[2][3] = true;

    jugada j_1 (pos (0,0), minasAdyacentes(T, pos (0, 0)));
    jugada j_2 (pos (0,3), minasAdyacentes(T, pos (0, 3)));

    // Armo un vector con el estado del juego
    vector<pos> posicionesAJugar = {pos (0, 0), pos (0, 3)};

    // Inicializo las jugadas y las banderitas. Coloco las posiciones a jugar
    jugadas J;
    banderitas b;
    initJB(T, J, b);

    //  Coloco las posiciones a jugar
    for (int i = 0; i < posicionesAJugar.size(); ++i) {
        jugar(T, J, posicionesAJugar[i]);
    }

    // Exercise
    bool resultado_juego = perdio(T, J);

    // Check
    ASSERT_TRUE(resultado_juego);
}

TEST(perdioTest, SinMinaDescubierta){
    // Setup
    tablero T (3, vector<bool>(4, false));
    T[0][3] = T[1][3] = T[2][3] = true;

    // Armo un vector con el estado del juego
    vector<pos> posicionesAJugar = {pos (0, 0), pos (0, 2)};

    // Inicializo las jugadas y las banderitas. Coloco las posiciones a jugar
    jugadas J;
    banderitas b;
    initJB(T, J, b);

    //  Coloco las posiciones a jugar
    for (int i = 0; i < posicionesAJugar.size(); ++i) {
        jugar(T, J, posicionesAJugar[i]);
    }

    // Exercise
    bool resultado_juego = perdio(T, J);

    // Check
    ASSERT_FALSE(resultado_juego);
}