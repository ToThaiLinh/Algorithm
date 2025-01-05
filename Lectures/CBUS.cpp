#include <bits/stdc++.h>
using namespace std;


const int maxN = 20; // sô khách hàng tối đa
const int inf = INT_MAX;

int n, K, c_min = inf;
long long fopt, f;
int x[maxN * 2 + 2];
int c[maxN * 2 + 1][maxN* 2 + 1];
bool visited[maxN * 2 + 1];
int load = 0;

void input() {
    cin >> n >> K;
    for(int i = 0; i <= 2 * n; i++) {
        for(int j = 0; j <= 2 * n; j++) {
            cin >> c[i][j];
            if(i != j && c_min > c[i][j]) {
                c_min = c[i][j];
            }
        }
        visited[i] = false;
    }
    fopt = inf;
    f = 0;
    x[0] = 0;
}

bool UCV(int i) {
    if(visited[i]) return false;
    if(i > n) {
        if(visited[i - n] == false) return false;
    }
    else {
        if(load + 1 > K) return false;
    }
    return true;
}

void Try(int k) {
    for(int i = 1; i <= 2 * n; i++) {
        if(UCV(i)) {
            x[k] = i;
            visited[i] = true;
            if (i <= n) load += 1;
            else load -= 1;
            f += c[x[k - 1]][x[k]];
            if (k == 2 * n) {
                fopt = min(fopt, f + c[x[k]][0]);
            }
            else if (f + c_min * (2 * n - k + 1) < fopt) {
                Try(k + 1);
            }
            f -= c[x[k - 1]][x[k]];
            visited[i] = false;
            if (i <= n) load -= 1;
            else load += 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    Try(1);
    cout << fopt << "\n";
    return 0;
}
