#include <string>
#include "auxiliares.h"

using namespace std;

int posicionEnAlfabeto(char c){
    return c - 'a';
}

void insert(string &s, int i){
    int j = i;
    while(j > 0 && posicionEnAlfabeto(s[j]) < posicionEnAlfabeto(s[j-1])){
        swap(s, j, j-1);
        j--;
    }
}

void insertionSort(string &s){
    for(int i = 0; i < s.size(); i++){
        insert(s, i);
    }
}

void selectionSort(string &s){
    int i = 0;
    while(i < s.size()){
        int min_element = min(s, i, s.size());
        swap(s, i, min_element);
        i++;
    }
}

int min(string &s, int i, int j){
    int res = i;
    int k = i + 1;
    while(k < j){
        if (posicionEnAlfabeto(s[k]) < posicionEnAlfabeto(s[res])){
            res = k;
        }
        k++;
    }
    return res;
}

void swap(string &s, int i, int j){
    if (i!=j){
        s[i] += s[j];
        s[j] = s[i] - s[j];
        s[i] -= s[j];
    }
}