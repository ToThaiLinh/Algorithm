#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 1;

void printArray(int a[], int n) {
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout<<endl;
}

void merge(int a[], int l, int mid, int r) { 
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
}

void mergeSort(int a[], int i, int j) {
    if(i < j) {
        int mid = (i + j) / 2;
        mergeSort(a, i, mid);
        mergeSort(a, mid + 1, j);
        merge(a, i, mid, j);
    }
}

int main() {
    int n;
    cin >> n;
    int a[MAX];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    printArray(a, n);
    mergeSort(a, 0,  n - 1);
    printArray(a, n);
    return 0;
}