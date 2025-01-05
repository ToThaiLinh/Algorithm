#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e3 + 2;
const int MAX_K = 401;
const int MOD = 1e9 + 7;
int N, K1, K2, res;
int f[MAX_N][2];

void input() {
    cin >> N >> K1 >> K2;
}

void process() {
    f[0][0] = f[0][1] = 1;
    for(int i = 1; i <= N; i++) {
        for(int j = K1; j <= K2; j++) {
            if(i - j < 0) break;
            f[i][1] += f[i - j][0];
            f[i][1]  %= MOD;
        }
        f[i][0] = f[i - 1][1];
    }
    res = (f[N][1] + f[N][0]) % MOD;
}

int main() {
    input();
    process();
    cout << res;
}