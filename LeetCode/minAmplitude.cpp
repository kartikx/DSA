#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findMinAmplitudeUtil(vector<int>& v, int start, int end, int numRemovals)
{
    if (start > v.size() || end < 0 || start > end)
        return INT_MAX;

    if (numRemovals == 3)
    {
        return v[end]-v[start];
    }

    return min(findMinAmplitudeUtil(v, start+1, end, numRemovals+1), 
               findMinAmplitudeUtil(v, start, end-1, numRemovals+1));
}
int findMinAmplitude(vector<int>& v)
{
    if (v.size() <= 3)
        return 0;

    // Need to query minimum and maximum multiple every time,
    // good idea to sort it.
    sort(v.begin(), v.end());
    int minAmp = findMinAmplitudeUtil(v, 0, v.size()-1, 0);

    if (minAmp == INT_MAX) {
        throw runtime_error("Something went wrong");
    }
}

int main() {
    vector<int> v{7, 5, 0, -1, -9, 12, 5, 8};
    cout << findMinAmplitude(v);
}