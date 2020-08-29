// https://www.techiedelight.com/find-maximum-length-sequence-continuous-ones-sliding-window/

/**
 * Instead of actually putting a one, and then computing the length of the window
 * you could consider this problem as longest continuous ones, where you're allowed
 * one and only one 0 in the region. So you could maintain a count of 0s, if it becomes
 * 2, then you would shrink from the left until a zero is removed.
 */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int makeMaximumLength(vector<int>& v) {
    int fast=0, slow=0;
    int count=0;
    int ans=0;
    while (fast < v.size()) {
        while (fast < v.size() && (v[fast] == 1 || count == 0)) {
            if (v[fast] == 0) {
                count++;
            }
            fast++;
        }

        ans = max(ans, fast-slow);

        // At this point, fast is at a zero s.t. count = 2.
        // I can be sure that there's a zero between slow and fast.
        while (v[slow] != 0) {
            slow++;
        }
        slow++;
        count--;
    }

    return ans;
}

int main() {
    vector<int> v{0, 0, 1, 0, 1, 1, 1, 0, 1, 1};
    cout << makeMaximumLength(v) << endl;
}