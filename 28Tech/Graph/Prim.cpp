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
}

void prim(int u) {
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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    prim(1);
    return 0;
}