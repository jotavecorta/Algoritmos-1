#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <sstream>

using namespace std;

vector<vector<int>> productoVectorial(const vector<int>& u, const vector<int>& v);
void trasponer(vector<vector<int> > &m);
vector<vector<int>> multiplicar(const vector<vector<int>> &m1, const vector<vector<int>> &m2);
vector<vector<int> > promediar(const vector<vector<int>> &m);
int promedioVecinos(const vector<vector<int>> &m, int i, int j);
int contarPicos(const vector<vector<int>> &m);
bool esPico(const vector<vector<int>> &m, int i, int j);
bool esTriangular(vector<vector<int> > m);
bool hayAmenaza(vector<vector<int> > m);
int diferenciaDiagonales(vector<vector<int> > m);