#include <iostream>
#include <string>

using namespace std;

bool subsecuencia(string s1, string s2) {

    if (s1 > s2){
        return false;
    }

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

int main()
{
    /* No hace falta modificar el main */
    // Leo la entrada
    string s, t;
    cin >> s >> t;
    
    bool res = subsecuencia(s, t);
    cout << (res ? "true" : "false");
    return 0;
}

