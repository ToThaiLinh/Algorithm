#include <bits/stdc++.h>
using namespace std;


//cách trâu bò
/*Duyệt tòan bộ phần tử của mảng 
Đến mỗi phần tử thì tính toán chiều rộng bằng cách đi ra 2 bên đến phần tử bé hơn thì thôi
*/
int solve1(int his[], int n) {
    int max_area = his[0];
    int temp_area = 0;
    for(int i = 1; i < n; i++) {
        int left, right;
        left = i; right = i;
        while(his[i] <= his[left] && left >= 0) left--;
        while(his[i] <= his[right] && right < n) right++;
        int width = right - 1 - left - 1 + 1;
        temp_area = width * his[i];
        if(max_area < temp_area) max_area = temp_area;
    }
    return max_area;
}

//Cách tối ưu
int solve2(int his[], int n) {
    int leftSmaller[n], rightSmaller[n];
    stack<int> s;
    for(int i = 0; i < n; i++) {
        while(!s.empty() && his[s.top()] >= his[i]) {
            s.pop();
        }
        if(s.empty()) leftSmaller[i] = 0;
        else leftSmaller[i] = s.top() + 1;
        s.push(i);
    }

    //làm sạch stack
    while(!s.empty()) s.pop();

    for(int i = n - 1; i >= 0; i--) {
        while(!s.empty() && his[s.top()] >= his[i]) {
            s.pop();
        }
        if(s.empty()) rightSmaller[i] = n - 1;
        else rightSmaller[i] = s.top() - 1;

        s.push(i);
    }

    int temp;
    int max_area = -1e9;
    for(int i = 0; i < n; i++) {
        temp = his[i] * (rightSmaller[i] - leftSmaller[i] + 1);
        if(temp > max_area) max_area = temp;
    }
    return max_area;
}

int main() {
    int n;
    // cin >> n;
    // int a[100];
    // for(int i = 0; i < n; i++) {
    //     cin >> a[i];
    // }
    int b[] = {6, 2, 5, 4, 5, 1, 6};
    n = sizeof(b)/sizeof(b[0]);
    cout<<solve2(b, n);
    return 0;
}