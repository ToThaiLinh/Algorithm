#include <bits/stdc++.h>
#define MAX 1000

using namespace std;

int n, load, K;
int c[MAX][MAX];
int x[MAX];
int fopt = 0;
int visited[MAX] = {0};
int f;
int c_min = 1e18;


int UCV(int i) { // trả về true nếu xe đến được bến i
    if(i <= n) {// Khách hàng i lên xe tại điểm i
        return (!visited[i] && load < K);
    }
    else //Khách hàng (i - n) Xuống xe
        return (visited[i] && !visited[i - n]);
}

void input() {
    cin >> n >> K;
    int N = 2 * n;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> c[i][j];
            if(i != j && c_min < c[i][j]) c_min = c[i][j];
        }
    }
}

void Try(int k) {
    for(int v = 1; v <= 2 * n; v++) {
        if(UCV(v)) {
            if(v <= n) load++;
            else load--;
            visited[v] = 1;
            f = f + c[x[k - 1]][v];
            if(k == 2 * n) {
                if(fopt > f + c[x[k]][0]) fopt = f + c[x[k]][0];
            }
            else {
                int g = f + (2 * n + 1 - k) * c_min;
                if(g < fopt) Try(k + 1);
            }
            visited[v] = 0;
            f = f - c[x[k - 1]][v];
            if(v <= n) load--;
            else load++;   
        }
    }
}

int main() {
    input();
    Try(1);
    cout<<fopt<<endl;
    return 0;
}