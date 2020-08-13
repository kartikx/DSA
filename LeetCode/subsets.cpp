/*
Given a vector of distinct integers,
compute it's powerset.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void subsets(vector<int>& nums)
{
    vector<vector<int>> powerSet;
    powerSet.push_back(vector<int>());

    for (int i=0; i<nums.size(); ++i)
    {
        int p_size = powerSet.size();
        for (int k=0; k<p_size; k++) {
            vector<int> newVec(powerSet[k]);
            newVec.push_back(nums[i]);
            powerSet.push_back(newVec);
        }
    }

    for (auto v : powerSet) {
        for (auto x : v) {
            cout << x << " ";
        }
        cout << endl;
    }
}

void backtrack(int index, list<int>& curr, list<list<int>>& output, vector<int>& nums, int size)
{
    if (curr.size() == size)
    {
        output.push_back(curr);
        return;
    }

    for (int i=index; i<nums.size(); ++i)
    {
        curr.push_back(nums[i]);
        backtrack(i+1, curr, output, nums, size);
        curr.pop_back();
    }
}

void subsetsRecursion(vector<int>& nums)
{
    list<list<int>> output;
    list<int> curr;

    for (int i=0; i<=nums.size(); i++)
    {
        backtrack(0, curr, output, nums, i);
    }

    for (auto l : output) {
        for (auto x : l) {
            cout << x << " ";
        }
        cout << endl;
    }
}

void subsetsBitMasking(vector<int> nums)
{
    vector<vector<int>> outputs;
    int numOfSubsets = pow(2, nums.size());

    for (int i=0; i<numOfSubsets; ++i) {
        vector<int> output;
        for (int j=0; j<nums.size(); ++j) {
            if (i & (1 << j)) {
                output.push_back(nums[j]);
            }
        }
        outputs.push_back(output);
    }
    for (auto l : outputs) {
        for (auto x : l) {
            cout << x << " ";
        }
        cout << endl;
    }
}

vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> leftProduct(nums.size());
        vector<int> rightProduct(nums.size());

        leftProduct[0] = nums[0];
        rightProduct[nums.size()-1] = nums[nums.size()-1];

        for (int i=1; i<nums.size(); ++i)
            leftProduct[i] = nums[i] * leftProduct[i-1];
        for (int i=nums.size()-2; i>=0; --i)
            rightProduct[i] = nums[i] * rightProduct[i+1];
        
        for (auto x : leftProduct)
            cout << x << " ";
        cout << endl;

        for (auto x : rightProduct)
            cout << x << " ";
        cout << endl;

        vector<int> result(nums.size());
        for (int i=0; i<nums.size(); ++i){
            if (i==0){
                result[i] = rightProduct[i+1];
            }
            else if (i==nums.size()-1){
                result[i] = leftProduct[i-1];
            }
            else {
                result[i] = leftProduct[i-1]*rightProduct[i+1];
            }
        }
        for (auto x : result) {
            cout << x << " ";
        }
        cout << endl;
        return result;
}

int main() {
    vector<int> v = {1, 2, 3, 4};
    productExceptSelf(v);
}