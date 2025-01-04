/*
Tại một vương quốc xa xôi, có một vị vua nổi tiếng với sự thông min và tài năng quản lý đất nước.
Để thử thách các thần dân và tìm kiếm những tài năng xuất chúng, nhà vua đã đặt ra một bài toán hóc búa và hứa hẹn phần thưởng lớn cho ai có thể giải quyết được.
Nhà vua sở hữu một thanh gỗ quý hiếm với chiều dài n đơn vị. Thanh gỗ này được chế tác từ loại cây cổ thụ chỉ mọc trên đỉnh núi cao nhất của vương quốc. Mỗi đoạn của thanh gỗ có gía trị đặc biệt phụ thuộc vào chiều dài của nó, và nhà vua muốn tối đa hóa tổng giá trị thu được từ việc bán các đoạn gỗ này. Nhà vua công bó cho toàn bộ thần dân biết bảng giá trị các đoạn gỗ có chiều dài lần lượt từ 1 đến n đơn vị là p1, p2, ..., pn.
Nhiệm vụ của bản là giúp nhà vua tìm ra cách cắt thanh gỗ để có thể bán các đoạn đã cắt với tổng giá trị lớn nhất. Hãy chứng minh tài năng của mình và giành lấy phần thưởng lớn từ nhà vua.

Dữ liệu vào:
    - Dòng đầu tiên chứa một số nguyên n (1 <= n <= 1000) là chiều dài của thanh gỗ.
    - Dòng thứ hai chứa n số nguyên pi (1 <= pi <= 10^9) cách nhau bởi dấu cách là giá trị của các đoạn gỗ có chiều dài i (i = 1, 2, ..., n)
Kết quả
    - In ra một số nguyên là giá trị lớn nhất có thể thu được bằng cách cắt thanh gỗ ban đầu và bán các đoạn đã cắt.

Ví dụ:
Dữ liệu vào:
8
1 5 8 9 10 17 17 20
Kết quả
22
Giải thích 
Cắt thành 1 đoạn độ dài 2 và 1 đoạn đọ dài 6.

Dữ liệu vào 
8
3 5 8 9 10 17 17 20
Kết quả
24
Giải thích
Cắt thành 8 đoạn có độ dài 1
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// đệ quy
int cutRodRecur(int i, vector<int> prices) {
    if(i == 0) return 0;

    int ans = 0;
    for(int j = 1; j <= i; j++) {
        ans = max(ans, prices[j] + cutRodRecur(i - j, prices));
    }
    return ans;
}

//đẹ quy có nhớ
int cutRodRecur(int i, vector<int> prices, vector<int> memo) {
    if(i == 0) return 0;

    if(memo[i] != -1) return memo[i];

    int ans = 0;
    for(int j = 1; j <= i; j++) {
        ans = max(ans, prices[j] + cutRodRecur(i - j, prices, memo));
    }
    memo[i] = ans;
    return ans;
}

//DP
int cutRodDP(vector<int> prices) {
    int n = prices.size() - 1;
    vector<int> dp(n + 1, -1);

    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            dp[i] = max(dp[i], prices[j] + dp[i - j]);
        }
    }
    return dp[n];
}

int cutRod(vector<int> prices) {
    int n = prices.size() - 1;
    // return cutRodRecur(n, prices);

    // vector<int> memo(n + 1, -1);
    // return cutRodRecur(n, prices, memo);

    return cutRodDP(prices);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int result = cutRod(a);
    cout << result << endl;
    return 0;
}