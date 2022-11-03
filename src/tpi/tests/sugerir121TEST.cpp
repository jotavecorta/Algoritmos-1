// Tests para la función sugerir121.
// Ver el archovo README.md para ayuda

#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

TEST(Sugerir121TEST, hay121){
    tablero T = {
            { cVACIA,  cVACIA,  cVACIA, cVACIA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA,  cVACIA },
            { cVACIA, cMINA,  cVACIA, cMINA, cVACIA },
            { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
            { cVACIA,  cVACIA, cVACIA,  cVACIA, cVACIA },
    };

    vector<pos> posicionesAJugar = {
            pos(3, 1), pos(3, 2), pos(3, 3)
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
    ASSERT_EQ(p,pos(4,4));
}