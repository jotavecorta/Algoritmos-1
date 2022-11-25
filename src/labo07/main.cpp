#include <iostream>
#include "ejercicios.h"
#include "cases.h"
#include "gtest/gtest.h"

using namespace std;

int main(int argc, char **argv)
{
    std::cout << "Implementando GTest!!" << std::endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    
}

