#include "ejercicios.h"

vector<vector<int>> productoVectorial(const vector<int>& u, const vector<int>& v){
	// Guardo el tamaño de la matriz resultante
    int rows = u.size();
    int columns = v.size();

    // Inicializo la variable donde guardar el producto, llena de ceros
    int fill_value = 0;
    vector<vector<int>> res (rows, vector<int>(columns, fill_value));

    // LLeno las entradas de res con el producto de las componentes de u y v
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            res[i][j] = u[i] * v[j];
        }
    }

	return res;
}

void trasponer(vector<vector<int> > &m) {
    // Guardo el tamaño de la matriz resultante
    int rows = m.size();

    // LLeno las entradas de m con sus elementos traspuestos
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < i; j++){
            m[i][j] = m[i][j] + m[j][i];
            m[j][i] = m[i][j] - m[j][i];
            m[i][j] -= m[j][i];
        }
    }

}

vector<vector<int>> multiplicar(const vector<vector<int>> &m1, const vector<vector<int>> &m2){
    // Guardo el tamaño de la matriz producto
    int rows = m1.size();
    int columns = m2[0].size();

    // Inicializo la variable donde guardar el producto, llena de ceros
    int fill_value = 0;
    vector<vector<int>> res (rows, vector<int>(columns, fill_value));

    // LLeno las entradas de res con el producto de las componentes de u y v
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            for (int k = 0; k < m2.size(); k++){
                res[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

	return res;
}

vector<vector<int> > promediar(const vector<vector<int>> &m){
    // Guardo el tamaño de la matriz resultante
    int rows = m.size();
    int columns = m[0].size();

    // Inicializo la variable donde guardar el producto, llena de ceros
    int fill_value = 0;
    vector<vector<int>> res (rows, vector<int>(columns, fill_value));

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            res[i][j] = promedioVecinos(m, i, j);
        }
    }

    return res;
}

int promedioVecinos(const vector<vector<int>> &m, int i, int j){
    // Inicializo la suma de los vecinos y la cantidad
    int suma_vecinos = 0;
    int cant_vecinos = 0;

    // Guardo el tamaño de la matriz resultante
    int rows = m.size();
    int columns = m[0].size();

    for (int k = i - 1; k < i + 2; k++) {
        for (int l = j - 1; l < j + 2; l++) {
            if ((k>=0 && k < rows) && (l>=0 && l < columns)){
                // Entra si es vecino valido
                cant_vecinos++;
                suma_vecinos += m[k][l];
            }
        }
    }
    return suma_vecinos / cant_vecinos;
}

int contarPicos(const vector<vector<int>> &m){
    // Guardo el tamaño de la matriz resultante
    int rows = m.size();
    int columns = m[0].size();

    // Inicializo la variable donde guardar el producto, llena de ceros
    int picos = 0;

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            if (esPico(m, i, j)) {
                picos++;
            }
        }
    }

    return picos;
}

bool esPico(const vector<vector<int>> &m, int i, int j){
    bool res = true;

    // Guardo el tamaño de la matriz resultante
    int rows = m.size();
    int columns = m[0].size();

    for (int k = i - 1; k < i + 2; k++) {
        for (int l = j - 1; l < j + 2; l++) {
            if ((k!=i || l!=j) && (k>=0 && k < rows) && (l>=0 && l < columns)){
                // Entra si es vecino válido y es distinto de m(i, j)
                res = res && m[i][j] > m[k][l];
            }
        }
    }
    return res;
}

bool esTriangular(vector<vector<int> > m){
	//COMPLETAR
	return true;
}

bool hayAmenaza(vector<vector<int> > m){
	//COMPLETAR
	return true;
}

int diferenciaDiagonales(vector<vector<int> > m) {
    //COMPLETAR
    return 0;
}