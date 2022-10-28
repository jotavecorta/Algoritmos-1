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