/**
 * Using Hoare's Partition Scheme for Partitioning
 * in Quick Sort.
 */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/**
 * In this partition scheme, the pivot's final location
 * is NOT the index that is returned. That is you don't end up
 * fixing the position of the pivot.
 */
int partition(vector<int>& v, int l, int r) {
    int i=l-1; int j=r+1;
    int pivot = v[l];
    while (true) {
        do {
            i++;
        } while(v[i] < pivot);

        do {
            j--;
        } while(v[j] > pivot);

        if (i >= j) {
            return j;
        }

        swap(v[i], v[j]);
    }
}

void quickSortUtil(vector<int>& v, int l, int r) {
    if (l >= r)
        return;
    
    int pi = partition(v, l, r);
    quickSortUtil(v, l, pi);
    quickSortUtil(v, pi+1, r);
}

void quickSort(vector<int>& v) {
    return quickSortUtil(v, 0, v.size()-1);
}

int main() {
    vector<int> v1{2, 1, 3, 7, 2, 6};
    quickSort(v1);

    // Gives equal sized partition for all same values as well.
    vector<int> v2{1, 1, 1, 1, 1, 1};
    int index = partition(v2, 0, v2.size()-1);

    for (int i=0; i<=index; i++) {
        cout << v2[i] << " ";
    }
    cout << endl;

    for (int i=index+1; i<v2.size(); i++) {
        cout << v2[i] << " ";
    }
    cout << endl;
}