/**
 * Print all maximum subarrays having distinct elements.
 * Maximum means that you shouldn't print the sub-arrays
 * which are completely included in another sub-array answer.
 */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void distinctSubarrays(vector<int>& v) {
    unordered_map<int, int> m;
    // Whenever you reach duplicate, incremenent slow. Else increment fast.
    int slow=0, fast=0;
    while (fast < v.size() && slow < v.size()) {
        if (m.count(v[fast]) > 0) {
            for_each(v.begin()+slow, v.begin()+fast, [](const int& x) {cout << x << " ";});
            cout << endl;
            // Remove all elements from [slow .. m[v[fast]]]

            /**
             * ! I was doing this earlier using:
             * while(slow <= m[v[fast]])
             * The problem with that is at the final step, when I've removed
             * the matched element, There shouldn't exist any key v[fast],
             * however when the condition is checking (at termination),
             * the accessor [] ends up creating a key v[fast] -> 0.
             * This leads to inf. loops
             */

            int index = m.at(v[fast]);
            while (slow <= index) {
                m.erase(v[slow]);
                slow++;
            }
        }
        else {
            m.insert({v[fast], fast});
            fast++;
        }
    }
    if (slow < v.size())
    {
        for_each(v.begin()+slow, v.begin()+fast, [](const int& x) {cout << x << " ";});
        cout << endl;
    }
    return;
}

void distinctSubarrays2(vector<int>& v) {
    unordered_map<int, bool> m;

    int slow=0, fast=0;

    while (fast < v.size()) {
        while (fast < v.size() && !m[v[fast]]) {
            fast++;
        }

        // print

        while (fast < v.size() && m[v[fast]]) {
            m[v[slow]] = false;
            slow++;
        }
    }
}

int main() {
    vector<int> v{1, 4, 2, 4, 4, 3, 2, 5, 6};
    distinctSubarrays(v);
}