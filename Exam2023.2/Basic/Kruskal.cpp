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


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1001;
int parent[MAX];
int size[MAX];
int n, m;

struct edge {
    int u, v;
    int w;
    edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
};

typedef struct edge edge;
vector<edge> canh;

void make_set() {
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
        size[i] = i;
    }
}

int find(int u) {
    if(parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}

bool Union(int u, int v) {
    int a = find(u);
    int b = find(v);
    if(a == b) return false;
    else {
        if(size[a] < size[b]) {
            parent[a] = b;
            size[b] += size[a];
        }
        else {
            parent[b] = a;
            size[a] += size[b];
        }
    }
    return true;
}

void input() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y, w; cin >> x >> y >> w;
        edge tmp(x, y, w);
        canh.push_back(tmp);
    }
}

bool cmp(const edge& a, const edge& b) {
    return a.w < b.w;
}

void kruskal() {
    vector<edge> mst;
    int d = 0;
    sort(canh.begin(), canh.end(), cmp);
    for(int i = 0; i < m; i++) {
        if(mst.size() == n - 1) break;
        edge top = canh[i];
        if(Union(top.u, top.v)) {
            d += top.w;
            mst.push_back(top);
        }
    }
    cout << d << endl;

    if(mst.size() != n - 1) cout << "Đồ thị không liên thông" << endl;
    else {
        cout << "MST : " << endl;
        for(int i = 0; i < mst.size(); i++) {
            edge e = mst[i];
            cout << e.u << " " << e.v << " " << e.w << endl;
        }
    }
    
}

int main() {
    input();
    make_set();
    kruskal();
    return 0;
}
