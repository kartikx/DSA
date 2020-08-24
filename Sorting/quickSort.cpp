#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/**
 * The basic idea is that we need to convert this vector, so that all elements
 * to the left of the Pivot (v[r] here) are less than it, and all elements to
 * the right are greater than it. We do this by constructing the left part,
 * which grows as we iterate from L to R.
 */
int partition(vector<int>& v, int l, int r) {
    // Stores the last element of the left container.
    int i = l-1;
    // Iterates over the entire container.
    int j=l;

    while (j < r) {
        // Add this element to container.
        if (v[j] <= v[r]) {
            i++;
            // This step is important if we had skipped some elements in between.
            swap(v[i], v[j]);
        }
        j++;
    }
    swap(v[i+1], v[r]);
    return i+1;
}

// ! Instead of doing this, I could have also just swapped the pivot index with the last element.
int partition(vector<int>& v, int l, int r, int pivot) {
    int i=l-1;
    int j=l;
    int pivotIndex = -1;

    while (j <= r) {
        if (v[j] <= pivot) {
            i++;
            if (v[j] == pivot) {
                pivotIndex = i;
            }
            swap(v[i], v[j]);
        }
        j++;
    }

    cout << pivotIndex << " " << i << endl;

    if (pivotIndex != -1) 
    {
        swap(v[i], v[pivotIndex]);
    }

    return i;
}

void quickSortUtil(vector<int>& v, int l, int r) {
    if (l >= r) {
        return;
    }

    // This sets the index pi at the correct position.
    int pi = partition(v, l, r);

    quickSortUtil(v, l, pi-1);
    quickSortUtil(v, pi+1, r);
}

void quickSort(vector<int>& v) {
    return quickSortUtil(v, 0, v.size()-1);
}

int main() {
    // vector<int> v{10, 8, 2, 7, 6, 4};
    // quickSort(v);

    vector<int> v{1, 5, 2, 6, 10, 5};
    partition(v, 0, v.size()-1);
    for (auto x : v) {
        cout << x << " ";
    }
    cout << endl;
}