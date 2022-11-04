#include "../llenarTaxis.h"
#include "gtest/gtest.h"

/* Test-Suit para la primera versión */
TEST(LlenarTaxis1Test, TodosGruposIguales){
    // Setup
    int g1 = 2;
    int g2 = 2;
    int g3 = 2;

    // Excercise
    int result = llenarTaxis1(g1, g2, g3);

    // Check
    EXPECT_EQ(result, 3);
}

TEST(LlenarTaxis1Test, g2ImparYDiferenciaIgual){
    // Setup
    int g1 = 1;
    int g2 = 1;
    int g3 = 2;

    // Excercise
    int result = llenarTaxis1(g1, g2, g3);

    // Check
    EXPECT_EQ(result, 2);
}

TEST(LlenarTaxis1Test, g2ImparYDiferenciaDistinta){
    // Setup
    int g1 = 4;
    int g2 = 1;
    int g3 = 1;

    // Excercise
    int result = llenarTaxis1(g1, g2, g3);

    // Check
    EXPECT_EQ(result, 3);
}

/* Test-Suit para la segunda versión */
TEST(LlenarTaxis2Test, TodosGruposIguales){
    // Setup
    int g1 = 2;
    int g2 = 2;
    int g3 = 2;

    // Excercise
    int result = llenarTaxis2(g1, g2, g3);

    // Check
    EXPECT_EQ(result, 3);
}

TEST(LlenarTaxis2Test, g2ImparYDiferenciaIgual){
    // Setup
    int g1 = 1;
    int g2 = 1;
    int g3 = 2;

    // Excercise
    int result = llenarTaxis2(g1, g2, g3);

    // Check
    EXPECT_EQ(result, 2);
}

TEST(LlenarTaxis2Test, g2ImparYDiferenciaDistinta){
    // Setup
    int g1 = 4;
    int g2 = 1;
    int g3 = 1;

    // Excercise
    int result = llenarTaxis2(g1, g2, g3);

    // Check
    EXPECT_EQ(result, 3);
}

/* Test-Suit para la tercera versión */
TEST(LlenarTaxis3Test, TodosGruposIguales){
    // Setup
    int g1 = 2;
    int g2 = 2;
    int g3 = 2;

    // Excercise
    int result = llenarTaxis3(g1, g2, g3);

    // Check
    EXPECT_EQ(result, 3);
}

TEST(LlenarTaxis3Test, g2ImparYDiferenciaIgual){
    // Setup
    int g1 = 1;
    int g2 = 1;
    int g3 = 2;

    // Excercise
    int result = llenarTaxis3(g1, g2, g3);

    // Check
    EXPECT_EQ(result, 2);
}

TEST(LlenarTaxis3Test, g2ImparYDiferenciaDistinta){
    // Setup
    int g1 = 4;
    int g2 = 1;
    int g3 = 1;

    // Excercise
    int result = llenarTaxis3(g1, g2, g3);

    // Check
    EXPECT_EQ(result, 3);
}