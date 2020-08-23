#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void findSum(vector<int>& v, int k) {
    make_heap(v.begin(), v.end());
    int sum = 0;
    for (int i=1; i<=k; i++) {
        cout << v[0] << " ";
        sum += v[0];
        pop_heap(v.begin(), v.end());
        v.pop_back();
    }
    cout << "Sum is: " << sum << endl;
}

int main() {
    vector<int> v{90, 89, 65, 80, 88, 71, 48, 23,100};
    findSum(v, 3);
}