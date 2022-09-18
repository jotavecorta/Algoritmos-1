#include <iostream>
#include <vector>

using namespace std;

vector<int> rotar(const vector<int> &v, int k){
    
    vector<int> vector_rotado = v;
    
    for(int i = 0; i < k; i++){
        // Agrego el primer elemento al final del vector
        vector_rotado.push_back(vector_rotado[0]);

        // Elimino el primer elemento
        vector_rotado.erase(vector_rotado.begin());
    }

    return vector_rotado;
}

int main() {
    /* No hace falta modificar el main */
    // Leo las entradas
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

    return 0;
}
