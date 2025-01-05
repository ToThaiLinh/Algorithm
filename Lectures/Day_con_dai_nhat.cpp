#include <bits/stdc++.h>

using namespace std;
/* Bài toán cho dãy số không âm a1, a2,..., an. Cho trước giá trị Q.
Tìm dãy con (một số phần tử liên tiếp) dài nhất có tổng nhỏ hơn hoặc bằng Q*/

//Thuật toán trực tiếp
int solve1(int a[], int n, int Q) {
    int res = 0; // độ dài dãy con
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += a[j];
            if(sum <= Q)
                res = max(res, j - i + 1);
            }
    }
    return res;   
}

//Kỹ thuật sử dụng 2 con trỏ
int solve2(int a[], int n, int Q) {
    int res = 0;
    int L = 0;
    int sum = 0;
    for(int R = 0; R < n; R++) {
        sum += a[R];
        while(sum > Q) {
            sum -= a[L];
            L++;
        }
        res = max(res, R - L + 1);
    }
    return res;
}

int main() {
    int a[] = {1, 10, 2, 3, 5, 1, 7, 8, 9};
    int n = sizeof(a)/sizeof(a[0]);
    cout<<solve1(a, n, 10)<<endl;
    cout<<solve2(a, n, 10)<<endl;
    return 0;

}