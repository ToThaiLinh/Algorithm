/*
ĐỒ THỊ VÔ HƯỚNG
Đồ thị vô hướng có chu trình Euler nếu:
    - Các đỉnh có bậc khác 0 của đồ thị liên thông với nhau
    - Tất cả các đỉnh của đồ thị có bậc chẵn

Đồ thị vô hướng có đường đi Euler nêu:
    - Các đỉnh có bậc khác 0 của đồ thị liên thông với nhau
    - Đồ thị có 0 hoặc 2 đỉnh có bậc lẻ trong trường hợp có 2 đỉnh bậc lẻ thì đường đi sẽ bắt đầu từ đỉnh bậc lẻ thứ 1 và kết thúc ở đỉnh bậc lẻ thứ 2

ĐỒ THỊ CÓ HƯỚNG
Đồ thị có hướng có chu trình Euler nếu:
    - Các đỉnh có bậc khác 0 của đồ thị thuộc cùng một thành phần liên thông
    - Mọi đỉnh thuộc đồ thị đều có bán bậc ra bằng bán bậc vào

Đồ thị có hướng có đường đi Euler nếu:
    - Các đỉnh có bậc khác 0 của đồ thị thuộc cùng 1 thành phần liên thông
    - Tồn tại 2 đỉnh u, v mà deg+(u) - deg-(v) = 1 và deg-(v) - deg+(u) = 1, mọi đỉnh còn lại đều có bán bậc ra bằng bán bậc vào. Khi đó đường đi bắt đầu từ đỉnh u và kết thúc tại đỉnh v.
*/

#include <bits/stdc++.h>
using namespace std;

/*
input 
5 6
1 2
2 3
3 1
2 4
4 5
2 5

output
1 2 4 5 2 3 1
*/

const int MAX = 1001;
int n, m;
set<int> adj[MAX];
int degree[MAX];

void input() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int x, y; cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
        degree[x]++;
        degree[y]++;
    }
}

void euler(int v) {
    stack<int> S;
    vector<int> EC;
    S.push(v);
    while(!S.empty()) {
        int x = S.top();
        if(adj[x].size() != 0) {
            int y = *adj[x].begin();
            S.push(y);
            adj[x].erase(y);
            adj[y].erase(x);
        }
        else {
            S.pop();
            EC.push_back(x);
        }
    }
    reverse(EC.begin(), EC.end());
    for(int i = 0; i < EC.size(); i++) {
        cout << EC[i] << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    euler(1);

    return 0;
}