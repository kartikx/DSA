// Given an array of Integers, find the Subset with maximum sum,
// such that no 2 elements in the subset are adjacent to each other.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// O(N^2).
int subsetMaxSum(vector<int> nums) {
    vector<int> ans(nums.size(), 0);
    ans[nums.size()-1] = nums.back();
    ans[nums.size()-2] = nums[nums.size()-2];

    int res = INT_MIN;
    for (int i=nums.size()-3; i>=0; --i) {
        int currAns = INT_MIN;
        for (int j=i+2; j<nums.size(); ++j) {
            currAns = max(currAns, nums[i] + ans[j]);
        }
        ans[i] = currAns;
        res = max(res, currAns);
    }

    return res;
}

// O(N)
/**
 * For every element you have two options:
 * 1. Include this element: In this case you can't include
 * the element just before it.
 * 2. Exclude this element: In this case, the answer is
 * whatever it was before.
 * We'll be building our answer from L to R.
 */
int subsetMaxSumOpt(vector<int> nums) {
    int incl = nums[0];
    int excl = 0;

    for (int i=1; i<nums.size(); ++i) {
        int incl_org = incl;
        incl = nums[i] + excl;
        excl = max(incl_org, excl);
    }

    return max(incl, excl);
}

int main() {
    cout << subsetMaxSumOpt({3, 2, 7, 10}) << endl;
    cout << subsetMaxSumOpt({3, 2, 5, 10, 7}) << endl;
}