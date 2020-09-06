#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int n) {
    if (n == 0) {
        return 0;
    }
    
    return (log2(n & (-n)) + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << solve(n) << endl;
    }
}