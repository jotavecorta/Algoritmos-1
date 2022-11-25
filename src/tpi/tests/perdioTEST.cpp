// Tests para la función perdio.
// Ver el archovo README.md para ayuda

#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

TEST(perdioTest, ConMinaDescubierta){
    // Setup
    tablero T = {
            { cVACIA,  cMINA,  cVACIA },
            { cVACIA, cVACIA, cMINA },
            { cVACIA, cVACIA, cMINA },
    };

    jugada j_1 (pos (0,0), minasAdyacentes(T, pos (0, 0)));
    jugada j_2 (pos (1,2), minasAdyacentes(T, pos (1, 2)));

    jugadas j = {j_1, j_2};

    // Exercise
    bool resultado_juego = perdio(T, j);

    // Check
    ASSERT_TRUE(resultado_juego);
}

TEST(perdioTest, SinMinaDescubierta){
    // Setup
    tablero T = {
            { cVACIA,  cMINA,  cVACIA },
            { cVACIA, cVACIA, cMINA },
            { cVACIA, cVACIA, cMINA },
    };

    jugada j_1 (pos (0,0), minasAdyacentes(T, pos (0, 0)));
    jugada j_2 (pos (0,2), minasAdyacentes(T, pos (0, 2)));

    jugadas j = {j_1, j_2};

    // Exercise
    bool resultado_juego = perdio(T, j);

    // Check
    ASSERT_FALSE(resultado_juego);
}