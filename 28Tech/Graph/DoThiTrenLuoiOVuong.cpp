#include <bits/stdc++.h>
using namespace std;
/*
dòng đầu nhập số hàng và số cột của lưới
output: số thành phần liên thông có ký tự x

input
6 6 
oxxooo
oxooxo
oooooo
oooooo
oooooo
oooooo

output
2

*/

const int MAX = 1001;
int n, m; // n hang, m cot
char a[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void input() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    memset(visited, false, sizeof(visited));
}

void bfs(int i, int j) {
    queue<pair<int, int>> Q;
    Q.push(make_pair(i, j));
    visited[i][j] = true;
    while(!Q.empty()) {
        int u = Q.front().first;
        int v = Q.front().second;
        Q.pop();
        for(int k = 0; k < 4; k++) {
            int i1 = u + dx[k];
            int j1 = v + dy[k];
            if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] == 'x' && !visited[i1][j1]) {
                Q.push(make_pair(i1, j1));
                visited[i1][j1] = true;
            }
        }
    }
}

void dfs(int i,int j) {
    visited[i][j] = true;
    for(int k = 0; k < 4; k++) {
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if( i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] == 'x' && !visited[i1][j1]) {
            dfs(i1, j1);
        }
    }
}

void connectedComponent() {
    int counter = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i][j] == 'x' && !visited[i][j]) {
                counter += 1;
                dfs(i, j);
            }
        }
    }
    cout << counter << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    connectedComponent();

    return 0;
}