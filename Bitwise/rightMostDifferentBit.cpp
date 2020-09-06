#include<bits/stdc++.h>
using namespace std;

int solve(int x, int y) {
    if (x == y) {
        return -1;
    }
    
    int n = (x ^ y);
    // now find first set bit
    return log2(n & (-n)) + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int x, y; cin >> x >> y;
        cout << solve(x, y) << endl;
    }
}