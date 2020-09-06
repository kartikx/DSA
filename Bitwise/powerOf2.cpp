#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool solve(unsigned long int n) {
    if (n==0) {
        return false;
    }
    return ((n & (n-1)) == 0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while (t--) {
        unsigned long int n; cin >> n;
        if (solve(n)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}