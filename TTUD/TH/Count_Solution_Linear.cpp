#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

int n, M;
int a[MAX];
int x[MAX];
int counter = 0, f = 0;
int t[MAX];

void input() {
    t[0] = 0;
    cin >> n >> M;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        t[i] = t[i - 1] + a[i];
    }
}

void Try(int k) {
    int b = (M - f - (t[n] - t[k])) / a[k];
    for(int v = 1; v <= b; v++) {
        x[k] = v;
        f += a[k] * x[k];
        if(k == n) {
            if(f == M) counter++;
        }
        else Try(k + 1);
        f -= a[k] * x[k];
    }
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    Try(1);
    cout<<counter;
}