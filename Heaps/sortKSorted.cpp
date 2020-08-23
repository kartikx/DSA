/*
Given an array, such that every element is at most K places
away from it's sorted position. Sort the array.
https://www.techiedelight.com/sort-k-sorted-array/
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * Basic Idea: For a given position i, it's correct number
 * will be the minimum number in [i .. i+k].
 * We don't consider the previous k elements for a position,
 * because those have gotten fixed.
 */
void sortArray(vector<int>& v, int k) {
    // Pointless, it's a standard sorting case.
    if (v.size() <= k) {
        sort(v.begin(), v.end());
    }
    // Don't forget to allocate space, if you're gonna use std::copy
    vector<int> v_heap(k+1);
    copy(v.begin(), v.begin()+k+1, v_heap.begin());

    make_heap(v_heap.begin(), v_heap.end(), greater<int>());

    for (int i=0; i<v.size(); i++) {
        v[i] = v_heap[0];
        pop_heap(v_heap.begin(), v_heap.end(), greater<int>());
        v_heap.pop_back();
        if (i < v.size() - k - 1)
        {
            v_heap.push_back(v[i+k+1]);
            push_heap(v_heap.begin(), v_heap.end(), greater<int>());
        }
    }
}

int main() {
    vector<int> v{1, 4, 5, 2, 3, 7, 8, 6, 10, 9};
    sortArray(v, 2);
    for_each(v.begin(), v.end(), [](int& x) {cout << x << " " ;});
    cout << endl;
}