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

    jugadas J = {j_1, j_2};

    // Exercise
    bool resultado_juego = perdio(T, J);

    // Check
    ASSERT_TRUE(resultado_juego);

}

TEST(perdioTest, SinMinaDescubierta){
    // Setup
    tablero T (3, vector<bool>(4, false));
    T[0][3] = T[1][3] = T[2][3] = true;

    jugada j_1 (pos (0,0), minasAdyacentes(T, pos (0, 0)));
    jugada j_2 (pos (0,2), minasAdyacentes(T, pos (0, 2)));

    jugadas J = {j_1, j_2};

    // Exercise
    bool resultado_juego = perdio(T, J);

    // Check
    ASSERT_FALSE(resultado_juego);

}