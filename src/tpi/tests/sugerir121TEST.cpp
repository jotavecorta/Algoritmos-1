// Tests para la función sugerir121.
// Ver el archovo README.md para ayuda

#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

TEST(Sugerir121TEST, hayhorizontalA121){
    tablero T = {
            { cVACIA,  cVACIA,  cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA,  cVACIA },
            { cVACIA, cMINA,  cVACIA, cMINA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
            { cVACIA,  cVACIA, cVACIA,  cVACIA, cVACIA },
    };

    vector<pos> posicionesAJugar = {
            pos(1, 1), pos(1, 2), pos(1, 3)
    };

    // Inicializo las jugadas y las banderitas. Coloco las posiciones a jugar
    jugadas J;
    banderitas b;
    pos p (-1,-1);
    initJB(T, J, b);

    //  Coloco las posiciones a jugar
    for (int i = 0; i < posicionesAJugar.size(); ++i) {
        jugar(T, J, posicionesAJugar[i]);
    }

    ASSERT_TRUE(sugerirAutomatico121(T,b,J,p));
    ASSERT_EQ(p,pos(2,2));// cuando pongamos cortocircuito hay que compararlo con el (0,2)
}

TEST(Sugerir121TEST, hayhorizontalB121){
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
    pos p (-1,-1);
    initJB(T, J, b);

    //  Coloco las posiciones a jugar
    for (int i = 0; i < posicionesAJugar.size(); ++i) {
        jugar(T, J, posicionesAJugar[i]);
    }

    ASSERT_TRUE(sugerirAutomatico121(T,b,J,p));
    ASSERT_EQ(p,pos(2,2));
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
    pos p (-1,-1);
    initJB(T, J, b);

    //  Coloco las posiciones a jugar
    for (int i = 0; i < posicionesAJugar.size(); ++i) {
        jugar(T, J, posicionesAJugar[i]);
    }

    ASSERT_FALSE(sugerirAutomatico121(T,b,J,p));
}
TEST(Sugerir121TEST, hayverticalA121){
    tablero T = {
            { cVACIA,  cVACIA,  cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA,  cVACIA },
            { cMINA, cVACIA,  cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
            { cMINA,  cVACIA, cVACIA,  cVACIA, cVACIA },
    };

    vector<pos> posicionesAJugar = {
            pos(2, 1), pos(3, 1), pos(4, 1)
    };

    // Inicializo las jugadas y las banderitas. Coloco las posiciones a jugar
    jugadas J;
    banderitas b;
    pos p (-1,-1);
    initJB(T, J, b);

    //  Coloco las posiciones a jugar
    for (int i = 0; i < posicionesAJugar.size(); ++i) {
        jugar(T, J, posicionesAJugar[i]);
    }

    ASSERT_TRUE(sugerirAutomatico121(T,b,J,p));
    ASSERT_EQ(p,pos(3,2));//si es cortocircuito me daria el (3,0)
}
TEST(Sugerir121TEST, hayverticalB121){
    tablero T = {
            { cVACIA,  cVACIA,  cVACIA, cVACIA, cVACIA },
            { cVACIA, cMINA, cVACIA, cVACIA,  cVACIA },
            { cVACIA, cVACIA,  cVACIA, cVACIA, cVACIA },
            { cVACIA, cMINA, cVACIA, cVACIA, cVACIA },
            { cVACIA,  cVACIA, cVACIA,  cVACIA, cVACIA },
    };

    vector<pos> posicionesAJugar = {
            pos(1, 2), pos(2, 2), pos(3, 2)
    };

    // Inicializo las jugadas y las banderitas. Coloco las posiciones a jugar
    jugadas J;
    banderitas b;
    pos p (-1,-1);
    initJB(T, J, b);

    //  Coloco las posiciones a jugar
    for (int i = 0; i < posicionesAJugar.size(); ++i) {
        jugar(T, J, posicionesAJugar[i]);
    }

    ASSERT_TRUE(sugerirAutomatico121(T,b,J,p));
    ASSERT_EQ(p,pos(2,3));
}