/*
Một nhà đầu tư tài chính quyết định đầu tư vào 2 nhóm cổ phiếu, nhóm cổ phiếu ngành công nghệ và nhóm cổ phiếu nghành bán lẻ.
Các mã cổ phiếu mà nhà đầu tư có thể lựa chọn đầu tư được đánh số từ 1 tới (n1 + n2) trong đó các cổ phiếu ngành công nghệ có mã từ 1 đến n1, và các cổ phiếu ngành bán lẻ có mã từ (n1 + 1) tới (n1 + n2).
Để giảm thiểu rủi ro, nhà đầu tư đưa ra chiến lược như sau:
    (1) Không đầu tư quá L mã cổ phiếu khác nhau;
    (2) Mỗi nhóm cổ phiếu, không đầu tư quá M mã cổ phiếu khác nhau;
    (3) Mỗi nhóm cổ phiếu, đầu tư ít nhất một mã cổ phiếu;
    (4) Lập một danh sách gồm P cặp mã cổ phiếu không cùng đầu tư với nhau; mỗi cặp (u, v) trong danh sách,
    nếu đầu tư vào mã cổ phiếu u thì sẽ không đầu tư vào mã cổ phiếu v, ngược lại nếu đầu tư vào mã cổ phiếu v thì sẽ không đầu tư vào mã cổ phiếu u vì 2 mã cổ phiếu này có cùng chủ sở hữu.
Mỗi một chiến lược là một tập các mã cổ phiếu thỏa mãn các điều kiện trên, hỏi nhà đầu tư có bao nhiêu chiến lược đầu tư khác nhau.
Dữ liệu vào:
    Dòng 1: Gồm 2 số nguyên cách nhau bởi dấu cách, các giá trị này tương ứng với số lượng mã cổ phiếu trong mỗi nhóm(n1, n2), giá trị các số nguyên nằm trong từ 1 đến 12.
    Dòng 2: Gồm 3 só nguyên cách nhau bởi dấu cách; trong đó số đầu tiên là số lượng mã cổ phiếu tối đa mà nhà đầu tư lựa chọn L, số thứ 2 là số lượng cổ phiếu tối đa mà nhà đầu tư đầu tư vào một nhóm M, số thứ 3 là số lượng cặp cổ phiếu không đầu tư cùng nhau P
    P dòng tiếp theo: mỗi dòng gồm 2 số nguyên cách nhau bởi dấu cách, cặp mã cổ phiếu không đầu tư cùng nhau.
Kết quả:
    Một số nguyên dương là số lượng chiến lược đầu tư khác nhau

Dữ liệu vào (stdin)
3 3
3 3 6
2 3
1 5
4 1
2 5
3 1
5 4

Kết quả (stdout)
3

Giải thích
3 phương án đầu tư hợp lệ là (2, 4), (3, 4), và (3, 5)
*/

#include <iostream>
#include <vector>
#include <set>
#include <bitset>

using namespace std;

// Kiểm tra nếu một tập hợp đầu tư hợp lệ
bool isValid(const vector<int>& investment, int n1, int n2, int L, int M, const vector< pair<int, int> >& constraints) {
    int techCount = 0, retailCount = 0;
    set<int> chosen;

    // Đếm số cổ phiếu trong mỗi nhóm
    for (int i = 0; i < investment.size(); i++) {
        int stock = investment[i];
        chosen.insert(stock);
        if (stock <= n1) {
            techCount++;
        } else {
            retailCount++;
        }
    }

    // Kiểm tra điều kiện (1), (2), (3)
    if (chosen.size() > L || techCount > M || retailCount > M || techCount == 0 || retailCount == 0) {
        return false;
    }

    // Kiểm tra điều kiện (4): Không vi phạm các cặp không đầu tư cùng nhau
    for (int i = 0; i < constraints.size(); i++) {
        int u = constraints[i].first;
        int v = constraints[i].second;
        if (chosen.count(u) && chosen.count(v)) {
            return false;
        }
    }

    return true;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n1, n2, L, M, P;
    cin >> n1 >> n2;
    cin >> L >> M >> P;

    vector<pair<int, int> > constraints(P);
    for (int i = 0; i < P; i++) {
        cin >> constraints[i].first >> constraints[i].second;
    }

    int totalStocks = n1 + n2;
    int strategies = 0;

    // Duyệt qua tất cả các tập hợp con của các mã cổ phiếu
    for (int mask = 1; mask < (1 << totalStocks); mask++) {
        vector<int> investment;
        for (int i = 0; i < totalStocks; i++) {
            if (mask & (1 << i)) {
                investment.push_back(i + 1); // Thêm mã cổ phiếu vào tập hợp
            }
        }

        if (isValid(investment, n1, n2, L, M, constraints)) {
            strategies++;
        }
    }

    cout << strategies << endl;
    return 0;
}
