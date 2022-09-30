#include "generador.h"
#include "vectores.h"

using namespace std;

int main() {
    // funcion para generar automaticamente los archivos numericos
    // generarDatosLaboratorio(); // descomentar para crear automaticamente los archivos necesarios en la parte de entrada-salida. Una vez creados, se puede volver a comentar
    holaModuloVectores(); // función definida en vectores.cpp

    // // Compruebo la division
    // vector<int> v(5, 4);
    // int divisor = 2;

    // cout << "El divisor divide al vector: " << (divide(v, 2)? "True": "False") << "\n";

    // // Rotar
    // int n; //Longitud del vector a rotar
    // cin >> n;
    // int i = 0;
    // int x;
    // vector<int> v;// En v leo el vector
    // while (i<n){
    //     cin >> x;
    //     v.push_back(x);
    //     i++;
    // }
    
    // int k; // La cantidad que tengo que rotar la guardo en k
    // cin >> k;
    
    // // Hago la rotacion
    // vector<int> res = rotar(v,k);
    // i = 0;
    
    // // Imprimo el vector resultado
    // while (i < res.size()){
    //     cout << res[i] << " ";
    //     i++;
    // }

    // // Maximo
    // cout << "\n";
    // cout << "El máximo es: " << mayor(v) << "\n";

    // // factores primos
    // vector<int> factores = factoresPrimos(n);
    // cout << "\n";
    // cout << "Los factores primos de n son : \n";
    // mostrarVector(factores); 
    // cout << "\n";

    // Ejercicios de Lectura y Escritura de archivos
    // // --8-- leerVector
    // string file_name;
    // vector<int> vector_lectura;

    // cout << "Ingresar el nombre del archivo junto con su extensión: " << "\n";
    // cin >> file_name;
    
    // vector_lectura = leerVector(file_name);
    // mostrarVector(vector_lectura);
    // cout << "\n";

    // // --9-- guardarVector
    // string file_;
    // vector<int> vector_escritura;

    // // Longitud del vector a ingresar 
    // int n;
    // cout << "Ingrese la longitud del vector: " << "\n";
    // cin >> n;

    // // Inicializo el índice y las componentes del vector
    // int i = 0;
    // int v_i;
    
    // cout << "Ingrese cada una de las componentes del vector: " << "\n";
    // while (i < n){
    //     cin >> v_i;
    //     vector_escritura.push_back(v_i);
    //     i++;
    // }    
    
    // // Obtengo el nombre del archivo
    // cout << "Ingrese el nombre del archivo en el que desea guardar el vector: " << "\n";
    // cin >> file_;

    // // Guardo el vector en el archivo
    // guardarVector(vector_escritura, file_);


    // // --10-- elementoMedio
    // string file_elemento_medio;
    // vector<int> vector_elemento_medio;

    // cout << "Ingresar el nombre del archivo junto con su extensión: " << "\n";
    // cin >> file_elemento_medio;
    
    // vector_elemento_medio = leerVector(file_elemento_medio);
    // cout << "Elemento Medio: " << elementoMedio(vector_elemento_medio) << "\n";

    // --11-- cantApariciones
    string file_name;

    cout << "Ingresar el nombre del archivo sin su extensión: " << "\n";
    cin >> file_name;    

    cantApariciones(file_name);

    return 0;

}
