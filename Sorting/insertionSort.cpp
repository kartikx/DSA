#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>& v) {
    for (int j=1; j<v.size(); j++) {
        int key = v[j];
        int i = j;
        while (i > 0 && v[i] < v[i-1]) {
            swap(v[i], v[i-1]);
            i--;
        }
    }
}

int main() {
    vector<int> v{5, 2, 4, 6, 1, 3};
    insertionSort(v);

    for (auto x : v) {
        cout << x << " ";
    }
    cout << endl;
}