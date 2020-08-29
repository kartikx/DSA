#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findMaximumLength(vector<int>& v) {
    int fast=0, slow=0;
    int ans = 0;

    while (fast < v.size()) {
        while (fast < v.size() && v[fast] == 1) {
            fast++;
        }
        // add condition.
        if (!(fast == 0 && slow == 0)) 
            ans = max(0, fast-slow+1);

        while (fast < v.size() && v[fast] == 0) {
            fast++;
        }
        slow = fast;
    }

    return ans;
}

int main() {
    vector<int> v{0, 0, 1, 0, 1, 1, 1, 0, 1, 1};
    cout << findMaximumLength(v) << endl;
}