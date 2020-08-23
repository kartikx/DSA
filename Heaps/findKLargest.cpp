/*
Given a vector of integers, find the K Largest
numbers in it.
https://www.techiedelight.com/find-kth-largest-element-array/
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
The main idea is to maintain a set which contains the K
Largest elements seen so far. If you encounter an element
which is larger than the minimum element of this set, then
you add it to the set, and remove the current minimum
(if size of set > K). Now get the new minimum.

Since you have to find the smallest number each time, use
a min-heap.
*/
void findKLargest(vector<int>& v, int k) {
    vector<int> v_heap;
    for (int i=0; i < v.size(); ++i) {
        if (v_heap.empty() || v[i] > v_heap[0]) {
            v_heap.push_back(v[i]);
            push_heap(v_heap.begin(), v_heap.end(), greater<int>());
            if (v_heap.size() > k) {
                pop_heap(v_heap.begin(), v_heap.end(), greater<int>());
                v_heap.pop_back();
            }
        }
    }

    cout << "The " << k << " largest elements are: " << endl;
    for_each(v_heap.begin(), v_heap.end(), [](int& x) {cout << x << " " ;});
}

int main() {
    vector<int> v{9, 8, 7, 6, 5, 4, 3, 2, 1};
    // findKLargest(v, 3);

    nth_element(v.begin(), v.begin()+6, v.end());
    for_each(v.begin(), v.end(), [](int& x) {cout << x << " " ;});
}