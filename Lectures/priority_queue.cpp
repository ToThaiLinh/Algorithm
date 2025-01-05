#include <bits/stdc++.h>

using namespace std;

int n;
vector< pair<int, int> > cong_viec;

int main() {
    int p, r;
    /* Khai báo 2 thành phần: 
    p là thời gian để thực hiện xong công việc, r là thời gian sớm nhất để bắt đầu */
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin>> p >> r;
        cong_viec.push_back(make_pair(r, p));
    }
    
    /*Sắp xếp công việc theo giá trị tăng dần của thành phần thứ nhất trong mỗi phần tử của vector công việc
    (tức là tăng theo giá trị r) */
    sort(cong_viec.begin(), cong_viec.end());

    /* Khai báo hàng đợi ưu tiên Q lưu các số nguyên
     là lượng thời gian còn lại để hoàn thành công việc đang được thực hiện */
    priority_queue<int, vector<int>, greater<int> > Q;

    int i = 0; // thứ tự công việc trong vector công việc đã được sắp xếp
    int t = 0; // thời gian kết thúc công việc thứ i
    int result = 0; // tổng thời gian hòan thành các công việc

    while(i < n || !Q.empty()) {
        //Thực hiện công việc đầu tiên
        if(Q.empty()) {
            t = cong_viec[i].first; //thời điểm bắt đầu công việc sớm nhất
            Q.push(cong_viec[i].second);// Thêm thời gian thực hiện công việc mới nhất vào hàng đợi ưu tiên
            i++; // Chuyển đến công việc tiếp theo
        }
        //Thực hiên công việc tiếp theo
        else {
            if(i < n) {
                //Thời gian từ thời điểm t đến khi có thể bắt đầu công việc i
                int remain = cong_viec[i].first - t; 
                if(remain < Q.top()) {
                    int u = Q.top();
                    Q.pop();
                    Q.push(u - remain);
                    Q.push(cong_viec[i].second);
                    t = cong_viec[i].first;
                    i++;
                }
                else {
                    t += Q.top();
                    result += t;
                    Q.pop(); 
                }
            }
            else {
                t += Q.top();
                result += t;
                Q.pop();
            }
        }
    }
    printf("%.2f", 1.0 * result/n);
    return 0;

}