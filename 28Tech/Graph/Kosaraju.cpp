#include <bits/stdc++.h>
using namespace std;

/*
Thuật toán Kosaraju tìm số thành phần liên thông mạnh của đồ thị có hướng
Bước 1: Gọi thuật toán DFS trên đồ thị ban đầu và lưu trữ thứ tự duyệt các đỉnh vào 1 stack
Bước 2: Xây dựng đồ thị lật ngược của đồ thị ban đầu: Transpose graph
Bước 3: Lần lượt pop các đỉnh trong stack ở bước 1 và gọi thuật toán DFS để liệt kê các thành phần liên thông mạnh: Strong connected component: SCC

input
8 9
1 2
2 3
3 4
3 5
4 1
5 6
6 7
7 8
8 6
*/

const int MAX = 1001;
int n, m;
vector<int> adj[MAX];
vector<int> r_adj[MAX];
bool visited[MAX];
stack<int> S;

void input() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        r_adj[y].push_back(x);
    }
}

void dfs1(int u) {
    visited[u] = true;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if(!visited[v]){
            dfs1(v);
        }
    }
    cout << u << " ";
    S.push(u);
}

void dfs2(int u) {
    visited[u] = true;
    cout << u << " "; 
    for(int i = 0; i < r_adj[u].size(); i++) {
        int v = r_adj[u][i];
        if(!visited[v]) {
            dfs2(v);
        }
    }
}

void scc() {
    memset(visited, false, sizeof(visited));
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            dfs1(i);
        }
    }
    cout << endl;
    memset(visited, false, sizeof(visited));
    while(!S.empty()) {
        int u = S.top(); S.pop();
        if(!visited[u]) {
            dfs2(u);
            cout << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    scc();

    return 0;
}