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
int parent[MAX];
int size[MAX];

struct edge {
    int u, v;
    int w;
};

typedef struct edge edge;
vector<struct edge> canh;

void make_set() {
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
        size[i] = 1;
    }
}

int find_set(int v) {
    if(v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

bool Union(int x, int y) {
    int a = find_set(x);
    int b = find_set(y);
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
    for(int i = 1; i <= m; i++) {
        int x, y, w; cin >> x >> y >> w;
        struct edge e;
        e.u = x; e.v = y; e.w = w;
        canh.push_back(e);
    }
    
}

bool cmp(struct edge a, struct edge b) {
    return a.w < b.w;
}

void kruskal() {
    //Tạo cây khung cực tiểu
    vector<struct edge> mst;
    int d = 0;
    sort(canh.begin(), canh.end(), cmp);
    for(int i = 0; i < m; i++) {
        if(mst.size() == n - 1) break;
        struct edge e = canh[i];
        if(Union(e.u, e.v)) {
            mst.push_back(e);
            d += e.w;
        }
    }
    if(mst.size() != n -1 ) cout << "Do thi khong lien thong\n";
    else {
        cout << "MST: " << d << endl;
        for(int i = 0; i < mst.size(); i++) {
            cout << mst[i].u << " "<< mst[i].v << " " << mst[i].w <<endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    make_set();
    kruskal();

    return 0;
}