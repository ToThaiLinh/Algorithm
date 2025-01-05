#include <bits/stdc++.h>
using namespace std;

struct segment {
    int x, y;
    segment(int x, int y) {
        this -> x = x;
        this -> y = y;
    }
};

bool comp(const segment& a, const segment& b) {
    if(a.y != b.y) return a.y < b.y;
    else return a.x < b.x;
}

int main() {
    int n;
    cin >> n;
    int x, y;
    vector<segment> a;
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        segment temp(x, y);
        a.push_back(temp);
    }

    sort(a.begin(), a.end(), comp);
    // for(vector<segment>::iterator it = a.begin(); it != a.end(); it++) {
    //     cout<<it -> x << " " << it -> y <<" ";
    // }
    // cout<<"\n";

    vector<segment> res;
    int last = -1e9;
    for(int i = 0; i < a.size(); i++) {
        if(last < a[i].x) {
            res.push_back(a[i]);
            last = a[i].y;
        }
    }
    cout<<res.size();
}