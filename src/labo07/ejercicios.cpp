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

bool esTriangular(const vector<vector<int>> &m){
	return es_triangular_inferior(m) || es_triangular_superior(m);
}

bool es_triangular_inferior(const vector<vector<int>> &m){
    bool res = true;
    for (int i = 0; i < m.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            res = res && (m[i][j]==0);
        }
    }
    return res;
}

bool es_triangular_superior(const vector<vector<int>> &m){
    bool res = true;
    for (int j = 0; j < m[0].size(); ++j) {
        for (int i = 0; i < j; ++i) {
            res = res && (m[i][j]==0);
        }
    }
    return res;
}

bool hayAmenaza(const vector<vector<int>> &m){
    for (int i = 0; i < m.size(); ++i) {
        for (int j = 0; j < m[0].size(); ++j) {
            if (m[i][j] && amenazaHorizontal(m, i, j)){
                return true;
            }else if (m[i][j] && amenazaDiagonal(m, i, j)){
                return true;
            }
        }
    }
	return false;
}

bool amenazaHorizontal(const vector<vector<int>> &m, int i, int j){
    // Inicializo el resultado
    bool res = false;

    // Guardo el tamaño de la matriz de entrada
    int rows = m.size();
    int columns = m[0].size();

    // Busco amenazas moviendome verticalmente
    int k = 0;
    while (k < rows && !res){
        res = res || (k != i && m[k][j]);
        k++;
    }

    // Busco amenazas moviendome horizontalmente
    int l = 0;
    while (l < columns && !res){ // No entra si hay amenazas verticales
        res = res || (l != j && m[i][l]);
        l++;
    }

    return res;
}

bool amenazaDiagonal(const vector<vector<int>> &m, int i, int j){
    // Inicializo el resultado
    bool res = false;

    // Guardo el tamaño de la matriz de entrada
    int rows = m.size();
    int columns = m[0].size();

    // Inicializo contadores
    int k = 1;
    int l = 1;

    // Recorro la diagonal descendente que pasa por (i, j)
    bool posicion_menor_valida = true;
    bool posicion_mayor_valida = true;

    while (posicion_menor_valida || posicion_mayor_valida) {

        // Chequeo que los elemento (i - k, j - k)
        posicion_menor_valida = (i - k >= 0) && (j - k >= 0);
        posicion_mayor_valida = (i + k < rows) && (j + k < columns);

        res = res || (posicion_menor_valida && m[i - k][j - k]) || (posicion_mayor_valida && m[i + k][j + k]);
        k++;
    }

    // Recorro la diagonal ascendente que pasa por (i, j)
    bool posicion_menor_valida_asc = true;
    bool posicion_mayor_valida_asc = true;

    while (posicion_menor_valida_asc || posicion_mayor_valida_asc) {

        // Chequeo que los elemento (i - k, j - k)
        posicion_menor_valida_asc = (i - k >= 0) && (j - k >= 0);
        posicion_mayor_valida_asc = (i + k < rows) && (j + k < columns);

        res = res || (posicion_menor_valida_asc && m[i - k][j - k]) || (posicion_mayor_valida_asc && m[i + k][j + k]);
        l++;
    }

    return res;
}


int diferenciaDiagonales(const vector<vector<int>> &m) {
    int res = abs(sumaDiagonalAscendente(m) - sumaDiagonalDescendente(m));
    return res;
}

int sumaDiagonalDescendente(const vector<vector<int>> &m){
    int suma = 0;
    for (int i = 0; i < m.size(); ++i) {
        suma += m[i][i];
    }
    return suma;
}

int sumaDiagonalAscendente(const vector<vector<int>> &m){
    int suma = 0;
    int length = m.size();
    for (int i = 0; i < length; ++i) {
        suma += m[i][length - 1 - i];
    }
    return suma;
}