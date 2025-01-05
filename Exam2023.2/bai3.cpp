/*
XÂY DỰNG ĐỒ THỊ
Tập đoàn AZ đang thực hiện dự án xây dựng một khu đô thị mới gồm nhiều tòa nhà cao tầng và thấp tầng. Bước vào giai đoạn thứ 2 của dự án, tập đoàn cần đầu tư xây dựng thêm một số đường hầm để đảm bảo cư dân có thể đi lại giữa tất cả các tòa nhà bằng đường hầm.
Chi phí để xây dựng đường hầm nối tòa A với tòa B được tính theo công thức:
(A.x - B.x)^2 + (A.y - B.y)^2 trong đó A.x, B.x tương ứng là hoành độ của tòa A và B, A.y và B.y là tung độ của tòa A và B trên bản đồ xây dựng bởi tập đoàn. 
Biết rằng, ở giai đoạn 1, tập đoàn đã xây dựng được một số đường hầm. Không thay đổi những đường hầm đã xây dựng ở giai đoạn 1, hãy giúp tập đoàn xác định cần xây dựng thêm những đường hầm nối giữa các cặp tòa nhà nào để tổng chi phí xây dựng là nhỏ nhất có thể, mà vẫn đảm bảo có thể đi lại giữa tất cả các toà nhà bằng đường hầm.
Dữ liệu vào:
    - Dòng thứ nhất chứa số nguyên n (1 <= n <= 750) là số lượng tòa nhà của dự án (các tòa nhà được đánh số từ 1 đến n). 
    - n dòng tiếp theo, mỗi dòng i (i = 1, 2, ..., n) chứa hai số nguyên x và y cách nhau bởi dấu cách, có giá trị tuyệt đối không quá 1000, lần lượt là hoành độ và tung độ của tòa thứ i.  
    - Dòng tiếp theo chứa số nguyên m (0 <= m <= 1000) là số lượng đường hầm đã xây dựng được ở giai đoạn 1.  
    - m dòng tiếp theo mô tả m đường hầm đã xây dựng ở giai đoạn 1, mỗi dòng i (i = 1, ..., m) chứa hai số nguyên tương ứng là chỉ số của 2 tòa được kết nối bởi đường hầm thứ i.  
Kết quả:  
    - Ghi ra 1 số nguyên K là chi phí tối thiểu mà dự án cần bỏ ra ở giai đoạn 2 để cư dân có thể đi lại giữa tất cả các toàn nhà bằng đường hầm.  

Ví dụ:
Dữ liệu vào (stdin)
4
3 4
4 1
4 3
1 1
1
4 2

Kết quả (stdout) 
6
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct edge {
    int u, v;
    long long w;
    edge(int _u, int _v, long long _w) : u(_u), v(_v), w(_w) {}
};

const int MAX = 751;
int n;
int parent[MAX];
int size[MAX];

void make_set() {
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
        size[i] = 1;
    }
}

int find(int u) {
    if(parent[u] == u) return parent[u];
    return parent[u] = find(parent[u]);
}

bool Union(int x, int y)  {
    int a = find(x);
    int b = find(y);
    if(a == b) return false;
    else {
        if(size[a] < size[b]) {
            parent[a] = b;
            size[b] += size[a];
        }
        else {
            parent[b] = a;
            size[a] += size[b];
        }
    }
    return true;
}

long long cal(pair<int, int>& x, pair<int, int>& y) {
    return (long long)(x.first - y.first) * (x.first - y.first) + (long long)(x.second - y.second) * (x.second - y.second);
}

bool cmp(const edge& a, const edge& b) {
    return a.w < b.w;
}

long long kruskal(vector<edge>& graph) {
    vector<edge> mst;
    long long d = 0;
    sort(graph.begin(), graph.end(), cmp);

    for(int i = 0; i < graph.size(); i++) {
        edge e = graph[i];
        if(Union(e.u, e.v)) {
            d += e.w;
            mst.push_back(e);
        }
    }
    return d;
}


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n;
    vector< pair<int, int> > canh(n);
    for(int i = 0; i < n; i++) {
        cin >> canh[i].first >> canh[i].second;
    }
    make_set();

    vector< edge> graph;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            long long w = cal(canh[i], canh[j]);
            graph.push_back(edge(i, j, w));
        }
    }

    int k; cin >> k;
    vector< pair<int, int> > exist(k);
    for(int i = 0; i < k; i++) {
       cin >> exist[i].first >> exist[i].second;
       exist[i].first--;
       exist[i].second--;
    }

    for(int i = 0; i < exist.size(); i++) {
        Union(exist[i].first, exist[i].second);
    }

    long long result  = kruskal(graph);
    cout << result;
    return 0;
}