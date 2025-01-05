#include <bits/stdc++.h>
using namespace std;

const int maxRow = 1000, maxCol = 1000;
const int INF = 1e9;

int n, m;
int a[maxRow][maxCol];
int D[maxRow][maxCol] = {0};

void input() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
}

int lagestRectangle(int *his, int n) {
    int max_area = -INF;
    int leftSmaller[n], rightSmaller[n];
    stack< int> s;
    for(int i = 0; i < n; i++) {
        while(!s.empty() && his[s.top()] >= his[i]) {
            s.pop();
        }
        if(s.empty()) leftSmaller[i] = 0;
        else leftSmaller[i] = s.top() + 1;

        s.push(i);
    }

    while(!s.empty()) s.pop();

    for(int i = n - 1; i >= 0; i--) {
        while(!s.empty() && his[s.top()] >= his[i]) {
            s.pop();
        }
        if(s.empty()) rightSmaller[i] = n - 1;
        else rightSmaller[i] = s.top() - 1;

        s.push(i);
    }
    int temp;
    for(int i = 0; i < n; i++) {
        temp = his[i] * (rightSmaller[i] - leftSmaller[i] + 1);
        if(temp > max_area) max_area = temp;
    }
    return max_area;
}

int solve() {
    int max_area = -INF;
    int temp;
    for(int i = 0; i < n; i++) D[0][i] = a[0][i];
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == 1) D[i][j] = D[i - 1][j] + a[i][j];
        }
        
    }
    for(int i = 0; i < n; i ++) {
        temp = lagestRectangle(D[i], m);
        if(max_area < temp) max_area = temp;
    }
    return max_area;
}
int main() {
    input();
    cout<<solve();
    return 0;
}