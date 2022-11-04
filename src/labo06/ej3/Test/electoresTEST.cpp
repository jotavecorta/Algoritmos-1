#include "../electores.h"
#include "gtest/gtest.h"

// Escribir tests aca:
TEST(validarVotanteTest, FechaInvalida){
    // Setup
    int anio = -1;
    int mes = 10;
    int dia = 20;

    // Excercise
    int result = validarVotante(anio, mes, dia);

    // Check
    EXPECT_EQ(result, NO_VOTA);
}

TEST(validarVotanteTest, MenoresNoVotantes){
    // Setup
    int anio = 2010;
    int mes = 05;
    int dia = 23;

    // Excercise
    int result = validarVotante(anio, mes, dia);

    // Check
    EXPECT_EQ(result, NO_VOTA);
}

TEST(validarVotanteTest, MenoresOpcional){
    // Setup
    int anio = 2005;
    int mes = 03;
    int dia = 22;

    // Excercise
    int result = validarVotante(anio, mes, dia);

    // Check
    EXPECT_EQ(result, OPCIONAL_MENOR);
}

TEST(validarVotanteTest, Obligatorios){
    // Setup
    int anio = 2000;
    int mes = 11;
    int dia = 01;

    // Excercise
    int result = validarVotante(anio, mes, dia);

    // Check
    EXPECT_EQ(result, OBLIGATORIO);
}

TEST(validarVotanteTest, OpcionalMayor){
    // Setup
    int anio = 1950;
    int mes = 07;
    int dia = 22;

    // Excercise
    int result = validarVotante(anio, mes, dia);

    // Check
    EXPECT_EQ(result, OPCIONAL_MAYOR);
}