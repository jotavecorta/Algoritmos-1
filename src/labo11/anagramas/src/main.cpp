#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "gtest/gtest.h"
#include "anagramas.h"
using namespace std;

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
//    string palabra, palabra2;
//    cout << "Ingrese una palabra en ingles con letras en minuscula:" << endl;
//    cin >> palabra;
//
//    ifstream dicci ("ingles.dic");
//    vector<string> listaPalabras;
//    string word;
//    while(getline(dicci, word)){
//        listaPalabras.push_back(word);
//    }
//    int cantidadAnagrama = 0;
//    for (int i = 0; i < listaPalabras.size(); ++i)
//    {
//        if (esAnagrama(listaPalabras[i], palabra)) {
//            cout << "Son anagramas: " << listaPalabras[i] << " y " << palabra << endl;
//            cantidadAnagrama++;
//        }
//    }
//    cout << "La cantidad de anagramas es: " << cantidadAnagrama << endl;
//    return 0;
}


