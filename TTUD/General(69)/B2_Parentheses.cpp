#include <bits/stdc++.h>
using namespace std;

bool isFair(char a, char b) {
    switch (a) {
    case '(': return b == ')';
    case '[': return b == ']';
    case '{': return b == '}';
    }
    return false;
}


bool check(string input) {
    stack<char> S;
    int len = input.length();
    for(int i = 0; i < len; i++) {
        char c = input[i];
        if(c == '(' || c == '[' || c == '{') {
            S.push(c);
        }
        else if(c == ')' || c == ']' || c == '}') {
            if(S.empty() || !isFair(S.top(), c)) {
                    return false;
            }
            else S.pop();
        }
    }
    return S.empty();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string input;
    getline(cin, input);
    if(check(input)) cout << "1" ;
    else cout << "0";
}