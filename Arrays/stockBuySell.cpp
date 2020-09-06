#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n, 0);
        for (int i=0; i<n; i++) {
            cin >> v[i];
        }

        int lastDay = 0;
        for (int i=0; i<v.size()-1; ++i) {
            if (v[i] > v[i+1]) {
                if (i != lastDay) {
                    printf("(%d %d) ", lastDay, i);
                }
                lastDay = i+1;
            }
        }

        if (lastDay != n-1) {
            printf("(%d %d) ", lastDay, n-1);
        }

        printf("\n");
    }
}