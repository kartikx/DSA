/*
Basic Idea: Compare all consecutive pairs of integers,
such that the largest element keeps bubbling upwards.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& v) {
    int len = v.size();
    bool flag;
    for (len; len > 0; --len) {
        flag = false;
        for (int i=0; i<len-1; i++) {
            if (v[i+1] < v[i]) {
                swap(v[i+1], v[i]);
                flag = true;
            }
        }
        if (!flag)
            break;
    }
}

int main() {
    vector<int> v{1, 2, 3, 0, 5};
    bubbleSort(v);
    for_each(v.begin(), v.end(), [](int& x) {cout << x << " ";});
    cout << endl;
}