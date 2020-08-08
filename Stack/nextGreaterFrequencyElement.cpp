#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void nextGreaterFrequency(vector<int>& nums, vector<int>& res)
{
    // first construct the frequency map.
    unordered_map<int, int> M;
    for (int x : nums) {
        M[x]++;
    }

    stack<int> s;
    
    for (int i=nums.size()-1; i>=0; --i){
        int curr = nums[i];
        while(!s.empty() && M[s.top()] <= M[curr]) {
            s.pop();
        }
        if (s.empty()) {
            res[i] = -1;
        }
        else {
            res[i] = s.top();
        }
        s.push(curr);
    }
}

int main() {
    vector<int> nums {1, 1, 2, 3, 4, 2, 1};
    vector<int> res(nums.size(), 0);
    nextGreaterFrequency(nums, res);
    for (int i=0; i<nums.size() ; i++) {
        cout << nums[i] << "/" << res[i] << " " ;
    }
}