#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, L;
    cin >> n >> L;
    string input;
    while(n--) {
        cin >> input;
        while(input.length() < L) input = "0" + input;
        cout << input << endl;
    }
    return 0;
}