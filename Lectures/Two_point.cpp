#include <bits/stdc++.h>

using namespace std;

//Tìm trong dãy không âm a1, a2,..., an sắp xếp theo thứ tự tăng dần (đôi một khác nhau) số cặp (i, j) sao cho a[i] + a[j] = Q;
/*nếu có 2 số giống nhau sẽ xảy ra trường hợp 
int a[] = {1, 3, 4, 4, 5, 6, 7, 9};
cout<<solve1(a, sizeof(a)/sizeof(a[0]), 5)<<endl;
cout<<solve2(a, sizeof(a)/sizeof(a[0]), 5);
In ra   2
        1
*/

//Thuật toán trực tiếp O(n2)
int solve1(int a[], int n, int Q) {
    int res = 0; 
    for(int i = 0; i < n - 1; i++) {
        for(int j = i; j < n; j++) {
            if(a[i] + a[j] == Q) res++;
        }
    }
    return res;
}

//Kỹ thuật dùng 2 con trỏ
int solve2(int a[], int n, int Q) {
    int res = 0;
    int i = 0, j = n - 1;
    while(i < j) {
        if(a[i] + a[j] == Q) {
            res++;
            i++;
            j--;
            
        }
        else if(a[i] + a[j] < Q) {
            i++;
        }
        else j--;
    }
    return res;
}

//Cải tiến cho trường hợp 2 số giống nhau
int solve3(int a[], int n, int Q) {
    int res = 0;
    int i = 0, j = n-1;
    while(i < j) {
        if(a[i] + a[j] == Q) {
            res++;
            while((i < j) && (a[i] == a[i + 1])){
                res++;
                i++;
            }
            while((i < j) && (a[j] == a[j-1])) {
                res++;
                j--;
            }
            i++;
            j--;
        }
        else if(a[i] + a[j] < Q) i++;
        else j--;
    }
    return res;
}

int main() {
    int a[] = {1, 3, 4, 4, 5, 6, 7, 9};
    cout<<solve1(a, sizeof(a)/sizeof(a[0]), 5)<<endl;
    cout<<solve2(a, sizeof(a)/sizeof(a[0]), 5)<<endl;
    cout<<solve3(a, sizeof(a)/sizeof(a[0]), 5)<<endl;
    return 0;
}