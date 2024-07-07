#include <bits/stdc++.h>
using namespace std;
/*
dòng đầu là số đỉnh, số cạnh
dòng tiếp theo la các cạnh của đồ thị
dòng cuối là đỉnh đầu và đỉnh cuối

input
10 8
1 2
2 3
2 4
3 6
3 7
6 7
5 8
8 9
1 7

output
1 2 3 6 7

*/

const int MAX = 1001;
int n, m, s, t;
vector<int> adj[MAX];
bool visited[MAX];
int parent[MAX];

void input() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int x, y; 
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cin >> s >> t;
}

void dfs(int u) {
    visited[u] = true;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if(!visited[v]) {
            parent[v] = u;
            dfs(v);
        }
    }
}

void bfs(int x) {
    queue<int> Q;
    Q.push(x);
    visited[x] = true;
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for(int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if(!visited[v]) {
                Q.push(v);
                visited[v] = true;
                parent[v] = u;
            }
        }
    }
}

void printPath(vector<int> path) {
    for(int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
    }
    cout << endl;
}

void Path(int s, int t) {
    memset(visited, false, sizeof(visited));
    memset(parent, 0, sizeof(parent));
    dfs(s);
    //bfs(s);
    if(!visited[t]) {
        cout << "Khong co duong di tu " << s << " toi " << t << endl;
    }
    else {
        cout << "Duong di tu " << s << " toi " << t << " la: ";
        vector<int> path;
        while(t != s) {
            path.push_back(t);
            t = parent[t];
        }
        path.push_back(s);
        reverse(path.begin(), path.end());
        printPath(path);
    }
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    Path(s, t);
    return 0;
}
