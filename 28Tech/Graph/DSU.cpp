#include <bits/stdc++.h>
using namespace std;

/*
Disjoint set union
*/

const int MAX = 1001;
int parent[MAX];
int size[MAX];
int n; // Số đỉnh của đồ thị

void make_set() {
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
        size[i] = 1;
    }
}

int find(int v) {
    if(v == parent[v]) return v;
    return parent[v] = find(parent[v]);
}

void union_set(int a, int b) {
    int a = find(a);
    int b = find(b);
    if(a != b) {
        if(size[a] < size[b]) {
            parent[a] = b;
            size[b] += size[a];
        }
        else {
            parent[b] = a;
            size[a] += size[b];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}