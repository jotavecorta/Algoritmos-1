#include <iostream>
#include <string>

using namespace std;

string rotar(string s, int j) {
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

int main()
{
    /* No hace falta modificar el main */
    // Leo la entrada
    string s;
    int j;
    cin >> s >> j;
    
    string res = rotar(s, j);
    cout << res;
    return 0;
}
