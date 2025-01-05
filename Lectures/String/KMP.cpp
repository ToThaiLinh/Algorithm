#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

int counter = 0;
int lps[MAX];

void computeLps(string P) {
    int M = P.length();
    
   int len = 0;
   int i = 1;
   lps[0] = 0;
   while(i < M) {
       if(P[len] == P[i]) {
           len++;;
           lps[i] = len;
           i++;
       }
       else { // P[len] != P[i];
           if(len != 0) {
               len = lps[len - 1];
               //i not incremental
           }
           else { //len == 0
               lps[i] = 0;
               i++;
           }
       }
   }
}

void kmp(string P, string T) {
    int M = P.length();
    int N = T.length();
    
    int i = 0; 
    int j = 0;
    while ((N - i) >= (M - j)) {
        if (P[j] == T[i]) {
            j++;
            i++;
        }
 
        if (j == M) {
            counter += 1;
            printf("Found pattern at index %d \n", i - j);
            j = lps[j - 1];
        }
 
        // mismatch after j matches
        else if (i < N && P[j] != T[i]) {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}
    


int main() {
    string T;
    string P;
    getline(cin, T);
    getline(cin, P);
    kmp(P, T);
    cout << "Found " << counter << " index";
    return 0;
}