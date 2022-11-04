#include "../puntaje.h"
#include "gtest/gtest.h"

TEST(PuntajeTest, MenorQueDiezYDivisiblePorTres){
    // Setup
    int b = 3;
    // Exercise
    int result = puntaje(b);
    // Check
    EXPECT_EQ(result, 16);
}

TEST(PuntajeTest, MenorQueDiezYNoDivisiblePorTres){
    // Setup
    int b = 2;
    // Exercise
    int result = puntaje(b);
    // Check
    EXPECT_EQ(result, -6);
}

TEST(PuntajeTest, MayorQueDiezYDivisiblePorTres){
    // Setup
    int b = 12;
    // Exercise
    int result = puntaje(b);
    // Check
    EXPECT_EQ(result, 22);
}

TEST(PuntajeTest, MayorQueDiezYNoDivisiblePorTres){
    // Setup
    int b = 25;
    // Exercise
    int result = puntaje(b);
    // Check
    EXPECT_EQ(result, 15);
}