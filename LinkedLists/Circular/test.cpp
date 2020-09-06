#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {4, 10, 15, 24, 26};
    int curr_min = 27;

    auto it = lower_bound(v.begin(), v.end(), curr_min);
    if (it != v.end()) {
        cout << *it << endl;
    }
    else {
        cout << "Not there" << endl;
    }
    // int upper_b = it == v.end() ? INT_MAX : *it;
    // it = lower_bound(v.begin(), v.end(), curr_min);
    // int lower_b = it == v.end() ? INT_MAX : *it;
    
    // if (abs(upper_b - curr_min) < abs(lower_b - curr_min)) {
    //     cout << upper_b << endl;
    // }
    // else {
    //     cout << lower_b << endl;
    // }
}