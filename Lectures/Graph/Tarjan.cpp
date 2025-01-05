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

void dfs() {
    
}

int main() {
    input();

    return 0;
}
