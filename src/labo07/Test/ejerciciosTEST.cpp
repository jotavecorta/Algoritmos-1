#include "../ejercicios.h"
#include "gtest/gtest.h"

// productoVectorial Test Suit
TEST(productoVectorialTest, IgualDimension){
    // Setup
    vector<int> u = {2,3,4};
    vector<int> v = {4,3,2};
    vector<vector<int> > expected = {
            {8,  6,  4},
            {12,  9,  6},
            {16, 12,  8}
    };

    // Exercise
    vector<vector<int> > real = productoVectorial(u,v);

    // Check
    EXPECT_EQ(real, expected);
}

TEST(productoVectorialTest, DistintaDimension){
    // Setup
    vector<int> u = {6,7,8,9};
    vector<int> v = {1,2,3};
    vector<vector<int> > expected = {
            { 6, 12, 18},
            {7, 14, 21},
            {8, 16, 24},
            {9, 18, 27}
    };

    // Exercise
    vector<vector<int> > real = productoVectorial(u,v);

    // Check
    EXPECT_EQ(real, expected);
}

TEST(productoVectorialTest, UnoPorUno){
    // Setup
    vector<int> u = {6};
    vector<int> v = {2};
    vector<vector<int> > expected = {
            {12}
    };

    // Exercise
    vector<vector<int> > real = productoVectorial(u,v);

    // Check
    EXPECT_EQ(real, expected);
}

// Test Suit esTriangular
TEST(esTriangularTest, TriangularSuperior){
    // Setup
    vector<vector<int> > m = {
            {1,2,0,4},
            {0,2,0,0},
            {0,0,3,4},
            {0,0,0,4}
    };

    // Excercise
    bool res = esTriangular(m);

    // Check
    EXPECT_TRUE(res);
}

TEST(esTriangularTest, TriangularInferior){
    // Setup
    vector<vector<int> > m = {
            {1,0,0,0},
            {0,2,0,0},
            {0,8,3,0},
            {0,0,0,4}
    };

    // Excercise
    bool res = esTriangular(m);

    // Check
    EXPECT_TRUE(res);
}

TEST(esTriangularTest, CasiTriangular){
    // Setup
    vector<vector<int> > m = {
            {1,0,0,0},
            {0,2,3,0},
            {0,0,3,0},
            {1,0,0,0}
    };

    // Excercise
    bool res = esTriangular(m);

    // Check
    EXPECT_FALSE(res);
}

TEST(esTriangularTest, CerosEnDiagonal){
    // Setup
    vector<vector<int> > m = {
            {0,0,0,4},
            {0,0,0,0},
            {0,0,0,0},
            {1,0,0,0}
    };

    // Excercise
    bool res = esTriangular(m);

    // Check
    EXPECT_FALSE(res);
}

TEST(esTriangularTest, DosXDos){
    // Setup
    vector<vector<int> > m = {
            {1,8},
            {0,2},
    };

    // Excercise
    bool res = esTriangular(m);

    // Check
    EXPECT_TRUE(res);
}

// TestSuit hayAmenaza
TEST(hayAmenazaTest, SinAmenazas){
    // Setup
    vector<vector<int> > vec(8,vector<int>(8,0));
    vec[0][2] = vec[1][5] = vec[2][3] = vec[3][0] = vec[4][7] = vec[5][4] = vec[6][6] = vec[7][1] = 1;

    // Excercise
    bool res = hayAmenaza(vec);

    // Check
    EXPECT_FALSE(res);
}

TEST(hayAmenazaTest, conAmenazas){
    // Setup
    vector<vector<int> > vec(8,vector<int>(8,0));
    vec[0][2] = vec[1][5] = vec[2][3] = vec[3][0] = vec[4][7] = vec[5][1] = vec[6][6] = vec[7][4] = 1;

    // Excercise
    bool res = hayAmenaza(vec);

    // Check
    EXPECT_TRUE(res);
}

TEST(hayAmenazaTest, test3){
    // Setup
    vector<vector<int> > vec(3,vector<int>(4,0));
    vec[0][0] = vec[1][3] = vec[2][1] = 1;

    // Excercise
    bool res = hayAmenaza(vec);

    // Check
    EXPECT_FALSE(res);
}

TEST(hayAmenazaTest, AmenazaHorizontal){
    // Setup
    vector<vector<int> > vec(3,vector<int>(4,0));
    vec[0][0] = vec[2][3] = vec[2][1] = 1;

    // Excercise
    bool res = hayAmenaza(vec);

    // Check
    EXPECT_TRUE(res);
}

TEST(hayAmenazaTest, AmenazaVertical){
    // Setup
    vector<vector<int> > vec(3,vector<int>(4,0));
    vec[0][0] = vec[1][3] = vec[2][3] = 1;

    // Excercise
    bool res = hayAmenaza(vec);

    // Check
    EXPECT_TRUE(res);
}