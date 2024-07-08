#include <bits/stdc++.h>
using namespace std;

/*
Đồ thị vô hướng, xác định có chu trình hay không 
input
7 6
1 2
2 3
2 4
3 6
3 7
6 7
*/


const int MAX = 1001;
int n, m, st, en;
vector<int> adj[MAX];
bool visited[MAX];
int parent[MAX];
int color[MAX];
int in[MAX]; // bán bậc vào của một đỉnh 

void input() {
    memset(in, 0, sizeof(in));
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y); in[y] += 1;
        adj[y].push_back(x); // Nếu là đồ thị có hướng thì không cần dòng này
    }
    memset(visited, false, sizeof(visited));
    memset(parent, 0, sizeof(parent));
    memset(color, 0, sizeof(color));
}

bool DFS(int u) {
    visited[u] = true;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if(!visited[v]) {
            parent[v] = u;
            if(DFS(v)) return true;
        }
        else if (v != parent[u]) {
            st = v;
            en = u;
            return true;
        }
    }
    return false;
}

//Áp dụng đối với đồ thị có hướng
bool DFS2(int u) {
    color[u] = 1;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if(color[v] == 0) {
            parent[v] = u;
            if(DFS2(v)) return true;
        }
        else if (color[v] == 1) {
            st = v;
            en = u;
            return true;
        };
    }
    color[u] = 2;
    return false;
}

// Đối với BFS khó có thể truy vết
bool BFS(int x) {
    queue<int> Q;
    Q.push(x);
    visited[x] = true;
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for(int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if(!visited[v]) {
                parent[v] = u;
                visited[v] = true;
                Q.push(v);
            }
            else if (v != parent[u]) {
                return true;
            }
        }
    }
    return false;
}

//Thuật toán Kahn cho đồ thị có hướng
bool Kahn() {
    queue<int> Q;
    int counter = 0;
    for(int i = 1; i <= n; i++) {
        if(in[i] == 0) Q.push(i);
    }
    while(!Q.empty()) {
        int u = Q.front(); Q.pop();
        counter += 1;
        for(int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            in[v] -= 1;
            if(in[v] == 0) Q.push(v);
        }
    }
    if(counter == n) return true;
    else return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    // if(DFS(1, 0)) {
    //     cout << "YES";
    // }
    // else cout << "NO";
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            if(DFS(i)) {
                cout << "YES\n";
                vector<int> cycle;
                cycle.push_back(st);
                while(en != st) {
                    cycle.push_back(en);
                    en = parent[en];
                }
                cycle.push_back(st);
                reverse(cycle.begin(), cycle.end());
                for(int i = 0; i < cycle.size(); i++) {
                    cout << cycle[i] << " ";
                }
                cout << endl;
                return 0;
            }
        }
    }
    cout << "NO";

    return 0;
}