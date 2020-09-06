#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Includes l but not r.
void reverseSubArray(vector<int>& v, int l, int r) {
    r = min(r, (int) v.size());

    int i=l, j=r-1;
    while (i < j) {
        swap(v[i], v[j]);
        i++;
        j--;
    }

    return;
}

int main() {
    int t; cin>>t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> v(n, 0);

        for (int i=0; i<n; i++) {
            cin >> v[i];
        }
        
        int start = 0;

        while (start < n) {
            reverseSubArray(v, start, start+k);
            start += k;
        }

        for (auto x : v) {
            cout << x << " ";
        }

        cout << endl;
    }
}