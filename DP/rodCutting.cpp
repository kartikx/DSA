#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int rodCutting(vector<int>& prices)
{
    vector<int> dp(prices.size()+1);
    dp[0] = 0;
    for (int i=1; i<=prices.size(); i++) {
        int ans = -1;
        for (int j=0; j<i; j++) {
            ans = max(ans, prices[j]+dp[i-j-1]);
        }
        dp[i] = ans;
    }

    return dp.back();
}

int main() {
    vector<int> prices{1, 5, 8, 9, 10, 17, 17, 20};
    cout << rodCutting(prices);
}