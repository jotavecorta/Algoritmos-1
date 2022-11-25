#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int posicionMinima(vector<int> &v, int low, int high){
    int min = low;
    for (int j = low + 1; j < high; ++j) {
        if (v[j] < v[min]){
            min = j;
        }
    }
    return min;
}

void swap(vector<int> &v, int i, int j){
    if (i != j){
        v[i] = v[i] + v[j];
        v[j] = v[i] - v[j];
        v[i] = v[i] - v[j];
    }
}

void insert(vector<int> &v, int i){
    for (int j = i; j>0 && v[j] < v[j - 1] ; --j) {
        swap(v, j, j - 1);
    }
}

void insertionSort(vector<int> &arr){
    for(int i = 0; i < arr.size(); i++) {
        insert(arr, i);
    }
}

void selectionSort(vector<int> &arr){
    for (int i = 0; i < arr.size(); i++){
        int index_min = posicionMinima(arr, i, arr.size());
        swap(arr, i, index_min);
    }
}


//void ordenar(vector<int> &items){
//	//Poner aca una implementación de ordenar
//    selectionSort(items);
//    //insertionSort(items);
//}
void ordenar(vector<int> &items){
    // Poner aca una implementación de ordenar

    // Atencion: no todas las implementaciones son
    // suficientemente rápidas para resolver en el
    // tiempo máximo permitido de la prueba automatizada.
    // Elegir entre las implementaciones vistas en
    // clase.
    //
    // Observación:
    // No vale usar std::sort()
    for(int i = 0; i < items.size(); i++) {
        int j = i;
        while ( j>0 && items[j] < items[j - 1]) {
            swap(items[j], items[j - 1]);
            j--;
        }
    }
}


int bestFit(int W, vector<int> &items){
	multiset<int> restos;
	for(int i=0; i<(int)items.size(); ++i){
		restos.insert(W);
	}
	int res = 0;
	for(int i=0; i<(int)items.size(); ++i){
		multiset<int>::iterator it = restos.lower_bound(items[i]);
		int restoAct = *it;
		if(restoAct==W){
			res++;
		}
		restoAct -= items[i];
		restos.erase(it);
		restos.insert(restoAct);
	}
	return res;
}
void printear_vector(vector<int> &v){
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << "\t";
    }
    cout << "\n";
}

int main(){
    vector<int> v = {3,2,-17, 1,4};
    vector<int> w = {3,3,3,1};
    vector<int> x = {3,2,1,0};
    vector<int> y = {1};

    ordenar(v);
    cout << "vector v ordenado: ";
    printear_vector(v);

    ordenar(w);
    cout << "vector w ordenado: ";
    printear_vector(w);

    ordenar(x);
    cout << "vector x ordenado: ";
    printear_vector(x);

    ordenar(y);
    cout << "vector y ordenado: ";
    printear_vector(y);

//	int N, W, aux;
//
//	//Se levantan los items y la capacidad del contenedor
//	cout << "Se levantan los items y la capacidad del contenedor";
//	ifstream bpp("BPP.in");
//	bpp >> N >> W;
//	vector<int> items;
//	for(int i=0; i<N; ++i){
//		bpp >> aux;
//		items.push_back(aux);
//	}
//	bpp.close();
//	//Se corre best-fit
//	int cant1 = bestFit(W, items);
//	cout << "Con la idea bestFit, se consigue una asignacion con " << cant1 << " contenedores" << endl;
//
//	//Se ordenan los items
//	ordenar(items);
//	//Se corre best-fit-decreasing
//	int cant2 = bestFit(W, items);
//	cout << "Con la idea bestFitDecreasing, se consigue una asignacion con " << cant2 << " contenedores" << endl;
//
//	return 0;
}
