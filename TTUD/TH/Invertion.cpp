#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 1;
const int M = 1e9 + 7;

long long merge(int a[], int l, int mid, int r) {
    long long inv_count = 0; 
    int i = l;
    int j = mid + 1;
    int k = l;
    int tmp[r + 1];
    while(i <= mid && j <= r) {
        if(a[i] <= a[j]) {
            tmp[k++] = a[i++];
        }
        else {
            tmp[k++] = a[j++];
            inv_count += mid - i + 1;
        }
    }
    while(i <= mid) {
        tmp[k++] = a[i++];
    }
    while(j <= r) {
        tmp[k++] = a[j++];
    }
    for(int i = l; i <= r; i++) {
        a[i] = tmp[i];
    }
    return inv_count % M;
}

long long mergeSort(int a[], int i, int j) {
    long long inv_count = 0;
    if(i < j) {
        int mid = (i + j) / 2;
        inv_count += mergeSort(a, i, mid);
        inv_count += mergeSort(a, mid + 1, j);
        inv_count += merge(a, i, mid, j);
    }
    return inv_count % M;
}

int main() {
    int n;
    scanf("%d", &n);
    int a[MAX];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int res = mergeSort(a, 0,  n - 1);
    cout<< res % M;
    return 0;
}