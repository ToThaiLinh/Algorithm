#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6;

int MaxLeft(int a[], int i, int m) {
    int ans = a[m], sum = 0;
    for(int k = m; k >= i; k--) {
        sum += a[k];
        ans = max(ans, sum);
    }
    return ans;
}

int MaxRight(int a[], int m, int j) {
    int ans = a[m], sum = 0;
    for(int k = m; k <= j; k++) {
        sum += a[k];
        ans = max(ans, sum);
    }
    return ans;
}

int SubSeqMax(int a[], int i, int j) {
    if(i == j) return a[i];
    int mid = (i + j) / 2;
    int wL = SubSeqMax(a, i, mid);
    int wR = SubSeqMax(a, mid + 1, j);

    int wLM = MaxLeft(a, i, mid);
    int wMR = MaxRight(a, mid + 1, j);
    int wM = wLM + wMR;
    int res = max(max(wL, wR), wM);
    return res;

}

int main() {
    int n; 
    cin >> n;
    int a[MAX];
    for(int i = 1; i <=n; i++) {
        cin >> a[i];
    }
    int res = SubSeqMax(a, 1, n);
    cout<<res<<endl;
    return 0;
}