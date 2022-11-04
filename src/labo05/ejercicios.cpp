#include "ejercicios.h"


// Ejercicio 1
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

// Ejercicio 2
int mcd(int m, int n){
	int a = 1;
	int mcd = 1;

	while(a <= m && a <= n){
		if (m % a == 0 &&  n % a == 0){
			mcd = a;
		}
		a++;
	}

	return mcd;
}

// Ejercicio 3
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

// Ejercicio 4
void ordenar1(vector<int> &v){
	
	int n = v.size();
	
	for (int i = 0; i < n; i++){
		
		int min_index = indiceMinSubsec(v, i, n - 1);
		
		if (min_index != i){
			swap(v[i], v[min_index]);
		}
	}

}

// Ejercicio 5
void ordenar2(vector<int>& v){
	return;
}

// Ejercicio 6
tuple<int,int> division(int n, int d){
	return make_tuple(0,0);
}
