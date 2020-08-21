// https://www.geeksforgeeks.org/coin-change-dp-7/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Bottom Up DP using a reduced Space Complexity.
void coinChange(int totalVal, vector<int>& coins)
{
    vector<vector<int>> dp(2, vector<int>(totalVal+1, 0));

    dp[0][0] = 1;
    dp[1][0] = 1;
    for (int i=0; i<coins.size(); i++) {
        for (int j=1; j<=totalVal; j++) {
            if (coins[i] > j)
                dp[(i+1)%2][j] = dp[i%2][j];
            else {
                dp[(i+1)%2][j] = dp[(i+1)%2][j-coins[i]] + dp[i%2][j];
            }
        } 
    }

    cout << "Total number of ways: " << dp[coins.size()%2].back() << endl;
}

int main() {
    vector<int> coins = {1, 2, 3};
    coinChange(4, coins);
}