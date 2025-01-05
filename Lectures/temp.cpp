#include <iostream>
#include <list> 
using namespace std;

bool mycomparison(double first, double second) {
    return ((first) > (second));
}

int main() {
    list<double> first;
    list<double> second;

    first.push_back(3.1);
    first.push_back(2.2);
    first.push_back(2.9);

    second.push_back(3.7);
    second.push_back(7.1);
    second.push_back(1.4);
    second.push_back(2.1);

    first.merge(second, mycomparison);
    cout<<"first list gom cac so:\n";
    for(list<double>::iterator it = first.begin(); it != first.end(); it++) {
        cout<<*it<<" ";
    }
    return 0;
}