#include <bits/stdc++.h>
using namespace std;
/*
input 
10  11
1 2
1 3
1 5 
1 10
2 4
3 6
3 7
3 9
6 7
5 8 
8 9
*/

const int MAX = 1001;
bool visited[MAX];
vector<int> adj[MAX];
int n, m;

void input() {
    cin >> n >> m;
    for(int i = 1; i <=m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}

void bfs(int x) {
    queue<int> Q;
    Q.push(x);
    visited[x] = true;
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        cout << u << " ";
        for(int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if(!visited[v]) {
                Q.push(v);
                visited[v] = true;
            }
        }
    }
}

int main() {
    input();
    bfs(1);
    return 0;
}