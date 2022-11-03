// Tests para la función gano.
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


TEST(ganoTEST, todaviaNoGano){
    tablero T = {
            { cMINA,  cMINA,  cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cMINA,  cVACIA },
            { cVACIA, cMINA,  cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
            { cMINA,  cVACIA, cMINA,  cVACIA, cVACIA },
    };

    vector<pos> posicionesAJugar = {
            pos(0, 2), pos(0, 4),
            pos(1, 0), pos(1, 1), pos(1, 2), pos(1, 4),
            pos(2, 0), pos(2, 2), pos(2, 3), pos(2, 4),
            pos(3, 0), pos(3, 1), pos(3, 2), pos(3, 3),
            pos(4, 1), pos(4, 3), pos(4, 4),
    };

    // Inicializo las jugadas y las banderitas. Coloco las posiciones a jugar
    jugadas J;
    banderitas b;
    initJB(T, J, b);

    //  Coloco las posiciones a jugar
    for (int i = 0; i < posicionesAJugar.size(); ++i) {
        jugar(T, J, posicionesAJugar[i]);
    }

    ASSERT_FALSE(gano(T, J));
}

TEST(ganoTEST, yaGano){
    tablero T = {
            { cMINA,  cMINA,  cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cMINA,  cVACIA },
            { cVACIA, cMINA,  cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
            { cMINA,  cVACIA, cMINA,  cVACIA, cVACIA },
    };

    vector<pos> posicionesAJugar = {
            pos(0, 2), pos(0, 3), pos(0, 4),
            pos(1, 0), pos(1, 1), pos(1, 2), pos(1, 4),
            pos(2, 0), pos(2, 2), pos(2, 3), pos(2, 4),
            pos(3, 0), pos(3, 1), pos(3, 2), pos(3, 3), pos(3, 4),
            pos(4, 1), pos(4, 3), pos(4, 4),
    };

    // Inicializo las jugadas y las banderitas. Coloco las posiciones a jugar
    jugadas J;
    banderitas b;
    initJB(T, J, b);

    //  Coloco las posiciones a jugar
    for (int i = 0; i < posicionesAJugar.size(); ++i) {
        jugar(T, J, posicionesAJugar[i]);
    }

    ASSERT_TRUE(gano(T, J));
}