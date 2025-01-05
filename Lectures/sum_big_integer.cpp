#include <iostream>
#include <bits/stdc++.h>
using namespace std;


//cách thêm các ký tự '0' lấp đầy xâu có độ dài nhỏ hơn
string tong(string a, string b) {
    while(b.length() < a.length()){
        b = "0" + b;
    }
    while(a.length() < b.length()) {
        a = "0" + a;
    }
    int nho = 0, tong = 0;
    string res = "";
    int so_ki_tu = a.length();
    for(int i = so_ki_tu - 1; i >= 0; i--){
        tong = (a[i] - '0') + (b[i] - '0') + nho; // tong = (a[i] - 48) + (b[i] - 48) + nho;
        nho = tong / 10;
        res = char(tong % 10 + '0') + res; // res = char(tong % 10 + 48) + res;
    }
    if (nho == 1) res = "1" + res;
    return res;
}

string Sum(string a, string b) {
    while(a.length() < b.length()) a = "0" + a;
    while(a.length() > b.length()) b = "0" + b;

    string result; 
    int nho = 0, tong = 0;
    int so_ki_tu = a.length();
    for(int i = so_ki_tu - 1; i >= 0; i--) {
        tong = (a[i] - 48) + (b[i] - 48) + nho;
        nho = tong / 10;
        result.push_back(char(tong%10 + 48));
    }
    if (nho == 1) result.push_back('1');
    reverse(result.begin(), result.end());
    return result;
}

//cách đảo ngược 2 xâu rồi cộng theo thứ tự từ phải sang trái
//Lưu ý xâu trên có độ dài lớn hơn xâu dưới. VD 12345898 + 12341 là hợp lý, còn 1234 + 1241241 là không hợp lý
string Sum2(string a, string b) {
    if(a.length() < b.length()) swap(a, b);
    int n1 = a.length(); int n2 = b.length();
    //đảo ngược 2 xâu
    reverse(a.begin(), a.end()); reverse(b.begin(), b.end());

    int tong = 0, nho = 0;
    string result = "";
    for(int i = 0; i < n2; i++) {
        tong = (a[i] - '0') + (b[i] - '0') + nho;
        nho = tong / 10;
        result.push_back(char(tong % 10 + '0'));
    }
    //Thêm các chữ số còn lại của số lớn hơn vào kết quả
    for(int i = n2; i < n1; i++) {
        tong = (a[i] - '0') + nho;
        nho = tong / 10;
        result.push_back(char(tong % 10 + '0'));
    }
    if(nho) result.push_back(char(nho + '0')); // cộng nốt biến nhớ nếu có
    reverse(result.begin(), result.end()); // đảo ngược xâu kết quả
    return result;
}

int main() {
    string a, b;
    cout<<"so thu nhat: "; cin>>a; fflush(stdin);
    cout<<"\nso thu hai: "; cin>>b;
    cout<<"\ntong 2 so la: "<< tong(a, b);
    cout<<"\ntong 2 so la: "<<Sum2(a, b);
    return 0;
}