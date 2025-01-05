#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 1;
int n;
int a[MAX];
int dp[MAX]; // dp[i] là dãy con tăng dài nhất tính đến phần tử thứ i

void input() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

void solve() {
    //Khởi tạo các dp[i] = 1 , mỗi phần tử của mảng là một dãy con tăng có độ dài là 1
    for(int i = 1; i <= n; i++) {
        dp[i] = 1;
    }

    //Duyệt qua các phần tử của mảng 
    //Tỉnh dp[i] = max(dp[i], dp[i - 1] + 1) nếu thỏa mãn điều kiện a[i] > a[j] với j : 1 -> i - 1, mảng bắt đầu từ 1
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j < i; j++ ) {
            if(a[i] > a[j]) {
                dp[i] = max(dp[i], dp[i - 1] + 1);
            }
        }
    }

    int res = *max_element(dp + 1, dp + n + 1);
    cout << res;
}

int main() {
   input();
   solve();
   return 0;
}
