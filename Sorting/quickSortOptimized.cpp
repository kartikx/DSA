#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Using right index as pivot, can be optimized to use a random element.
int partition(vector<int>& v, int l, int r) {
    int i=l-1; int j=l;

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

void quickSortUtil(vector<int>& v, int l, int r) {
    while (l < r) {
        int pi = partition(v, l, r);

        if (pi-l < r-pi) {
            quickSortUtil(v, l, pi-1);
            l = pi+1;
        }

        else {
            quickSortUtil(v, pi+1, r);
            r = pi-1;
        }
    }
}

void quickSort(vector<int>& v) {
    return quickSortUtil(v, 0, v.size()-1);
}

int main() {
    vector<int> v{7, 5, 3, 1, 2};
    quickSort(v);

    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
}