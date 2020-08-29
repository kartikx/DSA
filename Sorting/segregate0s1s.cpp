#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void segregate(vector<int>& v) {
    int l = -1, r = v.size();

    int c = 0;
    while (c < r) {
        if (v[c] == 0) {
            l++;
            swap(v[c], v[l]);
        }
        c++;
    }
}

int main() {
    vector<int> v{0, 1, 1, 0, 0, 1, 0};
    segregate(v);
    for (auto x : v) {
        cout << x << " " ;
    }
    cout << endl;
}