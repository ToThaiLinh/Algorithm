#include <bits/stdc++.h>
using namespace std;

const int MAX = 101;

int cutRod_native(int a[], int n) {
    if(n == 0) return 0;
    int res = -9999;
    for(int i = 0; i < n; i++) {
        res = max(res, a[i] + cutRod_native(a, n - i - 1));
    }
    return res;

}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tc, T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++) {
        int n; cin >> n;
        int a[MAX];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int res;

        //Theo cách đệ quy thông thường
        res = cutRod_native(a, n);

        cout << "#" << tc << " " << res << endl;
    }
    
    return 0;
}