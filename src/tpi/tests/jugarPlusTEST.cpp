// Tests para la función jugarPlus.
// Ver el archovo README.md para ayuda

#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

TEST(jugarPlusTest, siNoHayMinasDescubrePosicionesCorrectamente){
    // Setup
    tablero t = {
            { cMINA,  cMINA,  cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cMINA,  cVACIA },
            { cVACIA, cMINA,  cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
            { cMINA,  cVACIA, cMINA,  cVACIA, cVACIA },
    };

    banderitas b;
    jugadas j;

    // Excersice
    pos p(3, 4);
    jugarPlus(t, b, p, j);

    // Check
    // Fila 1
    ASSERT_TRUE(!posicionJugada(t, j, pos(0, 0)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(0, 1)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(0, 2)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(0, 3)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(0, 4)));

    // Fila 2
    ASSERT_TRUE(!posicionJugada(t, j, pos(1, 0)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(1, 1)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(1, 2)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(1, 3)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(1, 4)));

    // Fila 3 Columnas 4 y 5 SI
    ASSERT_TRUE(!posicionJugada(t, j, pos(2, 0)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(2, 1)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(2, 2)));
    ASSERT_TRUE(posicionJugada(t, j, pos(2, 3)));
    ASSERT_TRUE(posicionJugada(t, j, pos(2, 4)));

    // Fila 4 Columnas 4 y 5 SI
    ASSERT_TRUE(!posicionJugada(t, j, pos(3, 0)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(3, 1)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(3, 2)));
    ASSERT_TRUE(posicionJugada(t, j, pos(3, 3)));
    ASSERT_TRUE(posicionJugada(t, j, pos(3, 4)));

    // Fila 5 Columnas 4 y 5 SI
    ASSERT_TRUE(!posicionJugada(t, j, pos(4, 0)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(4, 1)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(4, 2)));
    ASSERT_TRUE(posicionJugada(t, j, pos(4, 3)));
    ASSERT_TRUE(posicionJugada(t, j, pos(4, 4)));
}

TEST(jugarPlusTest, noDescubrePosicionesConBanderita){
    // Setup
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

    // Excercise
    cambiarBanderita(t, j, banderita, b);
    jugarPlus(t, b, p, j);

    // Check
    // Fila 1
    ASSERT_TRUE(!posicionJugada(t, j, pos(0, 0)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(0, 1)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(0, 2)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(0, 3)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(0, 4)));

    // Fila 2pos()
    ASSERT_TRUE(!posicionJugada(t, j, pos(1, 0)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(1, 1)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(1, 2)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(1, 3)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(1, 4)));

    // Fila 3 Columnas 5 SI
    ASSERT_TRUE(!posicionJugada(t, j, pos(2, 0)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(2, 1)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(2, 2)));
    ASSERT_TRUE(posicionJugada(t, j, pos(2, 3)));
    ASSERT_TRUE(posicionJugada(t, j, pos(2, 4)));

    // Fila 4 Columnas 4 y 5 SI
    ASSERT_TRUE(!posicionJugada(t, j, pos(3, 0)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(3, 1)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(3, 2)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(3, 3)));
    ASSERT_TRUE(posicionJugada(t, j, pos(3, 4)));

    // Fila 5 Columnas 4 y 5 SI
    ASSERT_TRUE(!posicionJugada(t, j, pos(4, 0)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(4, 1)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(4, 2)));
    ASSERT_TRUE(posicionJugada(t, j, pos(4, 3)));
    ASSERT_TRUE(posicionJugada(t, j, pos(4, 4)));
}

TEST(jugarPlusTest, noDescubrePosicionesSiHayMinasAdyacentes){
    // Setup
    tablero t = {
            { cMINA,  cMINA,  cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cMINA,  cVACIA },
            { cVACIA, cMINA,  cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
            { cMINA,  cVACIA, cMINA,  cVACIA, cVACIA },
    };

    banderitas b;
    jugadas j;

    // Excercise
    pos p(2, 2);
    jugarPlus(t, b, p, j);

    // Check
    // Fila 1
    ASSERT_TRUE(!posicionJugada(t, j, pos(0, 0)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(0, 1)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(0, 2)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(0, 3)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(0, 4)));

    // Fila 2pos(
    ASSERT_TRUE(!posicionJugada(t, j, pos(1, 0)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(1, 1)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(1, 2)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(1, 3)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(1, 4)));

    // Fila 3pos(
    ASSERT_TRUE(!posicionJugada(t, j, pos(2, 0)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(2, 1)));
    ASSERT_TRUE(posicionJugada(t, j, pos(2, 2)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(2, 3)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(2, 4)));

    // Fila 4pos(
    ASSERT_TRUE(!posicionJugada(t, j, pos(3, 0)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(3, 1)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(3, 2)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(3, 3)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(3, 4)));

    // Fila 5 Columnas
    ASSERT_TRUE(!posicionJugada(t, j, pos(4, 0)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(4, 1)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(4, 2)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(4, 3)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(4, 4)));
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
    ASSERT_TRUE(!posicionJugada(t, j, pos(0, 0)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(0, 1)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(0, 2)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(0, 3)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(0, 4)));

    // Fila 2
    ASSERT_TRUE(!posicionJugada(t, j, pos(1, 0)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(1, 1)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(1, 2)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(1, 3)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(1, 4)));

    // Fila 3
    ASSERT_TRUE(!posicionJugada(t, j, pos(2, 0)));
    ASSERT_TRUE(posicionJugada(t, j,  pos(2, 1)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(2, 2)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(2, 3)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(2, 4)));

    // Fila 4
    ASSERT_TRUE(!posicionJugada(t, j, pos(3, 0)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(3, 1)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(3, 2)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(3, 3)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(3, 4)));

    // Fila 5
    ASSERT_TRUE(!posicionJugada(t, j, pos(4, 0)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(4, 1)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(4, 2)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(4, 3)));
    ASSERT_TRUE(!posicionJugada(t, j, pos(4, 4)));
}

