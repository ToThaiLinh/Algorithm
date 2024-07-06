#include <bits/stdc++.h>
using namespace std;
/*
Input
10 8
1 2
2 3
2 4
3 6
3 7
5 8
6 7
8 9
*/

const int MAX = 1001;
vector<int> adj[MAX];
bool visited[MAX];
int n, m;

void input() {
    cin >> n >> m;
    for(int i = 1; i <=m ;i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    memset(visited, false, sizeof(visited));
}

void dfs(int u) {
    visited[u] = true;
    cout << u << " ";
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if(!visited[v]) {
            dfs(v);
        }
    }
}

void connectedComponent() {
    int ans = 0; 
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            ++ans;
            cout<<"Cac dinh thuoc thanh phan lien thong thu " << ans << " : ";
            dfs(i);
            cout << endl;
        }
    }
    cout <<"So thanh phan lien thong : " << ans << endl;
    if(ans == 1) {
        cout << "Do thi da cho lien thong"<<endl;
    }
    else {
        cout << "Do thi da cho khong lien thong" << endl;
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    connectedComponent();
    return 0;
}