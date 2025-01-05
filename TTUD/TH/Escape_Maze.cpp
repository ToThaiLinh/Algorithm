#include <bits/stdc++.h>
using namespace std;

const int max_row = 1000, max_col = 1000;

const int next_x[] = {1, 0, -1, 0};
const int next_y[] = {0, 1, 0, -1};

int a[max_row][max_col];
int n, m, r, c;
int fopt = INT_MAX;


typedef struct POSITION {
    int x, y;
    int len;

    POSITION(int x, int y, int len = 0) {
        this -> x = x;
        this -> y = y;
        this -> len = len;
    }

}POSITION;

void input() {
    cin >> n >> m >> r >> c;
    r = r - 1;
    c = c - 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
}

inline int map1D(int x, int y, int n, int m) {
    return x * m + y;
}

bool isEscape(POSITION curPos) {
    return (curPos.x == 0 || curPos.x == n - 1 || curPos.y == 0 || curPos.y == m - 1);
}

void solve() {
    queue<POSITION> Q;
    set<int> isProcess;
    Q.push(POSITION(r, c, 0));
    isProcess.insert(map1D(r, c, n, m));
    
    while(!Q.empty()) {
        POSITION u = Q.front();
        Q.pop();
        if(isEscape(u)) {
            fopt = min(fopt, u.len);
        }
        
        if(u.len + (n - u.x + 1 + m - u.y + 1) >= fopt) {
            continue;
        }
        
        int curPosx = u.x;
        int curPosy = u.y;
        for(int i = 0; i < 4; i++) {
            int nextPosx = curPosx + next_x[i];
            int nextPosy = curPosy + next_y[i];
            if(a[nextPosx][nextPosy] == 0 && isProcess.find(map1D(nextPosx, nextPosy, n, m)) == isProcess.end()) {
                int lenNext = u.len + 1;
                POSITION nextPos = POSITION(nextPosx, nextPosy, lenNext);
                Q.push(nextPos);
                isProcess.insert(map1D(nextPosx, nextPosy, n, m));
            }
        }
        
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();
    if(fopt == INT_MAX) cout<< "-1";
    else cout<<fopt + 1;
    return 0;
}