#include <bits/stdc++.h>
using namespace std;

/*
input
10 6
5 4
5 2
10 2
10 7
5 3
10 1

output
3
*/

const int MAX = 1001;
int n, m;
vector<int> adj[MAX];
bool visited[MAX];
vector< pair<int, int> > dscanh;

void input() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        dscanh.push_back(make_pair(x, y));
    }
    //memset(visited, false, sizeof(visited));
}

void dfs(int u) {
    visited[u] = true;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if(!visited[v]) {
            dfs(v);
        }
    }
}

void dinhtru() {
    memset(visited, false, sizeof(visited));
    int ans = 0;
    int tplt = 0;
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            tplt++;
            dfs(i);
        }
    }
    cout << "Dinh tru : " << endl;
    for(int i = 1; i <= n; i++) {
        memset(visited, false, sizeof(visited));
        visited[i] = true;
        int dem = 0;
        for(int j = 1; j <= n; j++) {
            if(!visited[j]) {
                dem++;
                dfs(j);
            }
        }
        if(dem > tplt) {
            cout << i << " ";
            ans++;
        }
    }
    cout << endl;
    cout << ans << endl;
}

void dfs2(int u, int s, int t) {
    visited[u] = true;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if((u == s && v == t) || (u == t && v == s)) continue;
        if(!visited[v]) {
            dfs2(v, s, t);
        }
    }
}

void canhcau(){
    memset(visited, false, sizeof(visited));
    int ans = 0; 
    int tplt = 0;
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            tplt += 1; 
            dfs(i);
        }
    }
    cout << "Canh cau : "<< endl ;
    for(int i = 0; i < dscanh.size(); i++) {
        pair<int, int> canh = dscanh[i];
        int u = canh.first;
        int v = canh.second;
        int dem = 0;
        memset(visited, false, sizeof(visited));
        for(int j = 1; j <= n; j++) {
            if(!visited[j]) {
                dem += 1;
                dfs2(j, u, v);
            }
        }
        if(dem > tplt) {
            ans++;
            cout << u << " " << v << endl;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    //dinhtru();
    canhcau();

    return 0;
}