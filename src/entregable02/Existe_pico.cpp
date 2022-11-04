#include <vector>
#include <iostream>

using namespace std;

bool existePico(vector<int> v){
	// Inicializo las variables del invariante
	int i = 1;
	bool res = false;
	
	// recorro los elementos del vector
	while (i < v.size() - 1){
		res = res || (v[i] > v[i-1] && v[i] > v[i+1]);
		i++;
	}

	return res;
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
    
    // Evaluo si el vector v esta ordenado
    bool res = existePico(v);
    
    // Imprimo la salida
    cout << (res?"True":"False");
    
    return 0;
}
