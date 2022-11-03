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
    vector<pos> posicionesAJugar = {pos (0, 0), pos (0, 1), pos (4, 4)};
    vector<pos> banderitasAColocar = {pos (0, 4), pos (1, 2)};

    // Inicializo las jugadas y las banderitas. Coloco las posiciones a jugar
    jugadas J;
    banderitas b;
    initJB(T, J, b);

    //  Coloco las posiciones a jugar y las banderas
    for (int i = 0; i < posicionesAJugar.size(); ++i) {
        jugar(T, J, posicionesAJugar[i]);
    }

    for (int i = 0; i < banderitasAColocar.size(); ++i) {
        pos p = banderitasAColocar[i];
        int indice = mapIndex(T.size(), p.first, p.second);
        b[indice] = p;
    }

    // Inicializo la posición a colocar una nueva banderita
    pos posicionSospechosa (1, 3);

    // Exercise
    cambiarBanderita(T, J, posicionSospechosa, b);

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
    vector<pos> posicionesAJugar = {pos (0, 0), pos (0, 1), pos (4, 4)};
    vector<pos> banderitasAColocar = {pos (0, 4), pos (1, 2)};

    // Inicializo las jugadas y las banderitas. Coloco las posiciones a jugar
    jugadas J;
    banderitas b;
    initJB(T, J, b);

    //  Coloco las posiciones a jugar y las banderas
    for (int i = 0; i < posicionesAJugar.size(); ++i) {
        jugar(T, J, posicionesAJugar[i]);
    }

    for (int i = 0; i < banderitasAColocar.size(); ++i) {
        pos p = banderitasAColocar[i];
        int indice = mapIndex(T.size(), p.first, p.second);
        b[indice] = p;
    }

    // Inicializo la posición a colocar una nueva banderita
    pos posicionLibreSospecha (1, 2);

    // Exercise
    cambiarBanderita(T, J, posicionLibreSospecha, b);

    // Check
    banderitas valor_esperado = {pos (-1, -1), pos (-1, -1), pos (-1, -1), pos (-1, -1), pos (0, 4),
                                 pos (-1, -1), pos (-1, -1), pos (-1, -1), pos (-1, -1), pos (-1, -1),
                                 pos (-1, -1), pos (-1, -1), pos (-1, -1), pos (-1, -1), pos (-1, -1),
                                 pos (-1, -1), pos (-1, -1), pos (-1, -1), pos (-1, -1), pos (-1, -1),
                                 pos (-1, -1), pos (-1, -1), pos (-1, -1), pos (-1, -1), pos (-1, -1)};

    ASSERT_EQ(b, valor_esperado);



}

