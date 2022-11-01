// Tests para la función jugarPlus.
// Ver el archovo README.md para ayuda

#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

// ┌───┬───┬───┬───┬───┐
// │ * │ * │ 2 │ 1 │ 1 │
// ├───┼───┼───┼───┼───┤
// │ 3 │ 3 │ 3 │ * │ 1 │
// ├───┼───┼───┼───┼───┤
// │ 1 │ * │ 2 │ 1 │ 1 │
// ├───┼───┼───┼───┼───┤
// │ 2 │ 3 │ 2 │ 1 │ 0 │
// ├───┼───┼───┼───┼───┤
// │ * │ 2 │ * │ 1 │ 0 │
// └───┴───┴───┴───┴───┘


TEST(jugarPlusTest, siNoHayMinasDescubrePosicionesCorrectamente){
    tablero t = {
            { cMINA,  cMINA,  cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cMINA,  cVACIA },
            { cVACIA, cMINA,  cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
            { cMINA,  cVACIA, cMINA,  cVACIA, cVACIA },
    };

    banderitas b;
    jugadas j;

    pos p(3, 4);
    jugarPlus(t, b, p, j);

    // Fila 1
    ASSERT_TRUE(!posicionJugada(t, j, 0, 0));
    ASSERT_TRUE(!posicionJugada(t, j, 0, 1));
    ASSERT_TRUE(!posicionJugada(t, j, 0, 2));
    ASSERT_TRUE(!posicionJugada(t, j, 0, 3));
    ASSERT_TRUE(!posicionJugada(t, j, 0, 4));

    // Fila 2
    ASSERT_TRUE(!posicionJugada(t, j, 1, 0));
    ASSERT_TRUE(!posicionJugada(t, j, 1, 1));
    ASSERT_TRUE(!posicionJugada(t, j, 1, 2));
    ASSERT_TRUE(!posicionJugada(t, j, 1, 3));
    ASSERT_TRUE(!posicionJugada(t, j, 1, 4));

    // Fila 3 Columnas 4 y 5 SI
    ASSERT_TRUE(!posicionJugada(t, j, 2, 0));
    ASSERT_TRUE(!posicionJugada(t, j, 2, 1));
    ASSERT_TRUE(!posicionJugada(t, j, 2, 2));
    ASSERT_TRUE(posicionJugada(t, j, 2, 3));
    ASSERT_TRUE(posicionJugada(t, j, 2, 4));

    // Fila 4 Columnas 4 y 5 SI
    ASSERT_TRUE(!posicionJugada(t, j, 3, 0));
    ASSERT_TRUE(!posicionJugada(t, j, 3, 1));
    ASSERT_TRUE(!posicionJugada(t, j, 3, 2));
    ASSERT_TRUE(posicionJugada(t, j, 3, 3));
    ASSERT_TRUE(posicionJugada(t, j, 3, 4));

    // Fila 5 Columnas 4 y 5 SI
    ASSERT_TRUE(!posicionJugada(t, j, 4, 0));
    ASSERT_TRUE(!posicionJugada(t, j, 4, 1));
    ASSERT_TRUE(!posicionJugada(t, j, 4, 2));
    ASSERT_TRUE(posicionJugada(t, j, 4, 3));
    ASSERT_TRUE(posicionJugada(t, j, 4, 4));
}

TEST(jugarPlusTest, noDescubrePosicionesConBanderita){
    tablero t = {
            { cMINA,  cMINA,  cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cMINA,  cVACIA },
            { cVACIA, cMINA,  cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
            { cMINA,  cVACIA, cMINA,  cVACIA, cVACIA },
    };

    banderitas b;
    jugadas j;

    pos p(3, 4);
    pos banderita(3, 3);
    cambiarBanderita(t, j, banderita, b);
    jugarPlus(t, b, p, j);

    // Fila 1
    ASSERT_TRUE(!posicionJugada(t, j, 0, 0));
    ASSERT_TRUE(!posicionJugada(t, j, 0, 1));
    ASSERT_TRUE(!posicionJugada(t, j, 0, 2));
    ASSERT_TRUE(!posicionJugada(t, j, 0, 3));
    ASSERT_TRUE(!posicionJugada(t, j, 0, 4));

    // Fila 2
    ASSERT_TRUE(!posicionJugada(t, j, 1, 0));
    ASSERT_TRUE(!posicionJugada(t, j, 1, 1));
    ASSERT_TRUE(!posicionJugada(t, j, 1, 2));
    ASSERT_TRUE(!posicionJugada(t, j, 1, 3));
    ASSERT_TRUE(!posicionJugada(t, j, 1, 4));

    // Fila 3 Columnas 5 SI
    ASSERT_TRUE(!posicionJugada(t, j, 2, 0));
    ASSERT_TRUE(!posicionJugada(t, j, 2, 1));
    ASSERT_TRUE(!posicionJugada(t, j, 2, 2));
    ASSERT_TRUE(!posicionJugada(t, j, 2, 3));
    ASSERT_TRUE(posicionJugada(t, j, 2, 4));

    // Fila 4 Columnas 4 y 5 SI
    ASSERT_TRUE(!posicionJugada(t, j, 3, 0));
    ASSERT_TRUE(!posicionJugada(t, j, 3, 1));
    ASSERT_TRUE(!posicionJugada(t, j, 3, 2));
    ASSERT_TRUE(posicionJugada(t, j, 3, 3));
    ASSERT_TRUE(posicionJugada(t, j, 3, 4));

    // Fila 5 Columnas 4 y 5 SI
    ASSERT_TRUE(!posicionJugada(t, j, 4, 0));
    ASSERT_TRUE(!posicionJugada(t, j, 4, 1));
    ASSERT_TRUE(!posicionJugada(t, j, 4, 2));
    ASSERT_TRUE(posicionJugada(t, j, 4, 3));
    ASSERT_TRUE(posicionJugada(t, j, 4, 4));
}

TEST(jugarPlusTest, noDescubrePosicionesSiHayMinasAdyacentes){
    tablero t = {
            { cMINA,  cMINA,  cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cMINA,  cVACIA },
            { cVACIA, cMINA,  cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
            { cMINA,  cVACIA, cMINA,  cVACIA, cVACIA },
    };

    banderitas b;
    jugadas j;

    pos p(2, 2);
    jugarPlus(t, b, p, j);

    // Fila 1
    ASSERT_TRUE(!posicionJugada(t, j, 0, 0));
    ASSERT_TRUE(!posicionJugada(t, j, 0, 1));
    ASSERT_TRUE(!posicionJugada(t, j, 0, 2));
    ASSERT_TRUE(!posicionJugada(t, j, 0, 3));
    ASSERT_TRUE(!posicionJugada(t, j, 0, 4));

    // Fila 2
    ASSERT_TRUE(!posicionJugada(t, j, 1, 0));
    ASSERT_TRUE(!posicionJugada(t, j, 1, 1));
    ASSERT_TRUE(!posicionJugada(t, j, 1, 2));
    ASSERT_TRUE(!posicionJugada(t, j, 1, 3));
    ASSERT_TRUE(!posicionJugada(t, j, 1, 4));

    // Fila 3
    ASSERT_TRUE(!posicionJugada(t, j, 2, 0));
    ASSERT_TRUE(!posicionJugada(t, j, 2, 1));
    ASSERT_TRUE(posicionJugada(t, j, 2, 2));
    ASSERT_TRUE(!posicionJugada(t, j, 2, 3));
    ASSERT_TRUE(!posicionJugada(t, j, 2, 4));

    // Fila 4
    ASSERT_TRUE(!posicionJugada(t, j, 3, 0));
    ASSERT_TRUE(!posicionJugada(t, j, 3, 1));
    ASSERT_TRUE(!posicionJugada(t, j, 3, 2));
    ASSERT_TRUE(!posicionJugada(t, j, 3, 3));
    ASSERT_TRUE(!posicionJugada(t, j, 3, 4));

    // Fila 5 Columnas
    ASSERT_TRUE(!posicionJugada(t, j, 4, 0));
    ASSERT_TRUE(!posicionJugada(t, j, 4, 1));
    ASSERT_TRUE(!posicionJugada(t, j, 4, 2));
    ASSERT_TRUE(!posicionJugada(t, j, 4, 3));
    ASSERT_TRUE(!posicionJugada(t, j, 4, 4));
}

TEST(jugarPlusTest, noDescubrePosicionesSiHayUnaMina){
    tablero t = {
            { cMINA,  cMINA,  cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cMINA,  cVACIA },
            { cVACIA, cMINA,  cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
            { cMINA,  cVACIA, cMINA,  cVACIA, cVACIA },
    };

    banderitas b;
    jugadas j;

    pos p(2, 1);
    jugarPlus(t, b, p, j);

    // Fila 1
    ASSERT_TRUE(!posicionJugada(t, j, 0, 0));
    ASSERT_TRUE(!posicionJugada(t, j, 0, 1));
    ASSERT_TRUE(!posicionJugada(t, j, 0, 2));
    ASSERT_TRUE(!posicionJugada(t, j, 0, 3));
    ASSERT_TRUE(!posicionJugada(t, j, 0, 4));

    // Fila 2
    ASSERT_TRUE(!posicionJugada(t, j, 1, 0));
    ASSERT_TRUE(!posicionJugada(t, j, 1, 1));
    ASSERT_TRUE(!posicionJugada(t, j, 1, 2));
    ASSERT_TRUE(!posicionJugada(t, j, 1, 3));
    ASSERT_TRUE(!posicionJugada(t, j, 1, 4));

    // Fila 3
    ASSERT_TRUE(!posicionJugada(t, j, 2, 0));
    ASSERT_TRUE(posicionJugada(t, j, 2, 1));
    ASSERT_TRUE(!posicionJugada(t, j, 2, 2));
    ASSERT_TRUE(!posicionJugada(t, j, 2, 3));
    ASSERT_TRUE(!posicionJugada(t, j, 2, 4));

    // Fila 4
    ASSERT_TRUE(!posicionJugada(t, j, 3, 0));
    ASSERT_TRUE(!posicionJugada(t, j, 3, 1));
    ASSERT_TRUE(!posicionJugada(t, j, 3, 2));
    ASSERT_TRUE(!posicionJugada(t, j, 3, 3));
    ASSERT_TRUE(!posicionJugada(t, j, 3, 4));

    // Fila 5
    ASSERT_TRUE(!posicionJugada(t, j, 4, 0));
    ASSERT_TRUE(!posicionJugada(t, j, 4, 1));
    ASSERT_TRUE(!posicionJugada(t, j, 4, 2));
    ASSERT_TRUE(!posicionJugada(t, j, 4, 3));
    ASSERT_TRUE(!posicionJugada(t, j, 4, 4));
}

