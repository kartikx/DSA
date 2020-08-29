/**
 * Given two vectors v1 and v2 with distinct elements, return whether v2 is a subset of v1.
 */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/**
 * The basic idea is to check whether every element of v2 is contained in v1.
 * There are multiple ways to do this:
 * 1. For every element of v2 iterate over entire v1. O(N*M).
 * 2. Sort v1, for every element of v2, use binary search in v1. O(NLogN + MLogN).
 * 3. Sort v1, and v2. Iterate both containers simultaneously. O(NLogN + MLogM).
 * 4. Use an Unordered Set to store all elements of V1. Query for all elements of v2.
 */

bool isSubset(vector<int>& v1, vector<int>& v2) {
    sort(v1.begin(), v1.end());

    for (int i=0; i<v2.size(); i++) {
        if (!binary_search(v1.begin(), v1.end(), v2[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<int> v1{10, 20, 4, 5, 7, 11, 2, 3};
    vector<int> v2{5, 10, 3};
    isSubset(v1, v2);
}