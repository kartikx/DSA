/**
 * Given two arrays X, Y. Find all pairs of elements (x, y) s.t.
 * x^y > y^x.
 */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int getCount(vector<int>& v2, int x) {
    if (x == 0) {
        return 0;
    }
    
    else if (x == 1) {
    //  count += numZeroes.
    }
    int ans = 0;
    int num = v2.end() - upper_bound(v2.begin(), v2.end(), x);
    // ans += num + count0 + count1;
    
}

void findPairs(vector<int>& v1, vector<int>& v2) {
    sort(v2.begin(), v2.end());
    int count = 0;
    for (auto x : v1) {
        count += getCount(v2, x); 
    }
}

int main() {
    vector<int> v1{2, 1, 6};
    vector<int> v2{5, 1};

    findPairs(v1, v2);
}