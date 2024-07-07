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
*/

const int MAX = 1001;
int n, m;
vector<int> adj[MAX];
bool visited[MAX];
int in[MAX];
vector<int> topo;

void input() {
    memset(in, 0, sizeof(in));
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        in[y] += 1;
    }
    memset(visited, false, sizeof(visited));
}


void Kahn() {
    queue<int> Q;
    for(int i = 1; i <= n;i++) {
        if(in[i] == 0) {
            Q.push(i);
        }
    }
    while(!Q.empty()) {
        int u = Q.front(); Q.pop();
        topo.push_back(u);
        for(int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            in[v] -= 1;
            if(in[v] == 0) {
                Q.push(v);
            }
        }
    }
    for(int i = 0; i < topo.size(); i++) {
        cout << topo[i] << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    Kahn();

    return 0;
}