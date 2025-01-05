#include <bits/stdc++.h>
using namespace std;

void pattern_search(string P, string T) {
    int M = P.length();
    int N = T.length();
    for(int i = 0; i <= N - M; i++) {
        int j;
        for(j = 0; j < M; j++) {
            if(T[i + j] != P[j]) {
                break;
            }
        }
        if(j == M) {
            cout << "Pattern found at index " << i << endl;
        }
    }
}

void pattern_search2(string P, string T) {
    int M = P.length();
    int N = T.length();
    int i = 0;
    int j = M - 1;
    while(j < N) {
        int k;
        int temp;
        for(k = i, temp = 0; k <= j, temp <= M - 1; k++, temp++) {
            if(P[temp] != T[k]) {
                break;
            }
        }
        if(k == (j + 1)) {
            cout << "Pattern found at index " << i <<endl;
        }
        i++; j++;
    }
}

int main() {
    string T;
    string P;
    getline(cin, T);
    getline(cin, P);
    pattern_search(P, T);
    return 0;
    
}