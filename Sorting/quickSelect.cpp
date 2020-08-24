/**
 * Find the Kth smallest element in a container,
 * by using a variation of Quick Sort.
 */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& v, int l, int r) {
    int i=l-1, j=l;

    while (j < r) {
        if (v[j] <= v[r]) {
            i++;
            swap(v[i], v[j]);
        }
        j++;
    }
    swap(v[i+1], v[r]);
    return i+1;
}

int findUtil(vector<int>& v, int l, int r, int k) {
    if (l > r) {
        return -1;
    }

    int pivot = l + rand() % (r - l + 1);
    cout << "Pivot element: " << v[pivot] << endl;

    swap(v[pivot], v[r]);

    int pi = partition(v, l, r);
    if (pi == k) {
        return v[pi];
    }
    
    if (k < pi) {
        return findUtil(v, l, pi-1, k);
    }
    else {
        return findUtil(v, pi+1, r, k);
    }
}

int findKthSmallest(vector<int>& v, int k) {
    return findUtil(v, 0, v.size()-1, k-1);
}

int main() {
    // std::partition?
    vector<int> v{6, 4, 3, 5, 2, 1};
    cout << findKthSmallest(v, 3);
}