/*
https://www.geeksforgeeks.org/optimal-strategy-for-a-game-dp-31/
*/

/*
There is a more optimized approach, which can solve
using just 2 recursive calls, instead of the 4 here.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int optimalStrategyUtil(vector<int>& values, int l, int r)
{
    if (l > r)
        return 0;
    if (l==r)
        return values[l];

    int valL = values[l];
    int valR = values[r];

    return max(valL + (min(optimalStrategyUtil(values, l+2, r), optimalStrategyUtil(values,l+1, r-1))),
               valR + (min(optimalStrategyUtil(values, l, r-2), optimalStrategyUtil(values,l+1, r-1))));
}

int optimalStrategy(vector<int>& values) {
    return optimalStrategyUtil(values, 0, values.size()-1);
}

// Top Down DP based approach, using the Two Recursive calls technique.
int optimalStrategyOptUtil(vector<int>& values, int l, int r, int sum, vector<vector<int>>& dp)
{
    if (l > r)
        return INT_MAX;

    if (l == r) {
        dp[l][r] = sum;
        return sum;
    }

    if (dp[l][r] != -1) {
        return dp[l][r];
    }

    dp[l][r] = max(sum - optimalStrategyOptUtil(values, l+1, r, sum-values[l], dp),
                   sum-optimalStrategyOptUtil(values, l, r-1, sum-values[r], dp));

    return dp[l][r];
}

int optimalStrategyOpt(vector<int>& values) {
    if (values.empty())
        return -1;
    
    vector<vector<int>> dp(values.size());
    for (int i=0; i<values.size(); i++){
        dp[i] = vector<int>(values.size(), -1);
    }
    int sum = accumulate(values.begin(), values.end(), 0);
    
    optimalStrategyOptUtil(values, 0, values.size()-1, sum, dp);
        for (int i=0; i<values.size(); i++){
        for (auto x : dp[i])
            cout << x << " ";
        cout << endl;
    }
}

int main() {
    vector<int> values{8, 15, 3, 7};
    cout << optimalStrategyOpt(values);
}