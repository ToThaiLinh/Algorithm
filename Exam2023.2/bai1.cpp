/*
Có n người chơi 1, 2, ..., n trong một cuộc thi. Điểm số của người chơi i là a[i] (i = 1, 2, ..., n). Hãy tìm điểm số thấp nhất và cao nhất giữa n người chơi đó.
Dữ liệu vào:
- Dòng 1: chứa số nguyên n (1 ≤ n ≤ 100000).
- Dòng 2: chứa n số nguyên a[1], a[2], ..., a[n] (0 ≤ a[i] ≤ 100000).
Kết quả:
 Ghi ra điểm số thấp nhất và cao nhất giữa các người chơi (sau mỗi phần tử, có một ký tự SPACE)
Ví dụ:
Input:
5
2 4 3 7 1 
Output:
1 7
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);  
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
            cin >> a[i];
    }
    int min_value = *min_element(a.begin(), a.end());
    int max_value = *max_element(a.begin(), a.end());
    cout << min_value << " " << max_value;
    return 0;
}