#include <bits/stdc++.h>

using namespace std;

int main() {
    int numberTest, n, m, counter = 0;
    int x;
    map<int, int> r;
    scanf("%d", &numberTest);
    while(counter != numberTest) {
        scanf("%d %d", &n, &m);
        while(n--) {
            scanf("%d", &x);
            r[x]++;
        }
        while(m--) {
            scanf("%d", &x);
            r[x]--;
        }
        int sopheptinh = 0;
        for(map<int, int>::iterator it = r.begin(); it != r.end(); it++) {
            sopheptinh += abs(it -> second);
        }
        cout<<sopheptinh<<endl;
        counter++;
    }
    return 0;
}