#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// known that it1.first < it2.first
bool overlap(map<int, int>::iterator it1, map<int, int>::iterator it2){
    if (it2->first <= it1->second && it1->first <= it2->second) {
        return true;
    }
    return false;
}

int main()
{
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arrival(n, 0), departure(n, 0);

        for (int i=0; i<n; i++) {
            cin >> arrival[i];
        }

        for (int i=0; i<n; i++) {
            cin >> departure[i];
        }

        sort(arrival.begin(), arrival.end());
        sort(departure.begin(), departure.end());

        int i=0, j=0;
        int ans = -1;
        int platforms = 0;
        while (i < n && j < n) {
            if (arrival[i] <= departure[j]) {
                i++;
                platforms++;
            }
            else {
                platforms--;
                j++;
            }

            ans = max(ans, platforms);
        }

        cout << ans << endl;
    }
}
