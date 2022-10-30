// Tests para la función cambiarBanderita.
// Ver el archovo README.md para ayuda


#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

TEST(cambiarBanteritaTest, SinBanderitaEnPosicion){
    // Setup
    tablero T (5, vector<bool>(5, false));
    T[0][4] = T[1][3] = T[2][3] = T[4][0] = T[3][1]= true;

    jugada j_1 (pos (0,0), minasAdyacentes(T, pos (0, 0)));
    jugada j_2 (pos (0,1), minasAdyacentes(T, pos (0, 1)));

    jugadas J = {j_1, j_2};

    banderitas b = {pos (0, 4)};

    pos posicion_sospechosa (1, 3);

    // Exercise
    cambiarBanderita(T, J, posicion_sospechosa, b);

    // Check
    banderitas valor_esperado = {pos (0, 4), pos (1, 3)};
    ASSERT_EQ(b, valor_esperado);

}

