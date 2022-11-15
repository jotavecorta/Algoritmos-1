#include <vector>
#include <iostream>

using namespace std;

int menorMasGrande(vector<int> v,int x){
    if (v.size() == 0) {// Caso trivial
        return -1;
    }else if(v.size() == 1){
        return -1;
    }else if (v[v.size() -1] < x){
        return -1;
    }else {
        int i = 0;
        while (v[i] <= x){
            i++;
        }
        if (i < v.size()){
            return i;
        }else{
            return -1;
        }

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
    cin >> x;
    
    // Evaluo si el vector v esta ordenado
    int res = menorMasGrande(v,x);
    
    // Imprimo la salida
    cout << res;
    
    return 0;
}
