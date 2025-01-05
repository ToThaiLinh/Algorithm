#include <bits/stdc++.h>
using namespace std;

const int MAX = 1001;
int n, m;
vector<int> adj[MAX];
bool visited[MAX];

void input() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}

//De quy 
void dfs(int u) {
    visited[u] = true;
    for(int i = 0; i < adj[u].size();i++) {
        int v = adj[u][i];
        if(!visited[v]) {
            dfs(v);
        }
    }
}

//Stack
void dfs(int u){
    stack<int> S;
    S.push(u);
    while(!S.empty()) {
        int x = S.top(); S.pop();
        visited[x] = true;
        for(int i = 0; i < adj[x].size(); i++) {
            int v = adj[u][i];
            if(!visited[v]) {
                S.push(v);
            }
        }
    }
}

int main() {
    input();
    dfs(1);
    return 0;
}