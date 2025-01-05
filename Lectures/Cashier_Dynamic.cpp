#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int N = 20;
const int XMAX = 1e5 + 5;
int D[N], mem[N][XMAX];
//memset(mem, -1, sizeof(mem));

int MinCoin(int i, int x) {
    if(x < 0 || i == 0) return INF;
    if(x == 0) return 0;

    if(mem[i][x] == -1) return mem[i][x];
    int res = INF;
    res = min(res, 1 + MinCoin(1, x - D[i]));
    res = min(res, MinCoin(i - 1, x));
}



int main() {
    int money;
    cin >> money;

}