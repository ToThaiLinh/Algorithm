#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string input;
    set<string> info;
    while(true) {
        cin >> input;
        if(input == "*") break;
        info.insert(input);
    }
    string cmd, s;
    while(true) {
        cin >> cmd >> s;
        if(cmd == "***") break;
        if(cmd == "find") {
            if(info.find(s) != info.end()) {
                cout << "1" << endl;
            }
            else cout << "0" << endl;
        }
        if(cmd == "insert") {
            if(info.find(s) != info.end()) {
                cout << "0" << endl;
            }
            else {
                cout << "1" << endl;
                info.insert(s);
            }
        }
    }
    return 0;
}