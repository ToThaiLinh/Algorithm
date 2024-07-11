#include <bits/stdc++.h>
using namespace std;

/*
input 
6 9
1 2 12
1 3 4
2 3 1
2 4 5
2 5 3
3 5 2
4 5 3
4 6 10
5 6 8

output 
18
*/
const int MAX = 1001;
int n, m;
vector< pair<int, int> > adj[MAX];
bool used[MAX]; //used[i] = true : i thuoc tap V(MST), used[i] = false : i thuoc tap V
int parent[MAX], d[MAX];

struct canh{
    int x, y, w;
};

void input() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int x, y , w;
        cin >> x >> y >> w;
        adj[x].push_back(make_pair(y, w));
        adj[y].push_back(make_pair(x, w));
    }
    memset(used, false, sizeof(used));
    for(int i = 1; i <= n; i++) {
        d[i] = INT_MAX;
        parent[i] = -1;
    }
}

void prim2(int u) {
    vector<canh> MST; //cay khung
    int d = 0; // chieu dai cay khung
    used[u] = true;
    while(MST.size() < n - 1) {
        int min_w = INT_MAX;
        int X, Y;
        for(int i = 1; i <= n; i++) {
            if(used[i]) {
                for(int j = 0 ; j < adj[i].size(); j++) {
                    pair<int, int> c = adj[i][j];
                    if(!used[c.first] && c.second < min_w) {
                        min_w = c.second;
                        X = i; 
                        Y = c.first;
                    }
                }
            }
        }
        canh e; e.x = X; e.y = Y; e.w = min_w;
        MST.push_back(e);
        used[Y] = true;
        d += min_w;
    }
    cout << "MST : "<< d << endl;
    for(int i = 0 ;i < MST.size(); i++) {
        cout << MST[i].x << " " << MST[i].y << " " << MST[i].w << endl;
    }

}

void prim(int u) {
    priority_queue< pair<int, int> , vector< pair<int, int> >, greater< pair<int, int> > > Q;
    vector<canh> MST;
    int res = 0;
    Q.push(make_pair(0, u));
    while(!Q.empty()) {
        pair<int, int> top = Q.top(); Q.pop();
        int dinh = top.second, trongso = top.first;

        if(used[dinh]) continue;
        res += trongso;
        used[dinh] = true;
        canh e; e.x = parent[dinh]; e.y = dinh; e.w = trongso;
        if(u != dinh) MST.push_back(e);

        for(int i = 0; i < adj[dinh].size(); i++) {
            int v = adj[dinh][i].first;
            int w = adj[dinh][i].second;
            if(!used[v] && w < d[v]) {
                Q.push(make_pair(w, v));
                d[v] = w;
                parent[v] = dinh;
            }
        }
    }
    cout << "MST : " << res << endl;
    for(int i = 0; i < MST.size(); i++) {
        cout << MST[i].x << " " << MST[i].y << " " <<  MST[i].w << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    prim(1);
    return 0;
}