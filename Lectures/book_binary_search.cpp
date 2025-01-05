#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e3;
 
int binary_search(int *sum, int low, int hight, int target) {
    // tìm giá trị j sao cho sum[j] <= target
    while( low <= hight) {
        int mid = (low + hight) / 2;
        if(sum[mid] == target) return mid;
        else if(sum[mid] < target) low = mid + 1;
        else hight = mid - 1;
    }
    return hight;
 
}

int main() {
    int result = INT_MIN;
    int n, t;
    cin >> n >> t;
    int time[MAX];
    int sum[MAX]; sum[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> time[i];
        sum[i] = sum[i - 1] + time[i];
    }

    for(int i = 1; i <= n; i++) {
        int j = binary_search(sum, i, n, t + sum[i] - time[i]);
        result = max(result, j - i + 1);
    }
    cout<< result << endl;
    return 0;

}