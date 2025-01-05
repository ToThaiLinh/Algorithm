#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;
const int maxN = 1e5;

int n, q;
int a[maxN];
int st[4 * maxN];

//Thủ tục xây dựng cây phân đoạn 
void build(int id, int l, int r) {
    //đoạn chỉ gồm 1 phần tử không có nút con
    if(l == r) {
        st[id] = a[l];
        return;
    }
    
    int mid = (l + r) >> 1; //(l + r) / 2;
    //Gọi đệ quy để xử lý nút con của nút id
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);

    //Cập nhật lại giá trị min của đoạn [l, r] theo 2 nút con
    st[id] = min(st[id * 2], st[id * 2 + 1]);
}

//Thủ tục cập nhật
void update(int id, int l, int r, int i, int value) {
    //i nằm ngoài đoạn [l, r] => bỏ qua nút id
    if(l > i || r < i) {
        return;
    }

    //Đoạn chỉ gồm 1 phần tử không có nút con 
    if(l == r) {
        st[id] = value;
        return;
    }

    //Gọi đệ quy để xử lý nút con của nút id
    int mid = (l + r) >> 1;
    update(id * 2, l, mid, i, value);
    update(id * 2 + 1, mid + 1, r, i, value);

    //Cập nhật giá trị min của đoạn [l, r] theo 2 nút con
    st[id] = min(st[id * 2], st[id * 2 + 1]);
}

//Hàm lấy giá trị
int get(int id, int l, int r, int u, int v) {
    //Đoạn [u, v] không giao với đoạn [l, r]
    if(l > v || r < u ) 
        return inf;

    /* Đọan [l, r] nằm hoàn toàn trong đoạn [u, v] mà ta đang truy vấn
    ta trả lại thông tin ở nút id*/
    if(l >= u && r <= v) return st[id];

    //gọi đệ quy với các nút con của nút id
    int mid = (l + r) >> 1;
    int get1 = get(id * 2, l, mid, u, v);
    int get2 = get(id * 2 + 1, mid + 1, r, u, v);

    //Trả về giá trị nhỏ nhất theo 2 nút con
    return min(get1, get2);
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);

    cin >> q;
    while(q--) {
        int type, x, y;
        cin >> type >> x >> y;
        if(type == 1) {
            update(1, 1, n, x, y); //Gán giá trị y cho phẩn tử vị trí x
        }
        if(type == 2) {
            cout<<get(1, 1, n, x, y)<<"\n"; //In ra giá trị nhỏ nhất trong đọan x, y;
        }
    }
    return 0;
}

