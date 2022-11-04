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

/*reverso: Dado un vector v, devuelve el reverso.*/
vector<int> reverso(vector<int> v){

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

/*mostrarVector: dado un vector V de enteros muestra por la salida estándar, el vector. 
Ejemplo: si el vector es <1, 2, 5, 65> se debe mostrar en pantalla [1, 2, 5, 65]*/
void mostrarVector(vector<int> v){

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

// Ejercicios de lectura y escritura de archivos

/*leerVector: toma un string conteniendo el nombre de un archivo*/
vector<int> leerVector(string nombreArchivo){
	// Inicializamos el vector de salida y el archivo de entrada
	vector<int> vector_salida;
	ifstream file_in;

	// Inicializo el directorio de los datos (relativo)
	string data_dir = "../../data/";

	// abrimos el archivo y leemos los datos
	file_in.open(data_dir + nombreArchivo, ios::in); 

	if (!file_in.fail()){
		// Si el archivo existe y tenemos permisos de lectura
		int v = 0;

		while (file_in >> v){
			vector_salida.push_back(v);	
		}

	}else{
		// Caso contrario mostramos un mensaje de error
		cout << "Error: El archivo solicitado no existe "; 
		cout << "o no se tienen permisos de lectura sobre el mismo." << "\n";

		vector_salida.push_back(-999);
	}


	file_in.close();
		
	return vector_salida;
}	

/*guardarVector: toma un vector v y el nombre de un archivo -junto con su extensión- y
se escribe el vector en la última línea del archivo.*/
void guardarVector(const vector<int> &v, string nombreArchivo){
	// Inicializo el archivo de salida y el directorio con los datos
	ofstream out_file;
	string data_dir = "../../data/";

	// Abrimos el archivo y escribimos
	out_file.open(data_dir + nombreArchivo, ios_base::app);
	if (!out_file.fail()){
		// Si tenemos permiso de escritura
		int i = 0;
		
		out_file << "[";

		// Escribimos el vector 
		while (i < v.size()){
			if (i == v.size() - 1){
				out_file << v[i];
			}else{
				out_file << v[i] << ", ";			
			}
			i++;
		}
		
		out_file << "]";
		cout << "Guardado exitoso en: " << data_dir + nombreArchivo << "\n";

	}else{
		// Caso contrario mostramos un mensaje de error
		cout << "Error: No se poseen permisos de escritura sobre "; 
		cout << "el archivo o directorio solicitado." << "\n";		
	}

	// Cerramos el archivo
	out_file.close();
}	

int sumaVector(const vector<int> &v){
	int suma = 0;
	for (int i = 0; i < v.size(); i++){
		suma += v[i];
	}
	return suma;
}

/*elementoMedio: Dado un vector V de enteros encuentra el primer elemento de 
izquierda a derecha tal que los elementos a su izquierda suman más que los que
están a su derecha. 
Ejemplo: <1, 2, 3, 4> el resultado es 3 porque (1+2) < 3 + 4 y (1 + 2 +
3) > 4. */
int elementoMedio(const vector<int> &v){
	int idx = 0;
	int sum_izquierda = 0;
	int sum_derecha = sumaVector(v);

	while (sum_izquierda <= sum_derecha){		
		sum_izquierda += v[idx];
		sum_derecha -= v[idx];
		idx++;
	}

	return v[idx-1];
}

/*cantApariciones: Dado un archivo que contiene una lista de números, 
cuenta la cantidad de apariciones de cada uno y crea en un archivo
en el directorio con el mismo nombre del archivo de entrada -y extensión .out-, 
de manera de tener una línea por cada número encontrado, un espacio y su 
cantidad de apariciones.*/
void cantApariciones(string file_name){
	// Inicializo vectores para guardar elementos del archivo
	vector<int> elem_distintos;
	vector<int> v = leerVector(file_name + ".in");

	int apariciones = 0;

	// Directorio de salida
	string out_dir = "../../data/out/";

	// Abro el archivo de salida
	ofstream out_file;
	out_file.open(out_dir + file_name + ".out", ios_base::app);

	for (int i = 0; i < v.size(); i++){
		
		if (count(elem_distintos.begin(), elem_distintos.end(), v[i]) == 0){
			// Si es la primera vez que aparece ese elemento
			// Guardo en elementos distintos y cuento apariciones
			elem_distintos.push_back(v[i]);
			apariciones = count(v.begin(), v.end(), v[i]);
			
			// Escribo en el archivo de salida
			out_file << v[i] << " " << apariciones << "\n";
		}
	}

	out_file.close();
}


int cantidadAparicionesDePalabra(string nombreArchivo, string palabra){
	int cantidad_apariciones = 0;
	string data_dir = "../../data/";
	string word;
	
	// Inicializo un stream de entrada y abro el archivo
	ifstream in_file;
	in_file.open(data_dir + nombreArchivo, ios::in);

	// Chequeo que exista el archivo y leo palabra a palabra
	if (!in_file.fail()){
		while(in_file >> word){
			if (word == palabra){
				cantidad_apariciones++;
			}
		}	
	}
	return cantidad_apariciones;
}


