// Tests para la función minasAdyacentes.
// Ver el archivo README.md para ayuda

#include "../ejercicios.h"
#include "../auxiliares.h"
#include "../definiciones.h"
#include "gtest/gtest.h"

using namespace std;

// Casos Borde
TEST(minasAdyacentesCasosBorde, BordeIzquierdo){
    // Setup
    tablero T (5, vector<bool>(5, false));
    T[0][1] = T[1][0] = T[2][2] = T[4][0] = T[3][1]= true;

    pos posicion (3, 0);

    // Exercise
    int cant_minas_adyacentes = minasAdyacentes(T, posicion);

    // Check
    int valor_esperado = 2;
    ASSERT_EQ(cant_minas_adyacentes, valor_esperado);
}

TEST(minasAdyacentesCasosBorde, BordeDerecho){
    // Setup
    tablero T (5, vector<bool>(5, false));
    T[0][4] = T[1][3] = T[2][3] = T[4][0] = T[3][1]= true;

    pos posicion (1, 4);

    // Exercise
    int cant_minas_adyacentes = minasAdyacentes(T, posicion);

    // Check
    int valor_esperado = 3;
    ASSERT_EQ(cant_minas_adyacentes, valor_esperado);
}

TEST(minasAdyacentesCasosBorde, BordeSuperior){
    // Setup
    tablero T (5, vector<bool>(5, false));
    T[0][4] = T[1][3] = T[2][3] = T[4][0] = T[3][1]= true;

    pos posicion (0, 2);

    // Exercise
    int cant_minas_adyacentes = minasAdyacentes(T, posicion);

    // Check
    int valor_esperado = 1;
    ASSERT_EQ(cant_minas_adyacentes, valor_esperado);
}

TEST(minasAdyacentesCasosBorde, BordeInferior){
    // Setup
    tablero T (5, vector<bool>(5, false));
    T[0][4] = T[1][3] = T[2][3] = T[4][4] = T[3][3]= true;

    pos posicion (4, 3);

    // Exercise
    int cant_minas_adyacentes = minasAdyacentes(T, posicion);

    // Check
    int valor_esperado = 2;
    ASSERT_EQ(cant_minas_adyacentes, valor_esperado);
}

TEST(minasAdyacentesCasosBorde, Esquina){
    // Setup
    tablero T (5, vector<bool>(5, false));
    T[0][1] = T[1][0] = T[2][3] = T[4][0] = T[3][1]= true;

    pos posicion (0, 0);

    // Exercise
    int cant_minas_adyacentes = minasAdyacentes(T, posicion);

    // Check
    int valor_esperado = 2;
    ASSERT_EQ(cant_minas_adyacentes, valor_esperado);
}

// Interior del tablero
TEST(minasAdyacentesInteriorTablero, ConMinasAdyacentes){
    // Setup
    tablero T (5, vector<bool>(5, false));
    T[0][4] = T[1][3] = T[2][3] = T[4][0] = T[3][1]= true;

    pos posicion (2, 2);

    // Exercise
    int cant_minas_adyacentes = minasAdyacentes(T, posicion);

    // Check
    int valor_esperado = 2;
    ASSERT_EQ(cant_minas_adyacentes, valor_esperado);
}

TEST(minasAdyacentesInteriorTablero, SinMinasAdyacentes){
    // Setup
    tablero T (5, vector<bool>(5, false));
    T[0][4] = T[0][3] = T[0][0] = T[4][0] = T[3][1]= true;

    pos posicion (2, 3);

    // Exercise
    int cant_minas_adyacentes = minasAdyacentes(T, posicion);

    // Check
    int valor_esperado = 0;
    ASSERT_EQ(cant_minas_adyacentes, valor_esperado);
}

TEST(minasAdyacentesInteriorTablero, ConMinaEnEsaPosicion){
    // Setup
    tablero T (5, vector<bool>(5, false));
    T[0][4] = T[2][3] = T[2][4] = T[4][0] = T[3][1]= true;

    pos posicion (2, 3);

    // Exercise
    int cant_minas_adyacentes = minasAdyacentes(T, posicion);

    // Check
    int valor_esperado = 1;
    ASSERT_EQ(cant_minas_adyacentes, valor_esperado);
}

TEST(minasAdyacentesInteriorTablero, TodosLosVecinosTienenMina){
    // Setup
    tablero T (5, vector<bool>(5, false));
    T[1][2] = T[1][3] = T[1][4] = true;
    T[2][2] = T[2][4] = true;
    T[3][2] = T[3][3] = T[3][4] = true;

    pos posicion (2, 3);

    // Exercise
    int cant_minas_adyacentes = minasAdyacentes(T, posicion);

    // Check
    int valor_esperado = 8;
    ASSERT_EQ(cant_minas_adyacentes, valor_esperado);
}