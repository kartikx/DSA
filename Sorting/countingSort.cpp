#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/**
 * Constant Space Counting Sort Implementation.
 * Similar to Constant Space Merge Operation.
 */
void countingSort(vector<int>& v) {
    if (v.size() <= 1)
        return;

    // Find Maximum and Minimum.
    int maxEle = INT_MIN, minEle = INT_MAX;

    for (auto x : v) {
        maxEle = max(x, maxEle);
        minEle = min(x, minEle);
    }

    vector<int> count(maxEle-minEle+1, 0);

    for (auto x : v) {
        count[x-minEle]++;
    }

    for (int i=1; i<count.size(); i++) {
        count[i] += count[i-1];
    }

    vector<int> output(v.size(), 0);

    // You should always start from the end, this makes it stable.
    for (int i=v.size()-1; i>=0; i--) {
        // OrgValue is the value supposed to be in unaltered v[i].
        int orgValue = v[i] % (maxEle + 1);

        v[count[orgValue-minEle]-1] += (orgValue)*(maxEle+1);
        count[orgValue-minEle]--;
    }

    for (int i=0; i<v.size(); i++) {
        v[i] /= (maxEle+1);
    }
}

int main() {
    vector<int> v{3, 6, 4, 7, 5, 8, 4, 7};
    countingSort(v);

    for (auto x : v) {
        cout << x << " ";
    }
    cout << endl;
}