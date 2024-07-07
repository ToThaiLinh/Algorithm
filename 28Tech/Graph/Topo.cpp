#include <bits/stdc++.h>
using namespace std;

/*
Đồ thị có hướng
input 
7 7 
1 2
2 3
2 4
3 5
4 5
1 6
7 6

output
7 1 6 2 4 3 5
*/

const int MAX = 1001;
int n, m;
vector<int> adj[MAX];
bool visited[MAX];
vector<int> topo;

void input() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    memset(visited, false, sizeof(visited));
}

void dfs(int u) {
    visited[u] = true;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if(!visited[v]) {
            dfs(v);
        }
    }
    topo.push_back(u);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            dfs(i);
        }
    }
    reverse(topo.begin(), topo.end());
    for(int i = 0; i < topo.size(); i++) {
        cout << topo[i] << " ";
    }

    return 0;
}