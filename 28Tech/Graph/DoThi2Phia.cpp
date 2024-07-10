#include <bits/stdc++.h>
using namespace std;

/*
input
5 4
1 2
3 2
4 3
4 5

output
*/

const int MAX = 1001;
int n, m;
vector<int> adj[MAX];
int color[MAX]; //1 tương ứng với màu đỏ, 2 tương ứng với màu xanh

void input() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(color, 0, sizeof(color));
}

bool bfs(int x) {
    queue<int> Q;
    Q.push(x);
    color[x] = 1;
    while(!Q.empty()) {
        int u = Q.front(); Q.pop();
        for(int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if(!color[v]) {
                color[v] = (color[u] == 1) ? 2 : 1;
                Q.push(v);
            }
            else if(color[u] == color[v]) {
                return false;
            }
        }
    }
    return true;
}

bool dfs(int u, int par) {
    color[u] = (color[par] == 1)? 2 : 1;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if(!color[v]) {
            if(!dfs(v, u)) return false;
        }
        else if(color[v] == color[u]) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    bool check = true;;
    for(int i = 1; i <= n; i++) {
        if(!color[i]) {
            if(!bfs(i)) {
                check = false;
                break;
            }
        }
    }
    if(check) {
        cout << "Do thi da cho la do thi 2 phia";
    }
    else {
        cout << "Do thi da cho khong phai la do thi 2 phia";
    }
    return 0;
}