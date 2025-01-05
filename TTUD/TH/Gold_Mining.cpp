#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 2;
int n, l1, l2;
int a[N], S[N];
int res = INT_MIN;

void input() {
    cin >> n >> l1 >> l2;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

void process() {
    deque<int> d;
    for(int i = 1; i <= n; i++) {
        while(!d.empty() && d.front() < i - l2) d.pop_front();
        
        int j = i - l1;
        if(j >= 1) {
            while(!d.empty() && S[d.back()] < S[j]) d.pop_back();
            d.push_back(j);
        }
        S[i] = a[i] + (d.empty() ? 0 : S[d.front()]);
        res = max(res, S[i]);
    }
    cout << res << '\n';
}

int main() {
    input();
    process();
    return 0;
}