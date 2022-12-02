// Tests para la función sugerir121.

#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

TEST(Sugerir121TEST, hayHorizontal121NoDeterminable){
    // En este caso con la cantidad de jugadas no es posible determinar si la posición a
    // sugerir es la (0, 2) o la (2, 2) sin consultar dónde están las minas, por lo tanto no es sugerible
    tablero T = {
            { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
            { cVACIA, cMINA,  cVACIA, cMINA,  cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
    };

    vector<pos> posicionesAJugar = {
        pos(1, 1), pos(1, 2), pos(1, 3)
    };

    // Inicializo las jugadas y las banderitas. Coloco las posiciones a jugar
    jugadas j;
    banderitas b;
    pos p (0, 0);

    for (int i = 0; i < posicionesAJugar.size(); ++i) {
        jugar(T, j, posicionesAJugar[i]);
    }

    ASSERT_FALSE(sugerirAutomatico121(T, b, j, p));
    ASSERT_EQ(p, pos(0, 0));
}

TEST(Sugerir121TEST, hayHorizontal121){
    tablero T = {
            { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
            { cVACIA, cMINA,  cVACIA, cMINA,  cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
    };

    // Inicializo las jugadas y las banderitas. Coloco las posiciones a jugar
    jugadas J;
    banderitas b;
    pos p (-1,-1);

    //  Coloco las posiciones a jugar
    jugarPlus(T, b, pos(0, 2), J);

    ASSERT_TRUE(sugerirAutomatico121(T,b,J,p));
    ASSERT_EQ(p, pos(2,2)); // cuando pongamos cortocircuito hay que compararlo con el (0,2)
}

TEST(Sugerir121TEST, hayHorizontal121EnBordeNoDeterministico){
    // Igual que antes con la cantidad de jugadas no es posible determinar
    // si tenemos que devolver el (0, 2) o el (2, 2) ????
    tablero T = {
            { cVACIA,  cMINA,  cVACIA, cMINA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA,  cVACIA },
            { cVACIA, cVACIA,  cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
            { cVACIA,  cVACIA, cVACIA,  cVACIA, cVACIA },
    };

    vector<pos> posicionesAJugar = {
            pos(1, 1), pos(1, 2), pos(1, 3)
    };

    // Inicializo las jugadas y las banderitas. Coloco las posiciones a jugar
    jugadas J;
    banderitas b;
    pos p (0, 3);

    //  Coloco las posiciones a jugar
    for (int i = 0; i < posicionesAJugar.size(); ++i) {
        jugar(T, J, posicionesAJugar[i]);
    }

    ASSERT_FALSE(sugerirAutomatico121(T,b,J,p));
    ASSERT_EQ(p, pos(0,3));
}

// REVISAR ESTE TEST QUE NO PASA, Y SUS COMENTARIOS
TEST(Sugerir121TEST, hayHorizontal121EnBorde){
    // Igual que antes con la cantidad de jugadas no es posible determinar
    // si tenemos que devolver el
    tablero T = {
            { cVACIA,  cVACIA,  cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA,  cVACIA },
            { cVACIA, cVACIA,  cVACIA, cVACIA, cVACIA },
            { cVACIA, cMINA, cVACIA, cMINA, cVACIA },
            { cVACIA,  cVACIA, cVACIA,  cVACIA, cVACIA },
    };

    vector<pos> posicionesAJugar = {
            pos(4, 1), pos(4, 2), pos(4, 3)
    };

    // Inicializo las jugadas y las banderitas
    jugadas J;
    banderitas b;
    pos p (0, 0);

    //  Coloco las posiciones a jugar
    for (int i = 0; i < posicionesAJugar.size(); ++i) {
        jugar(T, J, posicionesAJugar[i]);
    }

    ASSERT_TRUE(sugerirAutomatico121(T,b,J,p));
    ASSERT_EQ(p, pos(3, 2));
}

TEST(Sugerir121TEST, hayHorizontal121EnCentro){
    tablero T = {
            { cVACIA,  cMINA,  cVACIA, cMINA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA,  cVACIA },
            { cVACIA, cVACIA,  cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
            { cVACIA,  cVACIA, cVACIA,  cVACIA, cVACIA },
    };

    // Inicializo las jugadas y las banderitas. Coloco las posiciones a jugar
    jugadas J;
    banderitas b;
    pos p (0, 0);

    //  Coloco las posiciones a jugar
    jugarPlus(T, b, pos(3, 2), J);

    ASSERT_TRUE(sugerirAutomatico121(T,b,J,p));
    ASSERT_EQ(p, pos(0, 2));
}

TEST(Sugerir121TEST, noHay121){
    tablero T = {
            { cMINA,  cVACIA,  cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA,  cVACIA },
            { cVACIA, cVACIA,  cVACIA, cMINA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
            { cVACIA,  cVACIA, cVACIA,  cVACIA, cVACIA },
    };

    vector<pos> posicionesAJugar = {
            pos(0, 1), pos(0, 2), pos(0, 3)
    };

    // Inicializo las jugadas y las banderitas. Coloco las posiciones a jugar
    jugadas J;
    banderitas b;
    pos p (0, 1);

    //  Coloco las posiciones a jugar
    for (int i = 0; i < posicionesAJugar.size(); ++i) {
        jugar(T, J, posicionesAJugar[i]);
    }

    ASSERT_FALSE(sugerirAutomatico121(T,b,J,p));
    ASSERT_EQ(p, pos(0, 1));
}

TEST(Sugerir121TEST, hayVertical121EnBorde){
    // Igual que con los horizontales, no es deterministico. No podemos decidir entre el (3, 0) o el (3, 1)
    tablero T = {
            { cVACIA,  cVACIA,  cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA,  cVACIA },
            { cVACIA, cMINA,  cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
            { cVACIA,  cMINA, cVACIA,  cVACIA, cVACIA },
    };

    vector<pos> posicionesAJugar = {
            pos(2, 0), pos(3, 0), pos(4, 0)
    };

    // Inicializo las jugadas y las banderitas. Coloco las posiciones a jugar
    jugadas J;
    banderitas b;
    pos p (0, 0);

    //  Coloco las posiciones a jugar
    for (int i = 0; i < posicionesAJugar.size(); ++i) {
        jugar(T, J, posicionesAJugar[i]);
    }

    ASSERT_TRUE(sugerirAutomatico121(T,b,J,p));
    ASSERT_EQ(p, pos(3,1));
}

TEST(Sugerir121TEST, hayVertical121EnCentroNoDeterministico){
    // Igual que con los horizontales, no es deterministico. No podemos decidir entre el (3, 0) o el (3, 1)
    tablero T = {
            { cVACIA,  cVACIA,  cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA,  cVACIA },
            { cVACIA, cMINA,  cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
            { cVACIA,  cMINA, cVACIA,  cVACIA, cVACIA },
    };

    vector<pos> posicionesAJugar = {
            pos(2, 2), pos(3, 2), pos(4, 2)
    };

    // Inicializo las jugadas y las banderitas. Coloco las posiciones a jugar
    jugadas J;
    banderitas b;
    pos p (1, 4);

    //  Coloco las posiciones a jugar
    for (int i = 0; i < posicionesAJugar.size(); ++i) {
        jugar(T, J, posicionesAJugar[i]);
    }

    ASSERT_FALSE(sugerirAutomatico121(T,b,J,p));
    ASSERT_EQ(p,pos(1, 4));
}

TEST(Sugerir121TEST, hayVertical121EnCentro){
    tablero T = {
            { cVACIA,  cVACIA,  cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA,  cVACIA },
            { cVACIA, cMINA,  cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
            { cVACIA,  cMINA, cVACIA,  cVACIA, cVACIA },
    };

    // Inicializo las jugadas y las banderitas. Coloco las posiciones a jugar
    jugadas J;
    banderitas b;
    pos p (-1,-1);

    // Coloco las posiciones a jugar
    jugarPlus(T, b, pos(2, 3), J);

    ASSERT_TRUE(sugerirAutomatico121(T,b,J,p));
    ASSERT_EQ(p, pos(3,1));
}

TEST(Sugerir121TEST, hayVertical121NoDeterministico){
    // Idem a todos los no deterministicos
    tablero T = {
            { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
            { cVACIA, cMINA,  cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
            { cVACIA, cMINA,  cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
    };

    vector<pos> posicionesAJugar = {
            pos(1, 2), pos(2, 2), pos(3, 2)
    };

    // Inicializo las jugadas y las banderitas.
    jugadas J;
    banderitas b;
    pos p (0, 0);

    //  Coloco las posiciones a jugar
    for (int i = 0; i < posicionesAJugar.size(); ++i) {
        jugar(T, J, posicionesAJugar[i]);
    }

    ASSERT_FALSE(sugerirAutomatico121(T,b,J,p));
    ASSERT_EQ(p, pos(0, 0));
}

TEST(Sugerir121TEST, hayVertical121){
    tablero T = {
            { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
            { cVACIA, cMINA,  cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
            { cVACIA, cMINA,  cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
    };

    // Inicializo las jugadas y las banderitas. Coloco las posiciones a jugar
    jugadas J;
    banderitas b;
    pos p (-1, -1);

    //  Coloco las posiciones a jugar
    jugarPlus(T, b, pos(2, 3), J);

    ASSERT_TRUE(sugerirAutomatico121(T,b,J,p));
    ASSERT_EQ(p, pos(2,1));
}

// SI TIENE BANDERITA HAY QUE DEVOLVER FALSE
TEST(Sugerir121TEST, hay121PeroTieneBanderita){
    tablero T = {
            { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
            { cVACIA, cMINA,  cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
            { cVACIA, cMINA,  cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
    };

    // Inicializo las jugadas y las banderitas.
    jugadas J;
    banderitas b = {pos(2, 1)};
    pos p (-1, -1);

    //  Coloco las posiciones a jugar
    jugarPlus(T, b, pos(2, 3), J);

    ASSERT_FALSE(sugerirAutomatico121(T,b,J,p));
    ASSERT_EQ(p, pos(-1, -1));
}

TEST(Sugerir121TEST, hay121PeroEnEsquina){
    tablero T = {
            { cVACIA, cMINA, cVACIA, cVACIA, cVACIA },
            { cMINA, cVACIA,  cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA,  cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
    };

    // Inicializo las jugadas y las banderitas.
    vector<pos> posicionesAJugar = {pos(0, 0)};

    jugadas J;
    for (int i = 0; i < posicionesAJugar.size(); ++i) {
        jugar(T, J, posicionesAJugar[i]);
    }

    banderitas b;
    pos p (-1, -1);

    //  Coloco las posiciones a jugar
    jugarPlus(T, b, pos(1, 1), J);

    ASSERT_FALSE(sugerirAutomatico121(T,b,J,p));
    ASSERT_EQ(p, pos(-1, -1));
}