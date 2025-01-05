#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6;

void printArray(int a[], int n) {
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void merge(int a[], int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int L[n1], R[n2];
    for(int i = 0; i < n1; i++) {
        L[i] = a[l + i];
    }
    for(int j = 0; j < n2; j++) {
        R[j] = a[mid + 1 + j];
    }
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            a[k] = L[i];
            i++;
            k++;
        }
        else {
            a[k] = R[j];
            j++;
            k++;
        }
    }
    while(i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }
    while(j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int l, int r) {
    if(l < r) {
        int mid = (r + l) / 2;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, r);
        merge(a, l, mid, r);
    }
    return;
}

int main() {
    int n;
    cin >> n;
    int a[MAX];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    printArray(a, n);
    mergeSort(a, 0, n - 1);
    printArray(a, n);
    return 0;
}