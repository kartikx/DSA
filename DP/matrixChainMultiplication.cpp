#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int matrixChainMultUtil(vector<int>& matrices, int l, int r, vector<vector<int>>& dp) {
    cout << l << " " << r << endl;
    // I have only one matrix, so no internal computation.
    if (l == r-1) {
        return 0;
    }

    if (dp[l][r] != -1) {
        return dp[l][r];
    }

    int ans = INT_MAX;
    for (int i=l+1; i<=r-1; ++i) {
        int sub1 = matrixChainMultUtil(matrices, l, i, dp);
        int sub2 = matrixChainMultUtil(matrices, i, r, dp);
        ans = min(ans, sub1 + sub2 + matrices[l]*matrices[r]*matrices[i]);
    }
    dp[l][r] = ans;
    return ans;
}

int matrixChainMult(vector<int>& matrices)
{
    vector<vector<int>> dp(matrices.size(), vector<int>(matrices.size(), -1)); 
    return matrixChainMultUtil(matrices, 0, matrices.size()-1, dp);
}

int main() {
    vector<int> matrices{40, 20, 30, 10, 30};
    cout << matrixChainMult(matrices) << endl;
}