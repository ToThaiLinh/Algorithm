#include <bits/stdc++.h>

using namespace std;

int main() {
    int a[] = {1, 5, 10, 25, 100}; //Các loại tiền
    int S[100]; // mảng S lưu trữ số lượng tiền thứ i cần đổi
    int money; //Số tiền cần đổi
    cin >> money;
    int size = sizeof(a) / sizeof(a[0]);
    for(int i = size - 1; i >= 0; i--) {
        S[i] = money / a[i];
        money = money % a[i]; 
    }
    cout<<"Nguoi thu ngan can tra:\n";
    for(int i = 0; i < size; i++) {
        cout<<S[i]<<" dong "<<a[i]<<endl;
    }
    return 0;

}