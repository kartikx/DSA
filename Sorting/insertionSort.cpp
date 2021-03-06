#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void insertionSortOrg(vector<int>& v) {
    for (int j=1; j<v.size(); j++) {
        int key = v[j];
        int i = j;
        while (i > 0 && v[i] < v[i-1]) {
            swap(v[i], v[i-1]);
            i--;
        }
    }
}

void insertionSortOpt(vector<int>& v) {
    for (int i=1; i<v.size(); i++) {
        int key = v[i];
        int j=i-1;
        while (j >= 0 && v[j] > key) {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = key;
    }
}

void insertionSortRecUtil(vector<int>& v, int i, int val) {
    if (i == 0 || v[i-1] <= val)
    {
        v[i] = val;
        return;
    }

    v[i] = v[i-1];
    insertionSortRecUtil(v, i-1, val);
}

void insertionSortRec(vector<int>& v) {
    for (int i=1; i<v.size(); i++) {
        insertionSortRecUtil(v, i, v[i]);
    }
}

int main() {
    vector<int> v{2, 6, 1, 1, 8 ,1, 2, 1, 5 ,22, 61, 7, 24, 9};
    insertionSortRec(v);
    for (auto x : v) {
        cout << x << " " ;
    }
    cout << endl;
}