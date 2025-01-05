#include <bits/stdc++.h>
using namespace std;

int f(unsigned int x) {
    return 1;
}

int binary_search(int low, int hight) {
    while(low < hight) {
        int mid = (low + hight) / 2;
        if(f(mid) > 0) hight = mid;
        else low = mid + 1;
    }
    return low;
}

int main() {
    
}