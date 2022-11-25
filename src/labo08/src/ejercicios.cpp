#include <algorithm>
#include "ejercicios.h"

/* Para compilar */ 

using namespace std;

vector<string> split(string s, char delim){
	vector<string> v;
	return v;
}

string darVueltaPalabra(string s){
	string res;
	return res;
}

// Decidir si s1 es substring o subsecuencia de s2
bool isWhitespace(unsigned char c) {
    if (c == ' ' || c == '\t' || c == '\n' ||
        c == '\r' || c == '\f' || c == '\v') {
        return true;
    } else {
        return false;
    }
}


bool subsecuencia(string s1, string s2) {

    if (s1 > s2){
        return false;
    }

    // Quito posibles espacios entre los caracteres de los strings
    s1.erase(remove_if(s1.begin(), s1.end(), isWhitespace),
            s1.end());

    s2.erase(remove_if(s2.begin(), s2.end(), isWhitespace),
             s2.end());

    int i = 0;
    int count = 0;

    while (i < s2.size() && count < s1.size()) {
            if (s2[i] == s1[count]){
                count++;
            }
            i++;
    }

	return count == s1.size();
}

// Mismo orden relativo de conjunto de anagramas y dentro de cada vector y con repetidos
vector<vector<string> > agruparAnagramas(vector<string> v){
	vector<vector<string> > res;
	return res;
}

bool esPalindromo(string s){
	bool cumple = true;
	return cumple;
}

bool tieneRepetidos(string s){
	bool distinto = true;
	return !distinto;
}

string rotar(string s, int j){
	string res (s);

    if (s.size() > 0){
        for(int i = 0; i < j; i++){
            // Agrego el primer elemento al final del vector
            char ultimoElemento = res.back();
            res.insert(res.begin(), ultimoElemento);

            // Elimino el primer elemento
            res.pop_back();
        }
    }

	return res;
}

// no se puede usar substring
string darVueltaK(string s, int k){
	string res(s);
	return res;
}

string abueloLaino(string s){
    string res = "S";
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'i'){
            res = "N";
        }
    }
    return res;
}

int cantidadDeFelicitaciones(vector<string> v){
    int res;
    return res;
}

int middleOut(string s, string t){

    return 0;
}
