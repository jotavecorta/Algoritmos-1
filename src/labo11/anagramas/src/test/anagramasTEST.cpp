#include "../anagramas.h"
#include "gtest/gtest.h"
#include <string>

using namespace std;

TEST(ordenarStringTest, ordenInversoAlAlfabeto){
    // SetUp
    string s = "gfedcba";

    // Excercise
    ordenarString(s);
    string valor_esperado = "abcdefg";

    // Check
    ASSERT_EQ(s, valor_esperado);
}

TEST(ordenarStringTest, PalabraOrdenada){
    // SetUp
    string s = "abcdefg";

    // Excercise
    ordenarString(s);
    string valor_esperado = "abcdefg";

    // Check
    ASSERT_EQ(s, valor_esperado);
}

TEST(ordenarStringTest, PalabraDesordenada){
    // SetUp
    string s = "esdrujula";

    // Excercise
    ordenarString(s);
    string valor_esperado = "adejlrsuu";

    // Check
    ASSERT_EQ(s, valor_esperado);
}

TEST(anagrama1TEST, SonAnagramas){
    // SetUp
    string s1 = "listen";
    string s2 = "silent";

    // Excercise
    bool res = esAnagrama1(s1, s2);

    // Check
    ASSERT_TRUE(res);
}

TEST(anagrama1TEST, NoSonAnagramas){
    // SetUp
    string s1 = "conversation";
    string s2 = "silence";

    // Excercise
    bool res = esAnagrama1(s1, s2);

    // Check
    ASSERT_FALSE(res);
}

TEST(anagrama1TEST, SonAnagramasLargos){
    // SetUp
    string s1 = "tergiversation";
    string s2 = "interrogatives";

    // Excercise
    bool res = esAnagrama1(s1, s2);

    // Check
    ASSERT_TRUE(res);
}