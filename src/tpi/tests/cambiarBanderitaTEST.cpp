// Tests para la función cambiarBanderita.
// Ver el archovo README.md para ayuda


#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

TEST(cambiarBanteritaTest, SinBanderitaEnPosicion){
    //// Setup
    // Estado actual del juego
    tablero T = {
            { cVACIA,  cVACIA,  cVACIA, cVACIA, cMINA },
            { cVACIA, cVACIA, cVACIA, cMINA,  cVACIA },
            { cVACIA, cVACIA,  cVACIA, cMINA, cVACIA },
            { cVACIA, cMINA, cVACIA, cVACIA, cVACIA },
            { cMINA,  cVACIA, cMINA,  cVACIA, cVACIA },
    };

    banderitas b = {pos (0, 4), pos (1, 2), pos (1, 3)};

    jugadas j = {jugada (pos (0,0), minasAdyacentes(T, pos (0,0))),
                 jugada (pos (2,1), minasAdyacentes(T, pos (2,1)))};

    // Banderita a agregar
    pos banderita_nueva (4, 0);


    //// Excersice
    cambiarBanderita(T, j, banderita_nueva, b);


    //// Check
    banderitas valor_esperado = {pos (0, 4), pos (1, 2), pos (1, 3), banderita_nueva};

    ASSERT_EQ(b, valor_esperado);

}

TEST(cambiarBanteritaTest, ConBanderitaEnPosicion){
    //// Setup
    // Estado actual del juego
    tablero T = {
            { cVACIA,  cVACIA,  cVACIA, cVACIA, cMINA },
            { cVACIA, cVACIA, cVACIA, cMINA,  cVACIA },
            { cVACIA, cVACIA,  cVACIA, cMINA, cVACIA },
            { cVACIA, cMINA, cVACIA, cVACIA, cVACIA },
            { cMINA,  cVACIA, cMINA,  cVACIA, cVACIA },
    };

    banderitas b = {pos (0, 4), pos (1, 2), pos (1, 3)};

    jugadas j = {jugada (pos (0,0), minasAdyacentes(T, pos (0,0))),
                 jugada (pos (2,1), minasAdyacentes(T, pos (2,1)))};

    // Banderita a agregar
    pos banderita_existente (1, 2);


    //// Excersice
    cambiarBanderita(T, j, banderita_existente, b);


    //// Check
    banderitas valor_esperado = {pos (0, 4), pos (1, 3)};
    ASSERT_EQ(b, valor_esperado);
}


TEST(cambiarBanteritaTest, posicionYaJugada){
    //// Setup
    // Estado actual del juego
    tablero T = {
            { cVACIA,  cVACIA,  cVACIA, cVACIA, cMINA },
            { cVACIA, cVACIA, cVACIA, cMINA,  cVACIA },
            { cVACIA, cVACIA,  cVACIA, cMINA, cVACIA },
            { cVACIA, cMINA, cVACIA, cVACIA, cVACIA },
            { cMINA,  cVACIA, cMINA,  cVACIA, cVACIA },
    };

    banderitas b = {pos (0, 4), pos (1, 2), pos (1, 3)};

    jugadas j = {jugada (pos (0,0), minasAdyacentes(T, pos (0,0))),
                 jugada (pos (2,1), minasAdyacentes(T, pos (2,1)))};

    // Banderita a agregar
    pos banderita_jugada (0, 0);


    //// Excersice
    cambiarBanderita(T, j, banderita_jugada, b);


    //// Check
    banderitas valor_esperado = {pos (0, 4), pos (1, 2), pos (1, 3)};
}

TEST(cambiarBanteritaTest, posicionInvalida){
    //// Setup
    // Estado actual del juego
    tablero T = {
            { cVACIA,  cVACIA,  cVACIA, cVACIA, cMINA },
            { cVACIA, cVACIA, cVACIA, cMINA,  cVACIA },
            { cVACIA, cVACIA,  cVACIA, cMINA, cVACIA },
            { cVACIA, cMINA, cVACIA, cVACIA, cVACIA },
            { cMINA,  cVACIA, cMINA,  cVACIA, cVACIA },
    };

    banderitas b = {pos (0, 4), pos (1, 2), pos (1, 3)};

    jugadas j = {jugada (pos (0,0), minasAdyacentes(T, pos (0,0))),
                 jugada (pos (2,1), minasAdyacentes(T, pos (2,1)))};

    // Banderita a agregar
    pos banderita_jugada (-1, 0);


    //// Excersice
    cambiarBanderita(T, j, banderita_jugada, b);


    //// Check
    banderitas valor_esperado = {pos (0, 4), pos (1, 2), pos (1, 3)};
}

