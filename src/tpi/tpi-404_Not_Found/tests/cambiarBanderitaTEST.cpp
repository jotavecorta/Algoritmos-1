// Tests para la función cambiarBanderita.
// Ver el archovo README.md para ayuda


#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

TEST(cambiarBanteritaTest, SinBanderitaEnPosicion){
    //// Setup
    tablero T (5, vector<bool>(5, false));
    T[0][4] = T[1][3] = T[2][3] = T[4][0] = T[3][1]= true;

    // Armo dos vectores con el estado del juego antes de agregar la nueva banderita
    vector<pos> banderitasAColocar = {pos (0, 4), pos (1, 2), pos (1, 3)};

    // Inicializo las jugadas y las banderitas. Coloco las posiciones a jugar
    jugadas J;
    banderitas b;
    initJB(T, J, b);

    // Exercise. Coloco las banderitas
    for (int i = 0; i < banderitasAColocar.size(); ++i) {
        cambiarBanderita(T, J, banderitasAColocar[i], b);
    }

    // Check
    banderitas valor_esperado = {pos (-1, -1), pos (-1, -1), pos (-1, -1), pos (-1, -1), pos (0, 4),
                                 pos (-1, -1), pos (-1, -1), pos (1, 2), pos (1, 3), pos (-1, -1),
                                 pos (-1, -1), pos (-1, -1), pos (-1, -1), pos (-1, -1), pos (-1, -1),
                                 pos (-1, -1), pos (-1, -1), pos (-1, -1), pos (-1, -1), pos (-1, -1),
                                 pos (-1, -1), pos (-1, -1), pos (-1, -1), pos (-1, -1), pos (-1, -1)};

    ASSERT_EQ(b, valor_esperado);

}

TEST(cambiarBanteritaTest, ConBanderitaEnPosicion){
    //// Setup
    tablero T (5, vector<bool>(5, false));
    T[0][4] = T[1][3] = T[2][3] = T[4][0] = T[3][1]= true;

    // Armo dos vectores con el estado del juego antes de agregar la nueva banderita
    vector<pos> banderitasAColocar = {pos (0, 4), pos (1, 2)};

    // Inicializo las jugadas y las banderitas. Coloco las posiciones a jugar
    jugadas J;
    banderitas b;
    initJB(T, J, b);

    //  Coloco las posiciones a jugar y las banderas
    for (int i = 0; i < banderitasAColocar.size(); ++i) {
        cambiarBanderita(T, J, banderitasAColocar[i], b);
    }

    // Exercise. Removemos una posición que ya está
    cambiarBanderita(T, J, pos (1, 2), b);

    // Check
    banderitas valor_esperado = {pos (-1, -1), pos (-1, -1), pos (-1, -1), pos (-1, -1), pos (0, 4),
                                 pos (-1, -1), pos (-1, -1), pos (-1, -1), pos (-1, -1), pos (-1, -1),
                                 pos (-1, -1), pos (-1, -1), pos (-1, -1), pos (-1, -1), pos (-1, -1),
                                 pos (-1, -1), pos (-1, -1), pos (-1, -1), pos (-1, -1), pos (-1, -1),
                                 pos (-1, -1), pos (-1, -1), pos (-1, -1), pos (-1, -1), pos (-1, -1)};

    ASSERT_EQ(b, valor_esperado);
}


TEST(cambiarBanteritaTest, posicionYaJugada){
    //// Setup
    tablero T (5, vector<bool>(5, false));
    T[0][4] = T[1][3] = T[2][3] = T[4][0] = T[3][1]= true;

    // Inicializo las jugadas y las banderitas. Coloco las posiciones a jugar
    jugadas J;
    banderitas b;
    initJB(T, J, b);

    jugar(T, J, pos(1, 2));

    // Exercise. Removemos una posición que ya está
    cambiarBanderita(T, J, pos (1, 2), b);

    // Check
    banderitas valor_esperado = {pos (-1, -1), pos (-1, -1), pos (-1, -1), pos (-1, -1), pos (-1, -1),
                                 pos (-1, -1), pos (-1, -1), pos (-1, -1), pos (-1, -1), pos (-1, -1),
                                 pos (-1, -1), pos (-1, -1), pos (-1, -1), pos (-1, -1), pos (-1, -1),
                                 pos (-1, -1), pos (-1, -1), pos (-1, -1), pos (-1, -1), pos (-1, -1),
                                 pos (-1, -1), pos (-1, -1), pos (-1, -1), pos (-1, -1), pos (-1, -1)};

    ASSERT_EQ(b, valor_esperado);
}

