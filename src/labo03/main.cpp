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

    // Rotar
    int n; //Longitud del vector a rotar
    cin >> n;
    int i = 0;
    int x;
    vector<int> v;// En v leo el vector
    while (i<n){
        cin >> x;
        v.push_back(x);
        i++;
    }
    
    int k; // La cantidad que tengo que rotar la guardo en k
    cin >> k;
    
    // Hago la rotacion
    vector<int> res = rotar(v,k);
    i = 0;
    
    // Imprimo el vector resultado
    while (i < res.size()){
        cout << res[i] << " ";
        i++;
    }

    // Maximo
    cout << "\n";
    cout << "El máximo es: " << mayor(v) << "\n";

    // factores primos
    vector<int> factores = factoresPrimos(n);
    cout << "\n";
    cout << "Los factores primos de n son : \n";
    mostrarVector(factores); 
    cout << "\n";

    return 0;
}
