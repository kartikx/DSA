/*
Given an integer array, you'll be given q queries of an index i,
for every i, print all the next Greater elements for arr[i].
For eg. if 3, 4, 2, 7, 5, 8, 10, 6
all NGE(0) will be 4, 7, 8, 10. After 4 you can't pluck 2, as 2 < 4
even though 2 > 3.
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int dp[20];

int numberOfNGE(vector<int>& nums, vector<int>& res, int index)
{
    if (dp[index] != -1) {
        cout << "Memo" ;
        return dp[index];
    }
    if (res[index] == -1) {
        dp[index] = 0;
        return 0;
    }

    // hasn't been processed.
    if (dp[res[index]] == -1) {
        numberOfNGE(nums, res, res[index]);
    }

    dp[index] = 1 + dp[res[index]];
    return dp[index];
}

void nextGreaterElement(vector<int>& nums, vector<int>& res)
{   
    stack<int> s;
    for (int i=nums.size()-1; i>=0; --i) {
        int curr = nums[i];
        while (!s.empty() && nums[s.top()] < curr) {
            s.pop();
        }
        if (s.empty()) {
            res[i] = -1;
        }
        else {
            res[i] = s.top();
        }
        // pushing Index in.
        s.push(i);
    }
}
int main() {
    vector<int> nums{3, 4, 2, 7, 5, 8, 10, 6};
    vector<int> res(nums.size(), 0);

    nextGreaterElement(nums, res);
    memset(dp, -1, 20*sizeof(int));
}