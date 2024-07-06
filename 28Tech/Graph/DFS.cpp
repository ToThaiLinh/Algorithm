#include <bits/stdc++.h>
using namespace std;

/*
input 
9 9
1 2
1 3
1 5
2 4
3 6
3 7
3 9
5 8
8 9 
*/
int n, m; 
vector<int> adj[1001];
bool visited[1001];

void input() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    memset(visited, false, sizeof(visited));
}

void dfs(int u) {
    cout << u << " ";
    visited[u] = true;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if(!visited[v]) {
            dfs(v);
        }
    }
}


int main() {
    input();
    dfs(1);
    return 0;
}