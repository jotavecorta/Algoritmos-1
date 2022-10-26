#include <vector>
#include <iostream>

using namespace std;

int indiceMinSubsec(vector<int> v, int l, int r){
	int i = l + 1;
	int res = l;

	while (i <= r){
		if (v[i] <= v[res]){
			res = i;
		}
		i++;
	}

	return res;
}

void ordenar1(vector<int>& v){
	int n = v.size();
	
	for (int i = 0; i < n; i++){
		
		int min_index = indiceMinSubsec(v, i, n - 1);
		
		if (min_index != i){
			swap(v[i], v[min_index]);
		}
	}
}

int main() {
    /* No hace falta modificar el main */
    
    // Leo las entradas
    int n; //Longitud del vector
    cin >> n;
    int i = 0;
    int x;
    vector<int> v;// En v leo el vector
    while (i<n){
        cin >> x;
        v.push_back(x);
        i++;
    }

    // Hago el ordenamiento
    ordenar1(v);
    
    // Imprimo el vector resultado
    i = 0;
    while (i < v.size()){
        cout << v[i] << " ";
        i++;
    }
    
    return 0;
}
