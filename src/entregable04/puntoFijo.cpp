#include <vector>
#include <iostream>

using namespace std;

int puntoFijo(vector<int> v){
    if (v.size() == 0){// Caso trivial
        return -1;
    }else if(v[0] == 0){
        return 0;
    }else{// Resto de los casos: hago busqueda binaria
        // Defino bordes de busqueda
        int low = 0;
        int high = v.size() - 1;

        while (high > low + 1){
            // Posicion media
            int mid = (high + low) / 2;

            // Si la posicion media cumple, listo
            if (v[mid]==mid){
                return mid;
            }

            // Sino, actualizo los bordes
            if (v[mid] > mid){
                high = mid;
            }else{
                low = mid;
            }
        }
    }
    if (v[v.size()-1] == v.size() -1){
        return v.size() - 1;
    }else{
        return -1;
    }

}

int main() {
    /* No hace falta modificar el main */
    // Leo las entradas
    int n;
    cin >> n;
    int i = 0;
    int x;
    vector<int> v;// En v leo el vector
    while (i<n){
        cin >> x;
        v.push_back(x);
        i++;
    }
    
    // Calculo el punto fijo de v
    int res = puntoFijo(v);
    
    // Imprimo la salida
    cout << res;
    
    return 0;
}
