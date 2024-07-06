#include <bits/stdc++.h>
using namespace std;

// Ma trận kề 
// Danh sách cạnh 
// Danh sách kề

const int MAX = 101;
int n, m;
int a[MAX][MAX];

int main() {
    cin >> n >> m;
    int x, y;
    for(int i = 1; i <= m; i++) {
        cin >> x >> y;
        a[x][y] = a[y][x] = 1;
    }
    for(int i = 1; i <=n ; i++) {
        for(int j = 1; j <= n;j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}