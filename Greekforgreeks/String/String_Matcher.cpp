#include <iostream>
using namespace std;

const int MAX = 100;

bool solve(char txt[], char pat[]) {
    int N = 0, M = 0;
    int i = 0;
    while(txt[i] != '\0') N++;
    int j = 0;
    while(pat[i] != '\0') M++;
    for(int i = 0; i <= N - M; i++) {
        int j;
        for(int j = 0; j < M; j++) {
            if(txt[i + j] != pat[j]) break;
        }
        if(j == M) return true;
    }
    return false;
}

int main() {
    //int n; 
    char txt[MAX];
    char pat[MAX];
    cin.getline(txt, 100);
    cin.getline(pat, 100);


    cout << txt << endl;
    cout << pat << endl;

    bool check = solve(txt, pat);
    cout << check << endl;
    
}