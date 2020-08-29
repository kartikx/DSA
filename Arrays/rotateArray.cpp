// https://www.geeksforgeeks.org/program-for-array-rotation-continued-reversal-algorithm/
/*
Rotate array clockwise in O(1) space.
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// make Repeated clockwise rotates of size 1. O(N*D)
void rotate_array(vector<int>& v, int d) {
    for (int i=0; i<d; i++) {
        int curr = v[0];
        for (int j=1; j<v.size(); j++) {
            swap(v[j-1], v[j]);
        }
        v[v.size()-1] = curr;
    }
}

// a > b.
int hcf(int a, int b) {
    while (a%b != 0) {
        int rem = a%b;
        a = b;
        b = rem;
    }
    return b;
}

// Interesting Method.
void rotate_array_juggle(vector<int>& v, int d) {
    int spacing = hcf(v.size(), d);
    cout << "Spacing is: " << spacing << endl;

    for (int i = d; i >= 0; --i) {
        int curr = v[i];
        int c;
        for (c=0; c<d-1; c++) {
            v[i+c*d] = v[i+(c+1)*d];
        }
        v[i+c*d] = curr;
    }
}

int main() {
    vector<int> v{1, 2, 3, 4, 5};
    rotate_array(v, 3);

    for (auto x : v) {
        cout << x << " ";
    }
    cout << endl;
}
