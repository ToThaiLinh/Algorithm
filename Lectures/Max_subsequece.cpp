#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> mem(n + 1);
    mem[0] = -1e9;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        mem[i] = max(a[i], mem[i - 1] + a[i]);
    }

    int ans = 0, pos = -1; 
    for(int i = 1; i <= n; i++) {
        if(ans < mem[i]) {
            ans = mem[i];
            pos = i;
        }
    }
    cout<< ans <<endl;

    int left = pos, right = pos, sum = a[left];
    while(sum != ans) {
        left--;
        sum += a[left];
    }
    cout<< left << ' ' << right;
    return 0;
}