#include <bits/stdc++.h>
using namespace std;
/*
Input: txt[] = “AABAACAADAABAABA”

pat[] = “AABA”
*/

int last[255] = {0};
int counter = 0;

void computeLast(string P) {
    int M = P.length();
    for(int i = M - 1; i >= 0; i--) {
        if(last[P[i]] == 0) {
            last[P[i]] = i;
        }
    } 
}

void boyerMoore(string P, string T) {
    computeLast(P);
    
    int M = P.length();
    int N = T.length();
    
    int s = 0;
    while(s <= N-M) {
        int j = M - 1;
        while(j >= 0 && T[j + s] == P[j]) j = j - 1;
        if(j == -1) {
            cout << "Pattern found in index: " << s << endl;
            s = s + 1;
            counter += 1;
        }
        else {
            int k = last[T[j + s]];
            s = s + (j - k > 1 ? j -k : 1);
        }
    }
    
}

int main() {
    string T, P;
    getline(cin, T);
    getline(cin, P);
    boyerMoore(P, T);
    cout << "Found " << counter << " index";
    return 0;
}