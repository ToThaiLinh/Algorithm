#include <bits/stdc++.h>
using namespace std;

map<int, int> mem;

int Fibo(int n) {
    if(n <= 2) return 1;
    if(mem.find(n) != mem.end()) return mem[n];
    else {
        mem[n] = Fibo(n - 2) + Fibo(n - 1);
    }
    return mem[n];
}

int main() {
    int n;
    cin >> n;
    cout<<Fibo(n);
    return 0;
}