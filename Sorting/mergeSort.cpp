#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void mergeRange(vector<int>& v, int l1, int r1, int l2, int r2) {
    assert(r1+1 == l2);

    vector<int> out(r2-l1+1, 0);

    int i=l1; int j=l2; int c=0;

    while (i <= r1 && j <= r2) {
        if (v[i] <= v[j]) {
            out[c++] = v[i++];
        }
        else {
            out[c++] = v[j++];
        }
    }

    while(i<=r1) {
        out[c++] = v[i++];
    }
    while(j <= r2) {
        out[c++] = v[j++];
    }

    c=0;
    for (int k=l1; k<=r2; k++, c++) {
        v[k] = out[c];
    }
}

void mergeSortUtil(vector<int>& v, int l, int r) {
    if (l >= r)
        return;
    
    int mid = (l+r)/2;
    mergeSortUtil(v, l, mid);
    mergeSortUtil(v, mid+1, r);

    mergeRange(v, l, mid, mid+1, r);

    return;
}

void mergeSort(vector<int>& v) {
    return mergeSortUtil(v, 0, v.size()-1);
}

int main() {
    vector<int> v{7, 4, 3, 2, 1, 5};

    mergeSort(v);
    for (auto x : v) {
        cout << x << " ";
    }
    cout << endl;
}