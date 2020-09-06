// https://practice.geeksforgeeks.org/problems/activity-selection/0

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/**
 * The main idea is to view it from the pov of the person performing the activity,
 * and the current time.
 * Suppose the current time is 1PM, if there's a possibility for you to finish an 
 * activity by 2PM (i.e. the next smallest time) then it's better than not doing
 * any activity. So at a particular instance, you should choose to do the activity
 * which would get finished the soonest from now.
 */

int main()
{
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        // <finish, start>
        vector<pair<int, int>> v1(n, {0, 0});
        int temp;
        for (int i=0; i<n; i++) {
            cin >> temp;
            v1[i].second = temp;
        }
        
        for (int i=0; i<n; i++) {
            cin >> temp;
            v1[i].first =temp;
        }
        
        sort(v1.begin(), v1.end());
        
        // test print?
        
        int ans = 0;
        int lastFinishedActivity = -1;
        for (int i=0; i<n; ++i) {
            if (v1[i].second >= lastFinishedActivity){
                ans++;
                lastFinishedActivity = v1[i].first;
            }
        }
        cout << ans << endl;
    }
}