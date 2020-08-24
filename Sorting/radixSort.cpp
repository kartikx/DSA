#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool mycompare(int a, int b, int k) {
    int base = (int)pow(10, k);
    return a%base < b%base;
}

void radixSort(vector<int>& v) {
    // Find maximum element.
    int maxEle = INT_MIN;
    for (auto x : v) {
        maxEle = max(x, maxEle);
    }

    int count = 0;
    // find number of digits in maxEle.
    while (maxEle != 0) {
        maxEle /= 10;
        count++;
    }

    for (int i=1; i<=count; i++) {
        sort(v.begin(), v.end(), [i](int a, int b) {return mycompare(a, b, i); });
    }
}

int main() {
    vector<int> v{200, 10312, 255, 259, 397, 361};
    radixSort(v);
    for (auto x : v) {
        cout << x << " ";
    }
    cout << endl;
}