#include <bits/stdc++.h> 
using namespace std;
//Tìm chỉ số phần tử nhỏ nhất trong dãy ai, a(i+1), a(i+2),...,aj

int RMQ(int a[], int first, int last) {
    int min_value = a[first];
    int min_index = -1;
    for(int i = first; i < last; i++) {
        if(a[i] < min_value) {
            min_value = a[i];
            min_index = i;
        }
    }
    return min_index;
 }

 int RMQ(int a[], int first, int last) {
    
 }

int main() {
    int a[] = {1, 2, 3, 7, 1, 0, -1, 7, 3, 9};
    cout<<RMQ(a, 2, 5)<<endl;
    return 0;

}