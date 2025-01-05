#include <bits/stdc++.h>

using namespace std;

const int MAX_M = 11;
const int MAX_N = 31;

int x[MAX_N];
int n, m;
vector<int> T[MAX_N]; // danh sách giáo viên có thể dạy môn học thứ ni
int load[MAX_M] = {0}; // số môn được phân công cho giáo viên mi
bool conflic[MAX_N][MAX_N] = {false};
int res = 1e9;


void input() {
    cin >> m >> n;
    for(int t = 1; t <= m; t++) {
        int k;
        cin >> k;
        for(int i = 0; i < k; i++) {
            int c; 
            cin >> c;
            T[c].push_back(t);
        }
    }
    int K;
    cin >> K;
    for(int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        conflic[x][y] = true;
        conflic[y][x] = true;
    }

}

bool check(int t, int k) {
    for(int i = 1; i <= k - 1; i++) {
        if(conflic[i][k] && x[i] == t) return false;
    }
    return true;
}

void solution() {
    int maxLoad = 0; 
    for(int t = 1; t <= m; t++) {
        maxLoad = max(maxLoad, load[t]);
    }
    if(res > maxLoad) res = maxLoad; // Cập nhật kết quả cuối cùng
}

void Try(int k) {
    for(int i = 0; i < T[k].size(); i++) {
        int t = T[k][i];
        if(check(t, k)) {
            x[k] = t;
            load[t] += 1; 
            if(k == n) solution();
            else {
                 if(load[t] < res) Try(k + 1);
            }
            load[t] -= 1;;
        }
    }
}

int main() {
    input();
    Try(1);
    cout << res;
    return 0;

}