#include <bits/stdc++.h>
using namespace std;

const int MAC = 10001;
int mem[10001][10001];
int a[10001], b[10001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    memset(mem, 0, sizeof(mem));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i] == b[j]) mem[i][j] = 1 + mem[i - 1][j - 1];
            else {
                mem[i][j] = max(mem[i - 1][j], mem[i][j - 1]);
            }
        }
    }
    cout << mem[n][m];
    return 0;
    
}