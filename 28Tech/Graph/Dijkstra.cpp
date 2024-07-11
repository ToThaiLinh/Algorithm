#include <bits/stdc++.h>
using namespace std;

/*
input
5 7
2 5 87
1 2 97
4 5 78
3 1 72
1 4 19
2 3 63
5 1 18
1 5

output
97
*/

const int MAX = 1001;
int n, m, st, en;
vector< pair<int, int> > adj[MAX];
int d[MAX];
int parent[MAX];

void input() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int x, y, w; cin >> x >> y >> w;
        adj[x].push_back(make_pair(y, w));
        //adj[y].push_back(make_pair(x, w));
    }
    cin >> st >> en;
}

void dijkstra(int s) {
    priority_queue< pair<int, int> , vector< pair<int, int> > , greater< pair<int, int> > > Q;
    d[s] = 0;
    for(int i = 1; i <= n; i++) {
        if(i != s) d[i] = INT_MAX;
    } 
    Q.push(make_pair(0, s));
    while(!Q.empty()) {
        pair<int, int> top = Q.top();
        Q.pop();
        int dinh = top.second, khoangcach = top.first;

        if(khoangcach > d[dinh]) continue;

        for(int i = 0; i < adj[dinh].size(); i++) {
            int v = adj[dinh][i].first;
            int w = adj[dinh][i].second;
            if(d[v] > d[dinh] + w) {
                parent[v] = dinh;
                d[v] = d[dinh] + w;
                Q.push(make_pair(d[v], v));
            }            
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    dijkstra(st);
    // for(int i = 1; i <= n; i++) {
    //     cout << d[i] << " ";
    // }
    cout << d[en] << endl;
    return 0;
}