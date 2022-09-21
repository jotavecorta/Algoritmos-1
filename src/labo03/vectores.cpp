#include "vectores.h"

// Función para probar en main.cpp si este módulo fue cargado correctamente
void holaModuloVectores(){
    cout << "El módulo vectores fue cargado correctamente" << endl;
}


/*divide: Dados un vector v y un int a, decide si a divide a todos los numeros de v*/
bool divide(vector<int> v, int a){
	int suma_resto = 0;
	
	// Sumo los restos: si a divide a todo v deben ser cero
	for (int i = 0; i < v.size(); i++){
		suma_resto += v[i] % a;
	}

	return suma_resto == 0;
}

/*mayor: Dado un vector v -no vacío-, devuelve el valor maximo encontrado*/
int mayor(vector<int> v){

	int maximo = v[0];

	for (int i = 1; i < v.size(); i++){
		if (v[i] > maximo){
			maximo = v[i];
		}
	}

	return maximo;
}

// //Ejercicio
vector<int> reverso(vector<int> v){
// 	// Dado un vector v, devuelve el reverso.
    vector<int> vector_reverso = v;
	int size = vector_reverso.size();
    
	if (v.size() > 0){
		for(int i = 0; i < size; i++){
			// Agrego el primer elemento al final del vector
			vector_reverso.push_back(vector_reverso[0]);

			// Elimino el primer elemento
			vector_reverso.erase(vector_reverso.begin());
    	}
	}
	return vector_reverso;
}

vector<int> rotar(const vector<int> &v, int k){
    
    vector<int> vector_rotado = v;
    
	if (v.size() > 0){
		for(int i = 0; i < k; i++){
			// Agrego el primer elemento al final del vector
			vector_rotado.push_back(vector_rotado[0]);

			// Elimino el primer elemento
			vector_rotado.erase(vector_rotado.begin());
    	}
	}

    return vector_rotado;
}

// //Ejercicio
bool esPrimo(int n){
	int divisores = 2;
	int suma = 0;
	
	while (divisores < n){
		if (n % divisores == 0){
			suma++;
		}
		divisores++;
	}

	return suma == 0;
}

vector<int> factoresPrimos(int n){
 	//que dado un entero devuelve un vector con los factores primos del mismo
	vector<int> factores;
	int count = 2;

	while (count < n){
		if ((esPrimo(count)) && (n % count == 0)){
			factores.push_back(count);
		}
		count++;
	}
	return factores;
}

// //Ejercicio
void mostrarVector(vector<int> v){
	//que dado un vector de enteros muestra por la salida estándar, el vector
	// Ejemplo: si el vector es <1, 2, 5, 65> se debe mostrar en pantalla [1, 2, 5, 65]
	int i = 0;
	
	cout << "[";

	// Imprimo el vector resultado
    while (i < v.size()){
        if (i == v.size() - 1){
			cout << v[i];
		}else{
			cout << v[i] << ", ";			
		}
		i++;
    }
	
	cout << "]";
}
