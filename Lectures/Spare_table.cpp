#include <bits/stdc++.h>
using namespace std;

//LG là số lớn nhất thỏa mãn 2^LG < N
//ví dụ: N = 10^5 thì LG = 16 vì 2^16 = 65536
const int N = 1e5;
const int LG = 16;

int a[N], st[LG + 1][N];
int n;
void preprocess() {
    for(int i = 0; i <= n; i++) st[0][i] = a[i];
    for(int j = 1; j <= LG; j++) {
        for(int i = 1; i + (1 << j) - 1 <= n; ++i ){
            st[j][i] = min(st[j - 1][i], st[j - 1][i + (1 << (j -1))]);
        }
    }
}

int queryMin(int l, int r) {
    int k = log(r - l + 1);
    return min(st[k][l], st[k][r - (1 << k) + 1]);
}

int main() {
    int a[] = {};
    n = sizeof(a)/sizeof(a[0]);
    return 0;
}