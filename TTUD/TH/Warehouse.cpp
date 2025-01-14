#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 2;

int n, T, D, a[N], t[N];
int f[N][102];
int res = INT_MIN;

void input() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> T >> D;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= T; i++) {
        cin >> t[i];
    }
    
}

void solve() {
    for(int i = 1 ; i <= n; i ++) {
        for(int k = t[i]; k <= T; k++) {
            for(int j = max(0, i - D); j <= i - 1; j ++) {
                f[i][k] = max(f[i][k], f[j][k - t[i]] + a[i]);
            }
            res = max(res, f[i][k]);
        }
    }
    cout << res << "\n";

}

int main() {
    input();
    solve();
    return 0;
}