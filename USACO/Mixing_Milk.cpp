#include <bits/stdc++.h>

using namespace std;

const int N = 3;
const int TURN_NUM = 100;

int main() {
    //Khai báo 2 vector để lưu lượng của mỗi thùng và lượng sữa đang chứa trong mỗi thùng 
    vector<int> capacity(3);
    vector<int> milk(3);
    for(int i = 0; i < N; i++) {
        scanf("%d %d", &capacity[i], &milk[i]);
    }

    for(int i = 0; i < TURN_NUM; i++) {
        int bucket1 = (i % N);
        int bucket2 = (i + 1) % N;

        int atm = min(milk[bucket1], capacity[bucket2] - milk[bucket2] );

        milk[bucket1] -= atm;
        milk[bucket2] += atm;
    }

    for(int i = 0; i < N; i++) {
        printf("%d\n", milk[i]);
    }
}