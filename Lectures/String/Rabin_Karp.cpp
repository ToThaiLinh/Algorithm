#include <bits/stdc++.h>
using namespace std;
/*
Input: txt[] = “AABAACAADAABAABA”

pat[] = “AABA”
*/

const int Q = 255;
const int d = 256;

int counter = 0;

int hashCode(string P) {
    int hash = 0;
    for(int i = 0; i < P.length(); i++) {
        hash = hash * d + P[i];
        hash %= Q;
    }
    return hash;
}

int hashCode(string T, int start, int end) {
    int hash = 0;
    for(int i = start; i <= end; i++) {
        hash = hash * d + T[i];
        hash %= Q;
    }
    return hash;
}

void rabinKarp(string P, string T) {
    int M = P.length();
    int N = T.length();
    
    int codeP = hashCode(P);
    int codeT = hashCode(T, 0, M-1);
    
    int e = pow(d, M-1);
    
    bool ok = false;
    for(int s = 0; s <= N-M; s++) {
        if(codeP == codeT) {
            ok = true;
            for(int j = 0; j < M; j++) {
                if(T[j + s] != P[j]) {
                    ok = false;
                    break;
                }
            }
            if(ok) {
                cout << "Pattern found in index: " << s << endl;
                counter++;
            }
        }
        else {
            int t = T[s] * e;
            t %= Q;
            t = (codeT - t) % Q;
            codeT = (t*d + T[s+M]) % Q;
        }
    }
}

int main() {
    string T, P;
    getline(cin, T);
    getline(cin, P);
    rabinKarp(P, T);
    cout << "Found " << counter << " index";
    return 0;
}