#include "../baldosasDelPiso.h"
#include "gtest/gtest.h"

TEST(baldosasDelPisoTest, AmbosDivisiblesPorB){
    // Setup
    int M = 12;
    int N = 9;
    int B = 3;

    // Excercise
    int result = baldosasDelPiso(M, N, B);

    // Check
    EXPECT_EQ(result, 12);
}

TEST(baldosasDelPisoTest, MDivisiblesPorB){
    // Setup
    int M = 12;
    int N = 5;
    int B = 3;

    // Excercise
    int result = baldosasDelPiso(M, N, B);

    // Check
    EXPECT_EQ(result, 8);
}

TEST(baldosasDelPisoTest, NDivisiblesPorB){
    // Setup
    int M = 7;
    int N = 6;
    int B = 3;

    // Excercise
    int result = baldosasDelPiso(M, N, B);

    // Check
    EXPECT_EQ(result, 6);
}

TEST(baldosasDelPisoTest, NingunoDivisiblesPorB){
    // Setup
    int M = 7;
    int N = 11;
    int B = 3;

    // Excercise
    int result = baldosasDelPiso(M, N, B);

    // Check
    EXPECT_EQ(result, 12);
}
