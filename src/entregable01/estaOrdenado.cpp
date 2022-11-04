#include <iostream>
#include <vector>

using namespace std;

bool estaOrdenado(const vector<int> &v){
    // Primero chequeo que tenga elementos
    if (v.size() == 0){
        return true;
    }
    
    // Recorro los elementos de v
    for (int i = 0; i < v.size() - 1; i++){
        
        if (v[i] <= v[i + 1]){
            
            // Si está ordenado crecientemente continua
            continue;

        }else{ // No está ordenado crecientemente

            // Chequeo si está ordenado decrecientemente
            for (int i = 0; i < v.size() - 1; i++){
                
                if (v[i] >= v[i + 1]){
                
                    // Si está ordenado decrecientemente continua
                    continue;
                
                }else{
                
                    // Sale del loop con un false si algún elemento no cumple
                    return false;
                
                }
            }              
        }        
    } 
    
    return true;    
}
    
int main() {
    /* No hace falta modificar el main */
    // Leo las entradas
    int n; 
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
    bool res = estaOrdenado(v);
    
    // Imprimo la salida
    cout << (res?"True":"False");
    
    return 0;
}
